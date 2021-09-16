#include "includes.h"

class AchievementManager: public cocos2d::CCNode
{
	cocos2d::CCDictionary* m_pAllAchievements;
	cocos2d::CCDictionary* m_pAllAchievementsSorted;
	cocos2d::CCDictionary* m_pAchievementRewardDict;
	void* dwordC;
	cocos2d::CCDictionary* m_pReportedAchievements;
	bool m_bNotifiedAchievement;
};
