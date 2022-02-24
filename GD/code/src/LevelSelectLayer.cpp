#include "../headers/includes.h"

cocos2d::ccColor3B LevelSelectLayer::colorForPage(int page)
{
	GameManager* GM = GameManager::sharedState();
	int colIDs[9] = { 5 ,7, 8, 9, 10, 11, 1, 3, 4 }; // GD uses switch statement but this is easier to write

	return GM->colorForIdx(colIDs[page % 9]);
}

bool LevelSelectLayer::init(int page)
{
	bool init = cocos2d::CCLayer::init();
	if (init)
	{
		GameManager* GM = GameManager::sharedState();
		GameLevelManager* GLM = GameLevelManager::sharedState();


		setKeypadEnabled(true);
		setKeyboardEnabled(true);

		m_bSecretMenuCoin = AchievementManager::sharedState()->isAchievementEarned("geometry.ach.secret04");
		cocos2d::CCDirector* director = cocos2d::CCDirector::sharedDirector();
		cocos2d::CCSize winSize = director->getWinSize();

		m_pBackground = cocos2d::CCSprite::create("GJ_gradientBG.png");
		m_pBackground->setAnchorPoint({ 0.0f, 0.0f });
		addChild(m_pBackground, -2);

		m_pBackground->setScaleX((winSize.width + 10.0f) / m_pBackground->getTextureRect().size.width);
		m_pBackground->setScaleX((winSize.height + 10.0f) / m_pBackground->getTextureRect().size.height);
		m_pBackground->setPosition({ -5.0f, -5.0f });
		m_pBackground->setColor({ 0x28, 0x7D, 0xFF });

		// why does game manager store the ground id? who knows!
		m_pGround = GJGroundLayer::create(GM->m_nGroundID, 1);
		m_pGround->PositionGround(std::min(128.0f, (winSize.height / 2) - 110.0f));

		cocos2d::CCSprite* topBar = cocos2d::CCSprite::create("GJ_topBar_001.png");
		topBar->setAnchorPoint({ 0.5f, 1.0f });
		topBar->setPosition({ winSize / 2, director->getScreenTop() + 1.0f });

		addChild(topBar, 1);

		cocos2d::CCSprite* leftArt = cocos2d::CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
		leftArt->setAnchorPoint({ 0.0f, 0.0f });
		leftArt->setPosition({ director->getScreenLeft() - 1.0f, director->getScreenBottom() - 1.0f });
		addChild(leftArt, 1);

		cocos2d::CCSprite* rightArt = cocos2d::CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
		rightArt->setAnchorPoint({ 1.0f, 0.0f });
		rightArt->setPosition({ director->getScreenRight() + 1.0f, director->getScreenBottom() - 1.0f });
		rightArt->isFlipX();
		addChild(rightArt, 1);

		cocos2d::CCArray* mainLevels = cocos2d::CCArray::create();
		cocos2d::CCArray* levelPages = cocos2d::CCArray::create();
		for (size_t i = 0; i < 22; i++)
			mainLevels->addObject(GLM->getMainLevel(i, true));

		for (size_t i = 0; i < 3; i++)
			levelPages->addObject(LevelPage::create(nullptr)); // the class takes a level object?

		GJGameLevel* defaultLevel = GJGameLevel::create();
		defaultLevel->setLevelID(-1);
		mainLevels->addObject(defaultLevel);

		m_pBoomScrollLayer = BoomScrollLayer::create(mainLevels, 0, true, levelPages, static_cast<DynamicScrollDelegate *>(this));
		addChild(m_pBoomScrollLayer);

		m_pBoomScrollLayer->setPagesIndicatorPosition({ winSize / 2, director->getScreenBottom() + 15.0f });

		m_fWindowWidth = winSize.width;

		m_pBoomScrollLayer->m_pExtendedLayer->m_pDelegate = static_cast<BoomScrollLayerDelegate*>(this);

		if (page)
		{
			if (page == 21)
				m_pBoomScrollLayer->instantMoveToPage(20);
			m_pBoomScrollLayer->instantMoveToPage(page);
		}
		else
		{
			scrollLayerMoved(&Globals::gScollLayerPos); //
		}

		cocos2d::CCLabelBMFont* download = cocos2d::CCLabelBMFont::create("Download the soundtracks", "bigFont.fnt");
		download->setScale(0.5f);

		CCMenuItemSpriteExtra* downloadBtn = CCMenuItemSpriteExtra::create(download, this, LevelSelectLayer::onDownload);
		downloadBtn->setSizeMult(2.0f);

		cocos2d::CCMenu* DLMenu = cocos2d::CCMenu::create();
		addChild(DLMenu);

		DLMenu->setPosition({ winSize / 2 , director->getScreenBottom() + 35.0f });
	
		cocos2d::CCMenu* btnMenu = cocos2d::CCMenu::create();
		addChild(btnMenu, 5);

		bool controller = PlatformToolbox::isControllerConnected();

		cocos2d::CCSprite* left = cocos2d::CCSprite::createWithSpriteFrameName(controller ? "controllerBtn_DPad_Left_001.png" : "navArrowBtn_001.png");
		if (!controller)
			left->isFlipX();

		CCMenuItemSpriteExtra* leftBtn = CCMenuItemSpriteExtra::create(left, this, LevelSelectLayer::onPrev);
		btnMenu->addChild(leftBtn);

		leftBtn->setSizeMult(2.0f);
		leftBtn->setPosition(btnMenu->convertToNodeSpace( { director->getScreenLeft() + 25.0f, winSize.height / 2 }));


		cocos2d::CCSprite* right = cocos2d::CCSprite::createWithSpriteFrameName(controller ? "controllerBtn_DPad_Right_001.png : "navArrowBtn_001.png");

		CCMenuItemSpriteExtra* rightBtn = CCMenuItemSpriteExtra::create(right, this, LevelSelectLayer::onNext);
		btnMenu->addChild(rightBtn);

		leftBtn->setSizeMult(2.0f);
		leftBtn->setPosition({ btnMenu->convertToNodeSpace(director->getScreenRight() - 25.0f, winSize.height / 2 }));


		cocos2d::CCSprite* back = cocos2d::CCSprite::createWithSpriteFrame("GJ_arrow_01_001.png");
		CCMenuItemSpriteExtra* backBtn = CCMenuItemSpriteExtra::create(back, this, LevelSelectLayer::onBack);
		backBtn->setSizeMult(1.6f);

		cocos2d::CCMenu* backMenu = cocos2d::CCMenu::create();
		addChild(backMenu, 1);

		backMenu->addChild(backBtn);

		backMenu->setPosition({ director->getScreenLeft() + 25.0f, director->getScreenTop() - 22.0f });

		//GM->0x298 = 0;

		cocos2d::CCMenu* infoMenu = cocos2d::CCMenu::create();
		addChild(infoMenu);

		cocos2d::CCSprite* info = cocos2d::CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
		CCMenuItemSpriteExtra* infoBtn = CCMenuItemSpriteExtra::create(info, this, LevelSelectLayer::onInfo);
		infoMenu->addChild(infoBtn);

		infoMenu->setPosition({ director->getScreenRight() - 20.0f, director->getScreenTop() - 20.0f });

		if (controller)
			GameToolbox::addBackButton(this, backBtn);

	}	
	return init;
}