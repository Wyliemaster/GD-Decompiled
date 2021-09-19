#include "includes.h"

class GhostTrailEffect;
class PlayerCheckpoint : public cocos2d::CCNode
{
public:
	cocos2d::CCPoint m_obPosition;
	float m_fYAccel;
	bool m_bGravity;
	bool m_bFlyMode;
	bool m_bRollMode;
	bool m_bBirdMode;
	bool m_bDartMode;
	bool m_bRobotMode;
	bool m_bSpiderMode;
	bool m_bOnGround;
	GhostTrailEffect* m_pGhostTrail;
	bool m_bMiniMode;
	float m_fTimeMod;
	bool m_bVisibility;
};


