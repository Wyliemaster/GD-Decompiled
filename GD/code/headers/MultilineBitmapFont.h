#include "includes.h"

class MultilineBitmapFont : cocos2d::CCSprite
{
	float m_fFontWidth[300];
	cocos2d::CCArray* m_pColouredTextArray; // ColoredSection*
	cocos2d::CCArray* m_pInstantTextArray;  // InstantSection*
	cocos2d::CCArray* m_pDelayedTextArray;  // DelayedSection*
	cocos2d::CCArray* m_pLetterArray;	    // cocos2d::CCSprite*
	float m_fHalfScaledFontWidth;
	bool m_bUnkScaleBool;
	int unk;
	cocos2d::CCSize m_obTextureSize;
	cocos2d::CCPoint m_obPosition;
	float m_fContentSizeScaleMod;
	bool m_bTagsDisabled;

	std::string readColorInfo(std::string);
	void moveSpecialDescriptors(int, int);
	void setOpacity(unsigned __int8);
	virtual bool initWithFont(const char* fontName, int* str, float scale, float width, cocos2d::CCPoint anchorPoint, bool bColourEnabled) override;
	static MultilineBitmapFont* create(const char* fontName, int* str, float scale, float width, cocos2d::CCPoint anchorPoint, bool bColourEnabled);
	std::string stringWithMaxWidth(std::string, float, float);
};