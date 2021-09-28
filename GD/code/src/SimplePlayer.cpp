#include "../headers/includes.h"

SimplePlayer::SimplePlayer()
{
	m_pPlayerSpriteLayer1 = nullptr;
	m_pPlayerSpriteLayer2 = nullptr;
	m_pPlayerSpriteBirdDome = nullptr;
	m_pPlayerSpriteGlow = nullptr;
	m_pPlayerSpriteDetail = nullptr;
	m_pRobotSprite = nullptr;
	m_pSpiderSprite = nullptr;
	m_unk = 0;
	m_bGlow = false;

}

SimplePlayer* SimplePlayer::create(int _iconID)
{
	auto pRet = new SimplePlayer;

	if (pRet && pRet->init(_iconID))
	{
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return nullptr;
}

bool SimplePlayer::init(int _iconID) 
{
	bool init = cocos2d::CCSprite::init();
	if (!init) return false;

	int id = std::min(_iconID, 142) <= 0 ? 1 : std::min(_iconID, 142);

	std::string layer1 = cocos2d::CCString::createWithFormat("player_%02d_001.png", id)->m_sString;
	std::string layer2 = cocos2d::CCString::createWithFormat("player_%02d_2_001.png", id)->m_sString;
	std::string layerGlow = cocos2d::CCString::createWithFormat("player_%02d_glow_001.png", id)->m_sString;

	setTextureRect(g_Unk75843C);

	m_pPlayerSpriteLayer1 = cocos2d::CCSprite::createWithSpriteFrameName(layer1);
	m_pPlayerSpriteLayer2 = cocos2d::CCSprite::createWithSpriteFrameName(layer2);

	m_pPlayerSpriteLayer1->addChild(m_pPlayerSpriteLayer2, -1);
	m_pPlayerSpriteLayer2->setPosition(m_pPlayerSpriteLayer1->convertToNodeSpace(g_obUnknownGlobal));

	m_pPlayerSpriteBirdDome = cocos2d::CCSprite::createWithSpriteFrameName(layer2);
	m_pPlayerSpriteLayer1->addChild(m_pPlayerSpriteBirdDome, -2);
	m_pPlayerSpriteBirdDome->setPosition(m_pPlayerSpriteLayer1->convertToNodeSpace(g_obUnknownGlobal));

	m_pPlayerSpriteGlow = cocos2d::CCSprite::createWithSpriteFrameName(layerGlow);
	m_pPlayerSpriteLayer1->addChild(m_pPlayerSpriteGlow, -3);
	m_pPlayerSpriteGlow->setPosition(m_pPlayerSpriteLayer1->convertToNodeSpace(g_obUnknownGlobal));
	m_pPlayerSpriteGlow->setVisible(false);

	m_pPlayerSpriteDetail = cocos2d::CCSprite::createWithSpriteFrameName(layerGlow);
	m_pPlayerSpriteLayer1->addChild(m_pPlayerSpriteDetail, 1);
	m_pPlayerSpriteDetail->setPosition(m_pPlayerSpriteLayer1->convertToNodeSpace(g_obUnknownGlobal));

	m_pRobotSprite = GJRobotSprite::create();
	m_pRobotSprite->setVisible(false);
	addChild(m_pRobotSprite);

	m_pSpiderSprite = m_pSpiderSprite::create();
	m_pSpiderSprite->setVisible(false);
	addChild(m_pSpiderSprite);

	m_pSpiderSprite->setPosition({ 0.0f, -1.5f });
	updatePlayerFrame(id, 0); // todo add IconType Enum
	return true;
}