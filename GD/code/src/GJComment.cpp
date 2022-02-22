#include "../headers/includes.h"

GJComment::GJComment()
{
	m_nCommentID = 0;
	m_nAuthorPlayerID = 0;
	m_nLikes = 0;
	m_nLevelID = 0;
	m_sComment = "";
	m_sUsername = "";
	m_bIsSpam = false;
	m_nAuthorAccountID = 0;
	m_sCommentAge = "";
	m_bCommentDeleted = false;
	m_nPercentage = 0;
	m_nModBadge = 0;
	m_cColor = { 0, 0, 0 };
	m_bHasLevelID = false;
	m_pUserScore = nullptr;
}

GJComment* GJComment::create()
{
	auto pRet = new GJComment;

	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return nullptr;
}

bool init()
{
	m_sComment = "";
	m_sUsername = "";
	return true;
}

int GJComment::getAccountID()
{
	return m_nAuthorAccountID;
}

int GJComment::getUserID() 
{
	return m_nAuthorPlayerID;
}

int GJComment::getPercentage()
{
	return m_nPercentage;
}

int GJComment::getBadge()
{
	return m_nModBadge;
}

cocos2d::ccColor3B GJComment::getColour()
{
	return m_cColor;
}

std::string GJComment::getUsername()
{
	return m_sUsername;
}

std::string GJComment::getComment()
{
	return m_sComment;
}

GJComment* GJComment::create(cocos2d::CCDictionary* dict)
{
	GJComment* comment = create();
	comment->m_sComment = dict->valueForKey("2")->m_sString;
	comment->m_nAuthorPlayerID = dict->valueForKey("3")->intValue();
	comment->m_nLikes = dict->valueForKey("4")->intValue();
	comment->m_nCommentID = dict->valueForKey("6")->intValue();
	comment->m_bIsSpam = dict->valueForKey("7")->boolValue();
	comment->m_nAuthorAccountID = dict->valueForKey("8")->intValue();
	comment->m_sCommentAge = dict->valueForKey("9")->m_sString;
	comment->m_nPercentage = dict->valueForKey("10")->intValue();
	comment->m_nModBadge = dict->valueForKey("11")->intValue();
	comment->m_nLevelID = dict->valueForKey("1")->intValue();

	if (comment->getBadge() > 0)
	{
		cocos2d::CCArray* colArr = RobTop::splitToCCArray(dict->valueForKey("12")->m_sString, ",");

		if (colArr.count() > 2)
		{
			comment->m_cColor.r = colArr->stringAtIndex(0)->intValue();
			comment->m_cColor.g = colArr->stringAtIndex(1)->intValue();
			comment->m_cColor.b = colArr->stringAtIndex(2)->intValue();
		}
	}

	return comment;
}