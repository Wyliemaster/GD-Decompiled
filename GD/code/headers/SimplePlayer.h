#include "includes.h"

class SimplePlayer : public cocos2d::CCSprite
{
public:
	cocos2d::CCSprite* m_pPlayerSpriteLayer1;
	cocos2d::CCSprite* m_pPlayerSpriteLayer2;
	cocos2d::CCSprite* m_pPlayerSpriteBirdDome;
	cocos2d::CCSprite* m_pPlayerSpriteGlow;
	cocos2d::CCSprite* m_pPlayerSpriteDetail;
	GJRobotSprite* m_pRobotSprite;
	GJSpiderSprite* m_pSpiderSprite;
	DWORD m_unk;
	bool m_bGlow;



	cocos2d::CCPoint g_obUnknownGlobal;
	cocos2d::CCRect g_UnkRect;


	SimplePlayer();
	static SimplePlayer* create(int _iconID);
	bool init(int _iconID)
};
