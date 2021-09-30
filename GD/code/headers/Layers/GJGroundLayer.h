#include "includes.h"

class GJGroundLayer : public cocos2d::CCLayer
{
public:
	cocos2d::CCSprite* m_pGround1Sprite;
	cocos2d::CCSprite* m_pGround2Sprite;
	float m_fGroundWidth;
	cocos2d::CCSprite* m_pLineSprite;
	bool m_bShowGround;
	bool m_bLineBlend;
	float m_fGroundHeight;
	int m_nLineID;
};
