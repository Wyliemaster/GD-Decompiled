#include "includes.h"

class GhostTrailEffect : public cocos2d::CCNode
{
	float m_fInterval;
	float m_fDuration;
	float m_fYScaleModMaybe;
	bool m_bVisible;
	float m_fScale;
	cocos2d::ccBlendFunc m_eBlendFunc;
	cocos2d::CCSprite* m_pIcon;
	PlayerObject* m_pPlayer;
	cocos2d::CCSpriteBatchNode* m_pBatchNodeAddPlayer;
	float m_fOpacity;
	void* m_pUnk; // pointer to something, passes GhostTrailEffect as Arg
	cocos2d::ccColor3B m_cColour;
	cocos2d::CCPoint m_obPosition;
	bool m_bUnk;
};
