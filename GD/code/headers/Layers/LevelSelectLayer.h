#include "../includes.h"

class BoomScrollLayerDelegate;
class DynamicScrollDelegate;
class LevelPage*

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
	cocos2d::ccColor3B getColorValue(int, int, float);
	bool init(int);
	bool tryShowAd();
	void onPrev(cocos2d::CCObject*);
	void onNext(cocos2d::CCObject*);
	void onDownload(cocos2d::CCObject*);
	void onInfo(cocos2d::CCObject*);
	void onPlay(cocos2d::CCObject*);
	void onBack(cocos2d::CCObject*);
	void backKeyClicked();
	void scollLayerMove(cocos2d::CCPoint);
	void keyDown(int);
	static LevelSelectLayer* create(int);
	cocos2d::CCScene* scene(int);
	void updatePageWithObject(LevelPage*, GJGameLevel*)
};
