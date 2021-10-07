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
		if(m_pBtnTextureName)
			size = m_pBtnTextureName->getContentSize();
	}
	setContentSize(size);


	// will finish later, going to bed

//  v17 = this->m_pCustomTexture;
//  v18 = *(void(__fastcall**)(cocos2d::CCSprite*, float*))(v17->vtable_ptr + 92);
//  v19 = *(float*)(*(int(__fastcall**)(ButtonSprite*))(this->vtable_ptr + 156))(this) * 0.5;
//  cocos2d::CCPoint::CCPoint(v40, 0.0, 2.0);
//  v20 = (float)(v19 + v40[0]) + this->m_obSpriteOffset.x;
//  v21 = *(float*)((*(int(__fastcall**)(ButtonSprite*))(this->vtable_ptr + 156))(this) + 4) * 0.5;
//  cocos2d::CCPoint::CCPoint(v41, 0.0, 2.0);
//  cocos2d::CCPoint::CCPoint(v42, v20, (float)(v21 + v41[1]) + this->m_obSpriteOffset.y);
//  v18(v17, v42);
//  v22 = this->m_pBackgroundImage;
//  if (v22)
//  {
//	  v23 = *(void(__fastcall**)(cocos2d::extension::CCScale9Sprite*, float*))(*(_DWORD*)v22 + 92);
//	  v24 = *(float*)(*(int(__fastcall**)(ButtonSprite*))(this->vtable_ptr + 156))(this) * 0.5;
//	  v25 = (*(int(__fastcall**)(ButtonSprite*))(this->vtable_ptr + 156))(this);
//	  cocos2d::CCPoint::CCPoint(v43, v24, *(float*)(v25 + 4) * 0.5);
//	  v23(v22, v43);
//  }
//  else
//  {
//	  v26 = this->m_pBtnTextureName;
//	  if (v26)
//	  {
//		  v27 = *(void(__fastcall**)(cocos2d::CCSprite*, float*))(v26->vtable_ptr + 92);
//		  v28 = *(float*)(*(int(__fastcall**)(ButtonSprite*))(this->vtable_ptr + 156))(this) * 0.5;
//		  v29 = (*(int(__fastcall**)(ButtonSprite*))(this->vtable_ptr + 156))(this);
//		  cocos2d::CCPoint::CCPoint(v44, v28, *(float*)(v29 + 4) * 0.5);
//		  v27(v26, v44);
//	  }
//  }
//  result = (void*)(*(int(__fastcall**)(ButtonSprite*))(this->vtable_ptr + 248))(this);
//  if (result)
//  {
//	  result = (void*)(*(int(__fastcall**)(ButtonSprite*))(this->vtable_ptr + 248))(this);
//	  if (result)
//	  {
//		  result = _dynamic_cast(
//			  result,
//			  (const struct __class_type_info*)&`typeinfo for'cocos2d::CCNode,
//			  (const struct __class_type_info*)&`typeinfo for'CCMenuItemSpriteExtra,
//			  0);
//		  if (result)
//		  {
//			  v31 = (*(int(__fastcall**)(ButtonSprite*))(this->vtable_ptr + 248))(this);
//			  v32 = *(void(__fastcall**)(int, int))(*(_DWORD*)v31 + 152);
//			  v33 = (*(int(__fastcall**)(ButtonSprite*))(this->vtable_ptr + 156))(this);
//			  v32(v31, v33);
//			  v34 = *(int(__fastcall**)(ButtonSprite*, float*))(this->vtable_ptr + 92);
//			  v35 = *(float*)(*(int(__fastcall**)(ButtonSprite*))(this->vtable_ptr + 156))(this);
//			  v36 = (*(int(__fastcall**)(ButtonSprite*))(this->vtable_ptr + 156))(this);
//			  cocos2d::CCPoint::CCPoint(v45, v35 * 0.5, *(float*)(v36 + 4) * 0.5);
//			  result = (void*)v34(this, v45);
//		  }
//	  }
//  }
//  return result;
}