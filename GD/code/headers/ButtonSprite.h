#include "includes.h"

class ButtonSprite : public cocos2d::CCSprite
{
	int m_eStringState;
	float m_fAbsoluteWidth;
	float m_fCustomWidth;
	float m_fScale;
	float m_fContentSizeHeight;
	bool m_bAbsolute;
	cocos2d::CCLabelBMFont* m_pLabel;
	cocos2d::CCSprite* m_pCustomTexture;
	cocos2d::CCSprite* m_pBtnTextureName;
	cocos2d::extension::CCScale9Sprite* m_pBackgroundImage;
	cocos2d::CCPoint m_obTextPosition;
	cocos2d::CCPoint m_obSpriteOffset;
	std::string m_sString;

	ButtonSprite();
	static ButtonSprite* create(cocos2d::CCSprite* _customTexture, int _width, int _customWidth, float _unk, float _scale, bool _absolute, const char* _btnName, bool _unk2);
	static ButtonSprite* create(const char* _string, int _absoluteWidth, int _customWidth, float _scale, bool _absolute, const char* _font, const char* _background, float _height);
	bool init(cocos2d::CCSprite* _customTexture, int _width, int _customWidth, float _unk, float _scale, bool _absolute, const char* _btnName, bool _unk2);
	bool init(const char* _string, int _absoluteWidth, int _customWidth, float _scale, bool _absolute, const char* _font, const char* _background, float _height);
	void updateSpriteOffset(cocos2d::CCPoint _offset);
	void updateSpriteBGSize();
	void setString(const char* _string);
	void setColor(cocos2d::ccColor3B _col);
};
