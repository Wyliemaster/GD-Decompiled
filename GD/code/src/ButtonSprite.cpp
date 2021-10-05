#include "../headers/includes.h"


ButtonSprite::ButtonSprite()
{

}

ButtonSprite* ButtonSprite::create(cocos2d::CCSprite* _customTexture, int _width, int _customWidth, float _unk, float _scale, bool _absolute, const char* _btnName, bool _unk2)
{
	auto pRet = new ButtonSprite;

	if (pRet && pRet->init(_customTexture, _width, _customWidth, _unk, _scale, _absolute, _btnName, _unk2))
	{
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return nullptr;
}

ButtonSprite* ButtonSprite::create(const char* _string, int _absoluteWidth, int _customWidth, float _scale, bool _absolute, const char* _font, const char* _background, float _height)
{
	auto pRet = new ButtonSprite;

	if (pRet && pRet->init(_string, _absoluteWidth, _customWidth, _scale, _absolute, _font, _background, _height))
	{
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return nullptr;
}

void ButtonSprite::updateSpriteOffset(cocos2d::CCPoint _offset)
{
	m_obSpriteOffset = _offset;
	updateSpriteBGSize();
}
