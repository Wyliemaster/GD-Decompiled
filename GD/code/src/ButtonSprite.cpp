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

bool ButtonSprite::init(const char* _string, int _absoluteWidth, int _customWidth, float _scale, bool _absolute, const char* _font, const char* _background, float _height)
{
	if (!cocos2d::CCSprite::init()) return false;
	m_eButtonType = kButtonTypeString;
	m_fScale = _scale;
	m_fAbsoluteWidth = _absoluteWidth;
	m_bAbsolute = _absolute;
	m_fHeight = _height;
	m_fCustomWidth = _customWidth;

	m_obTextPosition = { 0.0f, 2.0f };
	if (_font != "bigFont.fnt") m_obTextPosition = { -1.0f, 2.0f };

	m_pLabel = cocos2d::CCLabelBMFont::create("", _font);
	this->addChild(m_pLabel, 1);

	m_pBackgroundImage = cocos2d::extension::CCScale9Sprite::create(_background);
	m_pBackgroundImage->setContentSize({ 16.0f, 16.0f });
	this->addChild(m_pBackgroundImage, 0);

	this->setString(_string);
}

void ButtonSprite::updateSpriteBGSize()
{
	float width;
	float height;
	cocos2d::CCSize size;
	if (m_bAbsolute) width = m_fAbsoluteWidth;
	else
	{
		if (m_fCustomWidth < (m_pCustomTexture->getContentSize().width * m_pCustomTexture->getScaleX()))
			width = m_pCustomTexture->getContentSize().width * m_pCustomTexture->getScale() + 8.0f;
		else
			width = m_fCustomWidth;
	}

	if (m_pBackgroundImage)
	{
		cocos2d::CCRect rect = { 0.0f, 0.0f, 40.0f, 40.0f };
		if (rect.height >= m_pCustomTexture->getContentSize().height)
			height = rect;
		else
			height = m_pCustomTexture->getContentSize().height * m_pCustomTexture->getScale() + 8.0f;

		m_pBackgroundImage->setContentSize({ width + 8.0f, height });

		size = m_pBackgroundImage->getContentSize();
	}
	else
	{
		if (m_pBtnTextureName)
			size = m_pBtnTextureName->getContentSize();
	}
	setContentSize(size);

	cocos2d::CCSize HalfSize = getContentSize() * 0.5;
	cocos2d::CCPoint TexturePos = { HalfSize.width + m_obSpriteOffset.x, HalfSize.height + 2 + m_obSpriteOffset.y };

	m_pCustomTexture->setPosition(TexturePos);

	// did i mess up somewhere?
	if (m_pBackgroundImage)
	{
		m_pBackgroundImage->setPosition(HalfSize);
	}
	else
	{
		if (m_pBtnTextureName)
		{
			m_pBtnTextureName->setPosition(HalfSize);
		}
	}

	cocos2d::CCNode* Parent = getParent();

	if (Parent)
	{
		Parent = Parent->getParent();
		if (Parent)
		{
			if (dynamic_cast<CCMenuItemSpriteExtra*>(Parent))
			{
				Parent = getParent();
				Parent->setContentSize(getContentSize());

				setPosition(HalfSize);

			}
		}
	}

}


