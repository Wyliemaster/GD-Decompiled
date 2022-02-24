#include "../includes.h"

class BoomScrollLayerDelegate;
class DynamicScrollDelegate;

class LevelSelectLayer : public cocos2d::CCLayer, public BoomScrollLayerDelegate, public DynamicScrollDelegate
{
public:
	float m_fWindowWidth;
	cocos2d::CCSprite* m_pBackground;
	GJGroundLayer* m_pGround;
	BoomScrollLayer* m_pBoomScrollLayer;
	BYTE PAD[4];
	int m_nLevel;
	bool m_bSecretMenuCoin;

public:
	cocos2d::ccColor3B colorForPage(int);
	bool init(int);
};
