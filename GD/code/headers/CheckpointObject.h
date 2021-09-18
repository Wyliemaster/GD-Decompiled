#include "includes.h"

class CheckpointObject : public cocos2d::CCNode
{
public:
	GameObject* m_pObject;
	PlayerCheckpoint* m_pPlayer1Checkpoint;
	PlayerCheckpoint* m_pPlayer2Checkpoint;
	bool m_bTwoPlayer;
	bool m_bFlipped;
	cocos2d::CCPoint m_obCameraPos;
	int m_eTransitionType;
	GameObject* m_pPortal;
	double m_dTime;
	std::string m_sCurrentStateString;
	std::string m_sObjectStateString;
};


