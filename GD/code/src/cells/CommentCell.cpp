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

	if (m_fCellHeight == 36.0f)
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
	else
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