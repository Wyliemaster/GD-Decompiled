#include "../headers/includes.h"

DialogObject* DialogObject::create(std::string _title, std::string _text, int _type, float _width, bool _canSkip, cocos2d::ccColor3B _colour)
{
	auto pRet = new DialogObject;

	if (pRet && pRet->init(_title, _text, _type, _width, _canSkip, _colour))
	{
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return nullptr;
}

bool DialogObject::init(std::string _title, std::string _text, int _type, float _width, bool _canSkip, cocos2d::ccColor3B _colour)
{
	m_sTitle = _title;
	m_sText = _text;
	m_nDialogType = _type;
	m_fTextWidth = _width;
	m_bCanSkip = _canSkip;
	m_pColour = _colour;
	return true;
}



