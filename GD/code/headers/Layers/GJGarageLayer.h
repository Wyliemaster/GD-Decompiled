#include "includes.h"

class GJGarageLayer : public cocos2d::CCLayer,
	TextInputDelegate,
	FLAlertLayerProtocol,
	GameRateDelegate,
	ListButtonBarDelegate,
	DialogDelegate
{
	CCTextInputNode* m_pName;
	SimplePlayer* m_pIcon;
	void* m_pUnk;
	cocos2d::CCNode* m_pUnkCCNode;
	cocos2d::CCSprite* m_pCol1Selector;
	cocos2d::CCSprite* m_pCol2Selector;
	CCMenuItemSpriteExtra* m_pCol1Btn;
	CCMenuItemSpriteExtra* m_pCol2Btn;
	int m_unk;
	void* m_pUnkRatePointer2;
	cocos2d::CCArray* m_pGaragePageArray;
	float m_fUnk1;
	float m_fUnk2;
	CCMenuItemToggler* m_bSelectFrameBtn;
	CCMenuItemToggler* m_pSelectShipBtn;
	CCMenuItemToggler* m_pSelectBallBtn;
	CCMenuItemToggler* m_pSelectBirdBtn;
	CCMenuItemToggler* m_pSelectDartBtn;
	CCMenuItemToggler* m_pSelectRobotBtn;
	CCMenuItemToggler* m_pSelectSpiderBtn;
	CCMenuItemToggler* m_pSelectStreakBtn;
	CCMenuItemToggler* m_pSelectDeathBtn;
	void* m_pUnkRatePointer;
	bool m_bUnlocked;
	bool m_bUnkOnBack;
};