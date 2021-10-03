#include "includes.h"

class AchievementNotifier : public cocos2d::CCNode
{
	cocos2d::CCScene* m_pScene;
	cocos2d::CCArray* m_pAchievementArray;
	AchievementBar* m_pAchievementBar;
};
