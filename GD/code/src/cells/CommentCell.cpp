#include "../../headers/includes.h"

CommentCell::CommentCell(const char* a2, float a3, float a4)
{
	init();
}

bool CommentCell::init()
{
	m_pLikesIcon = nullptr;
	m_pLikesLabel = nullptr;
	m_pComment = nullptr;
	return true;
}

void CommentCell::draw()
{
	cocos2d::CCSize tableSize = { m_fTableHeight , m_fCellHeight };
	cocos2d::ccDrawColor4B({ 0, 0, 0, 0x4B });
	glLineWidth(2.0f);
	cocos2d::ccDrawLine({ 1.0f, tableSize.width }, { tableSize.width - 1.0f, tableSize.height });
	cocos2d::ccDrawLine({ 1.0f, 0.0f }, { tableSize.width - 1.0f, 0.0f });
}

void CommentCell::onViewProfile(cocos2d::CCObject* pSender)
{
	if (m_pComment)
		ProfilePage::create(m_pComment->m_nAuthorAccountID, false)->show();
}

void CommentCell::onConfirmDelete(cocos2d::CCObject* pSender)
{
	if (m_pComment)
	{
		FLAlertLayer* popup = FLAlertLayer::create(this, "Delete Comment", "Are you sure you want to <cr>delete</c> this comment?", "NO", "YES", 300.0f);
		popup->setTag(0);
		popup->show();
	}
}

void CommentCell::onGoToLevel(cocos2d::CCObject* pSender)
{
	if (m_pComment)
	{
		if (m_pComment->m_nLevelID > 0)
		{
			GJSearchObject* obj = GJSearchObject::create(0, cocos2d::CCString::createWithFormat("%i", m_pComment->m_nLevelID)->m_sString);
			cocos2d::CCScene* scene = LevelBrowserLayer::create(obj);
			cocos2d::CCDirector::sharedDirector()->pushScene(cocos2d::CCTransitionFade::create(0.5f, scene));
		}
	}
}

void CommentCell::onUnhide(cocos2d::CCObject* pSender)
{
	m_pComment->m_bIsSpam = false; // Technically can crash however, the option doesn't appear unless the comment is flagged as spam
	loadFromComment(m_pComment);
}

void CommentCell::onUndelete(cocos2d::CCObject* pSender)
{
	if (m_pComment)
	{
		m_pComment->m_bCommentDeleted = false;
		loadFromComment(m_pComment);
	}
}

void CommentCell::FLAlert_Clicked(FLalertLayer* popup, bool btn2)
{
	if (!popup->getTag() && btn2)
	{
		onDelete();
	}
}

void CommentCell::onDelete()
{
	if (m_pComment)
	{
		m_bAccountComment
			? GameLevelManager::sharedState()->deleteAccountComment(m_pComment->m_nCommentID)
			: GameLevelManager::sharedState()->deleteLevelComment(m_pComment->m_nLevelID, m_pComment->m_nCommentID);

		m_pComment->m_bCommentDeleted = true;
		loadFromComment(m_pComment);
	}
}

void CommentCell::incrementLikes()
{
	++m_pComment->m_nLikes;
	updateLabelValues();
}

void CommentCell::incrementDislikes()
{
	--m_pComment->m_nLikes;
	updateLabelValues();
}

void CommentCell::updateLabelValues()
{
	m_pLikesLabel->setString(cocos2d::CCString::createWithFormat("%i", m_pComment->m_nLikes)->m_sString);
	cocos2d::CCSprite displayFrame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(m_pComment->m_nLikes < 0 ? "GJ_dislikesIcon_001.png" : "GJ_likesIcon_001.png");
	m_pLikesIcon->setDisplayFrame(displayFrame);
}

void CommentCell::likedItem(LikeItemType likeItemType, int commentID, bool like)
{
	if (m_pComment && commentID == m_pComment->m_nCommentID)
	{
		like ? incrementLikes() : incrementDislikes();
	}
}

void CommentCell::onLike(cocos2d::CCObject* pSender)
{
	LikeItemType type;
	int special;
	if (m_bAccountComment)
	{
		special = m_pComment->m_nAuthorAccountID; // no check D: would crash if comment wasn't defined
		type = kLikeItemTypeAccComment;
	}
	else
	{
		special = m_pComment->m_nLevelID;
		type = kLikeItemTypeComment;
	}

	if (m_pComment)
	{
		bool liked = GameLevelManager::sharedState()->hasLikedItemFullCheck(type, m_pComment->m_nCommentID ,special);
		if (!liked)
		{
			GameManager* GM = GameManager::sharedState();
			if (m_pComment->m_nAuthorPlayerID != GM->getPlayerID())
			{
				GJAccountManager* AM = GJAccountManager::sharedState();
				if (!m_pComment->m_nAuthorAccountID || m_pComment->m_nAuthorAccountID != AM->getPlayerAccountID())
				{
					LikeItemLayer* layer = LikeItemLayer::create(type, m_pComment->m_nCommentID, special);
					layer->LikeItemDelegate = dynamic_cast<LikeItemDelegate*>(this);
					layer->show()
				}
			}
		}
	}
}

void CommentCell::updateBGColor(int cellIdx)
{
	cocos2d::ccColor3B col;

	if (m_fCellHeight == 36.0f) // small rows
	{
		if (cellIdx & 1)
		{
			col = { 0x90, 0x4F, 0x27 };
		}
		else
		{
			col = { 0x9C, 0x55, 0x2A };
		}
	}
	else // big rows
	{
		if (cellIdx & 1)
		{
			col = { 0xC2, 0x72, 0x3E };
		}
		else
		{
			col = { 0xA1 , 0x58, 0x2C };
		}
	}
	m_pColourLayer->setColor(col);
}

void CommentCell::loadFromComment(GJComment* comment)
{
	m_pColourLayer->setOpacity(255);
	comment->retain();
	if (m_pComment)
		m_pComment->release();

	m_pComment = comment;

	m_bAccountComment = comment->m_nLevelID ? false : comment->m_nAuthorAccountID > 0;

	m_pLayer->removeAllChildrenWithCleanup(true);

	GameLevelManager* GLM = GameLevelManager::sharedState();

	if (!comment->m_bCommentDeleted)
	{
		bool isSmallRow = m_fCellHeight == 36.0f;
		cocos2d::CCMenu* commentMenu = cocos2d::CCMenu::create();
		m_pLayer->addChild(commentMenu, 2);

		std::string username = GLM->userNameForUserID(comment->m_nAuthorPlayerID);

		if (m_bAccountComment)
			username = GLM->userNameForUserID(GLM->UserIDForAccountID(comment->m_nAuthorAccountID));
		
		m_pComment->m_sUsername = username;

		if (!m_bAccountComment && !m_pComment->m_nAuthorAccountID)
			m_pComment->m_nAuthorAccountID = GLM->accountIDForUserID(m_pComment->m_nAuthorPlayerID);

		cocos2d::CCLabelBMFont* nameLabel = cocos2d::CCLabelBMFont::create(m_pComment->m_sUsername, "goldFont.fnt");

		float width, defaultScale;

		if (isSmallRow)
		{
			width = 150.0f;
			defaultScale = 0.5f;
		}
		else
		{
			defaultScale = 0.7f;
			width = m_pComment->m_nLevelID ? 100.0f : 150.0f;
		}

		nameLabel->limitLabelWidth(width, defaultScale, 0.0f);

		float unk1, unk2, width, widthPad, heightPad;

		if (m_bAccountComment)
		{
			unk1 = 0.0f;
			goto label_1;
		}
		if (!m_pComment->m_pUserScore)
		{
			unk1 = 0.0f;
		label_2:
			if (m_pComment->m_nModBadge < 1)
				unk2 = 0.0f;
			else
			{
				widthPad = isSmallRow ? 8.0f : 12.0f;
				heightPad = isSmallRow ? 11.5f : 19.5f;

				xPos = ((unk1 + 10.0f) + (nameLabel->getContentSize() * nameLabel->getScale())) + widthPad;
				cocos2d::CCPoint namePos = { xPos, m_fCellHeight - heightPad };

				cocos2d::CCSprite badgeSprite = cocos2d::CCSprite::createWithSpriteFrameName(m_pComment->m_nModBadge == 2 ? "modBadge_02_001.png" : "modBadge_01_001.png");

				float badgeScale = isSmallRow ? 0.55f : 0.75f;
				badgeSprite->setScale(badgeScale);
				m_pLayer->addChild(badgeSprite, 10);

				unk2 = isSmallRow ? 15.0f : 22.0f;
			}
			if (m_pComment->m_nPercentage > 0)
			{
				std::string percentage = cocos2d::CCString::createWithFormat("%i%%", m_pComment->m_nPercentage)->m_sString;
				cocos2d::CCLabelBMFont* percentageLabel = cocos2d::CCLabelBMFont::create(percentage, "chatFont.fnt");
				m_pLayer->addChild(percentageLabel);
				percentageLabel->setAnchorPoint({ 0.0f, 0.5f });

				float percentScale = isSmallRow ? 0.48f : 0.6f;
				percentageLabel->setScale(percentScale);
				percentageLabel->setColor({ 0, 0, 0 });
				percentageLabel->setOpacity(150.0f);

				xPos = (((unk1 + 10.0f) + unk2) + (nameLabel->getContentSize() * nameLabel->getScale())) + 4.0f; // yes it uses the name rather than the percent
				cocos2d::CCPoint percentPos = { xPos, m_fCellHeight - heightPad };
				percentageLabel->setPosition(percentPos);
			}
		label_1:
			heightPad = isSmallRow ? 10.0f : 18.0f;

			if (!m_pComment->m_nAuthorAccountID || m_bAccountComment || comment->m_bHasLevelID) // unregistered account
			{
				m_pLayer->addChild(nameLabel);
				nameLabel->setAnchorPoint({ 0.0f, 0.5f });
				nameLabel->setPosition({ xPos, m_fCellHeight - heightPad });

				if (m_pComment->m_nAuthorAccountID != 71 && !m_bAccountComment && m_pComment->m_nAuthorAccountID <= 0) // change colour to green if not robtop
				{
					nameLabel->setColor({ 0x5A, 0xFF, 0xFF });
				}

			}
			else
			{
				cocos2d::CCMenuItemSpriteExtra* cName = CCMenuItemSpriteExtra::create(nameLabel, this, onViewProfile);
				commentMenu->addChild(cName);
				cocos2d::CCPoint pos = commentMenu->convertToNodeSpace(m_pLayer->convertToWorldSpace({ (unk1 + 10.0f) + ((nameLabel->getContentSize() / 2) * nameLabel->getScale()), m_fCellHeight - heightPad }));
				cName->setPosition(pos);
			}

			float a = 10.0f, b = 12.0f;

			if (isSmallRow)
				a = b = 8.0f;
			

			if (!isSmallRow)
			{
				cocos2d::extension::CCScale9Sprite* bgSprite = cocos2d::extension::CCScale9Sprite::create("square02b_001.png", { 0.0f, 0.0f, 80.0f, 80.0f });
				bgSprite->setContentSize({ m_fTableHeight - a, m_fCellHeight - b });
				m_pLayer->addChild(bgSprite, -1);
				bgSprite->setPosition({ m_fTableHeight / 2, m_fCellHeight / 2 });
				bgSprite->setColor({ 0x82, 0x40, 0x21 });
				bgSprite->setOpacity({ 100.0f });
			}

			while (true)
			{
				std::size_t NSBP = m_pComment->m_sComment.find('\xA0');
				if (NSBP == -1)
					break;
				m_pComment->m_sComment.replace(NSBP, 1, 1, '\x00'); // Robert removing all instances of 0xA0 (No-Break spaces) from comments
			}

			std::string comment = m_pComment->m_sComment;

			float scaleMod = isSmallRow ? 0.6f : 0.7f, scaleFactor = 1.0f, textSize, unkScale;
			int commentCapacity = m_bAccountComment ? 140 : 100;
			int commentLen = std::min(m_pComment->m_sComment.size(), commentCapacity);

			bool lessThanHalf = commentLen <= (commentCapacity / 2);

			if (commentLen > (commentCapacity / 2))
			{
				textSize = static_cast<float>(commentCapacity - commentLen);
				unkScale = textSize / commentCapacity;
			}

			if (lessThanHalf)
				scaleMod = 1.0f;
			else
			{
				scaleFactor = 1.0f - scaleMod;
				scaleMod = scaleMod + (unkScale * scaleFactor);
			}

			if (m_pComment->m_bIsSpam)
			{
				comment = "Comment flagged as spam";
				if(!isSmallRow)
					comment = "<cy>Comment flagged as spam</c>"
			}
			if (!isSmallRow)
			{
				TextArea* commentText = TextArea::create(comment, "chatFont.fnt", 1.0f, (m_fTableHeight - a - 45.0f) / scaleMod, { 0.0f, 1.0f }, !m_pComment->m_bIsSpam);
				m_pLayer->addChild(commentText);
				commentText->setAnchorPoint({ 0.0f, 0.5f });
				commentText->setPosition({ 10, m_fCellHeight / 2 });
				commentText->setScale(scaleMod);

				cocos2d::ccColor3B commentCol;

				if (m_pComment->m_nAuthorAccountID == 71) // Roberts blue comment
				{
					commentCol = { 0x32,0xFF,0xFF };
				}
				else
				{
					GJGameLevel* level = GLM->getSavedLevel(m_pComment->m_nLevelID);

					if (level || (level = GLM->getSavedDailyLevelFromLevelID(m_pComment->m_nLevelID)) != 0 && level->getUserID() == m_pComment->getUserID())
					{
						commentCol = { 0xFF, 0xFF, 0x4B };
					}
					else
					{
						if (m_pComment->m_nModBadge > 0 && !m_bAccountComment)
						{
							commentCol = m_pComment->m_cColor;
						}
					}
				}
				commentText->colorAllCharactersTo(commentCol);
			}

			if (m_pComment->m_bHasLevelID)
			{
				std::string levelID = cocos2d::CCString::createWithFormat("%i", m_pComment->m_nLevelID)->m_sString;
				ButtonSprite* idBtn = ButtonSprite::create(LevelID, 120, 0, 1.0f, 1, "bigFont.fnt", "GJ_button_01.png", 30.0f);
				idBtn->setScale(isSmallRow ? 0.4f : 0.6f);
				CCMenuItemSpriteExtra* idBtnClickable = CCMenuItemSpriteExtra::create(idBtn, this onGoToLevel);
				idBtnClickable->setSizeMulti(1.2f);
				commentMenu->addChild(idBtnClickable);

				cocos2d::CCPoint idPos = { m_fTableHeight - (isSmallRow ? 95.0f : 130.0f), m_fCellHeight - (isSmallRow ? 11.5f : 19.5f) };
				idBtnClickable->setPosition(commentMenu->convertToNodeSpace(m_pLayer->convertToWorldSpace(idPos)));
			}
			// 665/995





		}
		

	}
}