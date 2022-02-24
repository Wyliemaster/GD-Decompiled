#include "includes.h"

class LevelPage : public cocos2d::CCLayer, DialogDelegate
{
	bool m_bUnlockedMaybe;
	GJGameLevel* m_pLevel;
	cocos2d::CCMenu* m_pMenu;
	cocos2d::extension::CCScale9Sprite* m_pBackgroundSquare;
	cocos2d::CCLabelBMFont* m_pLabel;
	cocos2d::CCLabelBMFont* m_pPracticeLabel;
	cocos2d::CCLabelBMFont* m_pNameLabel;
	cocos2d::CCLabelBMFont* m_pStarsLabel;
	float m_fProgressBarWidth;
	cocos2d::CCSprite* m_pProgressBar;
	cocos2d::CCSprite* m_pPracticeBar;
	cocos2d::CCSprite* m_pDifficulty;
	cocos2d::CCSprite* m_pStars;
	cocos2d::CCSize m_obPageSize;
	cocos2d::CCArray* m_pCoins;
	cocos2d::CCArray* m_pEvents;
	cocos2d::CCArray* m_pLevelInfo;
	cocos2d::CCArray* m_pPlayerLevelStats;
	GameObject* m_pSecretMenuCoin;
	cocos2d::CCSprite* m_pDoor;

	bool init(GJGameLevel*);
	void addSecretDoor();

};
