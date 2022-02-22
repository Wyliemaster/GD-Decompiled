#include "includes.h"

class MultilineBitmapFont : cocos2d::CCSprite
{
	float m_fFontWidth[300];
	cocos2d::CCArray* m_pColouredTextArray;
	cocos2d::CCArray* m_pInstantTextArray;
	cocos2d::CCArray* m_pDelayedTextArray;
	cocos2d::CCArray* m_pUnkArr4;
	float m_funk3;
	bool m_bUnk;
	DWORD dword6AC;
	DWORD unk1;
	DWORD unk2;
	cocos2d::CCPoint m_obUnkPos;
	float m_fUnk1;
	bool m_bColourEnabled;

	std::string readColorInfo(std::string);
};