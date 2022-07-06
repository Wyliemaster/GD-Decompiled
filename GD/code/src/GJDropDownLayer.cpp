#include "GJDropDownLayer.h"

GJDropDownLayer::GJDropDownLayer() {
	this->m_endPosition = ccp(0, 0);
	this->m_startPosition = ccp(0, 0);
	this->m_buttonMenu = nullptr;
	this->m_listLayer = nullptr;
	this->m_controllerEnabled = false;
	this->m_mainLayer = nullptr;
	this->m_hidden = false;
	this->m_delegate = nullptr;
}

GJDropDownLayer::~GJDropDownLayer() {
	cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->decrementForcePrio(2);
}

void GJDropDownLayer::disableUI() {
	this->m_buttonMenu->setTouchEnabled(false);
}

void GJDropDownLayer::enableUI() {
	this->m_buttonMenu->setTouchEnabled(true);
}

void GJDropDownLayer::draw() {
	if (this->getOpacity())
		this->draw();
}

void GJDropDownLayer::enterLayer() {
	this->enableUI();
	this->showLayer(false);
}

void GJDropDownLayer::exitLayer(cocos2d::CCObject* p) {
	this->setKeypadEnabled(false);

	auto director = cocos2d::CCDirector::sharedDirector();
	director->getTouchDispatcher()->m_bForcePrio = false;

	this->disableUI();
	this->hideLayer(false);
}

void GJDropDownLayer::hideLayer(bool instantHide) {
	if (this->m_hidden) {
		if (this->m_delegate)
			this->m_delegate->dropDownLayerWillClose(this);
	}

	this->m_mainLayer->stopAllActions();

	if (instantHide) {
		this->m_mainLayer->setPosition(this->m_startPosition);
		this->setOpacity(0);
		this->layerHidden();
	}
	else {
		auto action = cocos2d::CCEaseInOut::create(cocos2d::CCMoveTo::create(0.5, this->m_startPosition), 2.);
		auto callback = cocos2d::CCCallFunc::create(this, callfunc_selector(GJDropDownLayer::exitLayer));
		auto seq = cocos2d::CCSequence::create(action, callback);
		this->m_mainLayer->runAction(seq);
		this->runAction(cocos2d::CCFadeTo::create(0.5, 0));
	}
}

void GJDropDownLayer::registerWithTouchDispatcher() {
	cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -500, true);
}

void GJDropDownLayer::keyBackClicked() {
	this->exitLayer(nullptr);
}

void GJDropDownLayer::layerHidden() {
	this->setVisible(false);
	if (this->m_hidden)
		this->removeFromParentAndCleanup(true);
}

void GJDropDownLayer::layerVisible() {
	this->setVisible(true);
}

void GJDropDownLayer::showLayer(bool instantShow) {
	this->m_mainLayer->stopAllActions();
	this->layerVisible();

	if (instantShow) {
		this->m_mainLayer->setPosition(this->m_endPosition);
		this->setOpacity(125);
		this->enterAnimFinished();
	}
	else {
		auto action = cocos2d::CCEaseInOut::create(cocos2d::CCMoveTo::create(0.5, this->m_endPosition), 2.);
		auto callback = cocos2d::CCCallFunc::create(this, callfunc_selector(GJDropDownLayer::enterLayer));
		this->m_mainLayer->runAction(cocos2d::CCSequence::create(action, callback));
		this->setOpacity(0);
		this->runAction(cocos2d::CCFadeTo::create(0.5, 125));
	}
}

GJDropDownLayer* GJDropDownLayer::create(const char* title, float height) {
	auto pRet = new GJDropDownLayer();

	if (pRet && pRet->init(title, height)) {
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return nullptr;
}

GJDropDownLayer* GJDropDownLayer::create(const char* title) {
	return GJDropDownLayer::create(title, 220);
}

bool GJDropDownLayer::init(const char* title) {
	return this->init(title, 220);
}

bool GJDropDownLayer::init(const char* title, float height) {
	cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->incrementForcePrio(2);

	if (!this->initWithColor({ 0, 0, 0, 125 }))
		return false;

	this->setTouchEnabled(true);
	this->setKeypadEnabled(true);
	this->setKeyboardEnabled(true);

	auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
	
	this->m_mainLayer = cocos2d::CCLayer::create();
	this->addChild(this->m_mainLayer);

	this->m_endPosition = ccp(0, 0);
	this->m_startPosition = ccp(0, winSize.height);

	this->m_mainLayer->setPosition(this->m_startPosition);

	this->m_listLayer = GJListLayer::create(nullptr, title, { 0, 0, 0, 180 }, 356.0, height); // it shows -76 in decomp but 0xB4 in asm so i guess its 0xB4 :P
	this->m_mainLayer->addChild(this->m_listLayer);

	this->m_listLayer->setPosition({ (winSize.width - 356.0) * 0.5, (((winSize.height - height) * 0.5) - 10.0) + 5.0 });

	auto spr = cocos2d::CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
	auto btn = CCMenuItemSpriteExtra::create(spr, nullptr, this, menu_selector(GJDropDownLayer::exitLayer)); // not sure about GJDropDownLayer::exitLayer, again &stru_274.st_value
	btn->setSizeMult(1.6);

	this->m_buttonMenu = cocos2d::CCMenu::create(btn);
	this->m_buttonMenu->setPosition({ (winSize.width * 0.5) + 178.0, (winSize.height * 0.5) - (height * 0.5) });

	//that doesnt make sense wtf

	auto director = cocos2d::CCDirector::sharedDirector();
	this->m_buttonMenu->setPosition({ director->getScreenLeft() + 24, director->getScreenTop() - 23 });

	this->m_mainLayer->addChild(this->m_buttonMenu, 10);

	auto chain1 = cocos2d::CCSprite::createWithSpriteFrameName("chain_01_001.png");
	this->m_mainLayer->addChild(chain1, -1);
	chain1->setAnchorPoint({ 0.5, 0.0 });
	chain1->setPosition({ (winSize.width * 0.5) - 156.0, height + this->m_listLayer->getPosition().y + 12.0 });
	chain1->setTag(0);

	auto chain2 = cocos2d::CCSprite::createWithSpriteFrameName("chain_01_001.png");
	this->m_mainLayer->addChild(chain2, -1);
	chain2->setAnchorPoint({ 0.5, 0.0 });
	chain2->setPosition({ (winSize.width * 0.5) + 156.0, height + this->m_listLayer->getPosition().y + 12.0 });
	chain2->setTag(1);

	this->m_hidden = false;
	this->hideLayer(true);
	this->m_hidden = true;

	this->customSetup();

	if (PlatformToolbox::isControllerConnected() && !this->m_controllerEnabled)
		GameToolbox::addBackButton(this->m_mainLayer, btn);

	return true;
}