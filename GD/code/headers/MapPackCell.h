#include "includes.h"

class MapPackCell : public TableViewCell
{
	GJMapPack* m_pPack;
	CCMenuItemSpriteExtra* m_pBtn;
	CCMenuItemSpriteExtra* m_pClaimBtn;
	cocos2d::CCArray* m_pLabels;
	cocos2d::CCArray* m_pSprites;
};
