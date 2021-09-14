#include "includes.h"

class FLAlertLayerProtocol;
class GooglePlayDelegate;
class CCMenuItemSpriteExtra;

class MenuLayer : public cocos2d::CCLayer, FLAlertLayerProtocol, GooglePlayDelegate
{
	cocos2d::CCSpriteFrameCache* m_pGooglePlaySprite;
	cocos2d::CCSprite* m_pViewProfileText;
	cocos2d::CCLabelBMFont* m_pPlayerNameLabel;
	CCMenuItemSpriteExtra* m_pProfileBtn;
};
