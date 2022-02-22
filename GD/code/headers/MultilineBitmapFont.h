#include "includes.h"

class MultilineBitmapFont : cocos2d::CCSprite
{
	float m_fFontWidth[300];
	cocos2d::CCArray* m_pColouredTextArray; // ColoredSection*
	cocos2d::CCArray* m_pInstantTextArray;  // InstantSection*
	cocos2d::CCArray* m_pDelayedTextArray;  // DelayedSection
	cocos2d::CCArray* m_pLetterArray;	    // cocos2d::CCSprite*
	float m_funk3;
	bool m_bUnk;
	DWORD dword6AC;
	DWORD unk1;
	DWORD unk2;
	cocos2d::CCPoint m_obUnkPos;
	float m_fUnk1;
	bool m_bColourEnabled;

	std::string readColorInfo(std::string);
	void moveSpecialDescriptors(int, int);
	void setOpacity(unsigned __int8);
};