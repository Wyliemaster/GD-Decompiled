#include "../headers/includes.h"

SetIDLayer::SetIDLayer()
{
	m_pGameObject = nullptr;
	m_pIDLabel = nullptr;
}

void SetIDLayer::onDown(cocos2d::CCObject* btn)
{
	m_pGameObject->m_nSecretCoinID <= 1 ? m_pGameObject->m_nSecretCoinID = 0 : m_pGameObject->m_nSecretCoinID--;
	updateID();
}

void SetIDLayer::onUp(cocos2d::CCObject* btn)
{
	m_pGameObject->m_nSecretCoinID++;
	updateID();
}

void SetIDLayer::updateID()
{
	std::string label = cocos2d::CCString::createWithFormat("%i", >m_pGameObject->m_nSecretCoinID)->m_sString;
	m_pIDLabel->setString(label);
}

bool SetIDLayer::init(GameObject* obj)
{
	// kinda rushed through this, dont expect it to be accurate or valid
	bool init = cocos2d::CCLayerColor::initWithColor({0x00, 0x00, 0x00, 0x4B});
	if (init)
	{
		cocos2d::CCDirector* director = cocos2d::CCDirector::sharedDirector();
		director->getTouchDispatcher()->incrementForcePrio(2);
		m_pGameObject = obj;

		setTouchEnabled(true);
		setKeypadEnabled(true);

		cocos2d::CCSize winSize = director->getWinSize();
		m_pLayer = cocos2d::CCLayer::create();

		this->addChild(m_pLayer);

		cocos2d::extension::CCScale9Sprite* bg = cocos2d::extension::CCScale9Sprite::create("GJ_square01.png", { 0.0f, 0.0f, 80.0f, 80.0f });
		bg->setContentSize({ 360.0f, 180.0f });
		m_pLayer->addChild(bg, -1);
		bg->setPosition({ winSize.width / 2, winSize.height / 2 });

		cocos2d::CCLabelBMFont* title = cocos2d::CCLabelBMFont::create("Set ID", "bigFont.fnt");
		title->setPosition({ winSize.width / 2, (winSize.height / 2) + 70.0f });

		m_pButtonMenu = cocos2d::CCMenu::create();
		m_pLayer->addChild(m_pButtonMenu, 10);

		m_pButtonMenu->addChild(title);

		// to lazy to double check so convertToNodeSpace it is!
		cocos2d::CCMenuItemSpriteExtra* okBtn = cocos2d::CCMenuItemSpriteExtra::create(ButtonSprite::create("OK"), this, onClose);
		m_pButtonMenu->addChild(okBtn);
		okBtn->setScale(convertToNodeSpace( { winSize.width / 2, (winSize.height / 2) - 100.0f } ));

		cocos2d::CCMenuItemSpriteExtra* downBtn = cocos2d::CCMenuItemSpriteExtra::create(cocos2d::CCSprite::createWithSpriteFrameName("GJ_arrow_02_001.png"), this, onDown);
		m_pButtonMenu->addChild(downBtn);
		downBtn->setScale(convertToNodeSpace({ (winSize.width / 2) - 100.0f, winSize.height / 2 } ));
		downBtn->setSizeMulti(4.0f);
		downBtn->setRotation(-90.0f);


		cocos2d::CCMenuItemSpriteExtra* upBtn = cocos2d::CCMenuItemSpriteExtra::create(cocos2d::CCSprite::createWithSpriteFrameName("GJ_arrow_02_001.png"), this, onUp);
		m_pButtonMenu->addChild(upBtn);
		upBtn->setScale(convertToNodeSpace({ (winSize.width / 2) + 100.0f, winSize.height / 2 } ));
		upBtn->setSizeMulti(4.0f);
		upBtn->setRotation(90.0f);

	}
	return init;
}