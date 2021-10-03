#include "../includes.h"

class UILayer : public cocos2d::CCLayerColor, public cocos2d::CCKeyboardDelegate
{
	DWORD field_1; // no Xrefs :(
	cocos2d::CCMenu* m_pMenu;
	CCMenuItemSpriteExtra* m_pPauseBtn;
	bool m_bUnk; // these bools were involved with KeyDown stuff
	bool m_bUnk2;
	bool m_bUnk3;
	bool m_bUnk4;
	bool m_bCheckpoint;
	int m_nPlayer1TouchIDMaybe;
	int m_nPlayer2TouchIDMaybe;
	float m_fClkTimer;
};




