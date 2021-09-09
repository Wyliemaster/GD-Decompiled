#include "../headers/includes.h"

GJBaseGameLayer::GJBaseGameLayer()
{
	m_nUnk = 1;
}

void GJBaseGameLayer::enableHighCapacityMode()
{
	int high = 0x3E7;
	int mid = 0xC8;
	int low = 0x64;

	m_pBatchNodeAddTop2->increaseAtlasCapacity(high);
	m_pBatchNode->increaseAtlasCapacity(high);
	m_pBatchNodeAdd->increaseAtlasCapacity(high);
	m_pBatchNodePlayer->increaseAtlasCapacity(high);
	m_pBatchNodeAddPlayer->increaseAtlasCapacity(high);
	m_pBatchNodeAddMid->increaseAtlasCapacity(high);
	m_pBatchNodeBot->increaseAtlasCapacity(high);
	m_pBatchNodeAddBot->increaseAtlasCapacity(high);

	m_pEffectBatchNode->increaseAtlasCapacity(high);
	m_pEffectBatchNodeAdd->increaseAtlasCapacity(high);

	m_pBatchNodeBot2->increaseAtlasCapacity(high);
	m_pBatchNodeAddBot2->increaseAtlasCapacity(high);
	m_pBatchNodeAddGlow->increaseAtlasCapacity(high);
	m_pBatchNodeAddBotGlow->increaseAtlasCapacity(high);
	m_pBatchNodeAddBot2Glow->increaseAtlasCapacity(high);
	m_pBatchNodeBot4->increaseAtlasCapacity(high);
	m_pBatchNodeAddBot4->increaseAtlasCapacity(high);
	m_pBatchNodeAddBot4Glow->increaseAtlasCapacity(high);
	m_pBatchNodeBot3->increaseAtlasCapacity(high);
	m_pBatchNodeAddBot3->increaseAtlasCapacity(high);
	m_pBatchNodeAddBot3Glow->increaseAtlasCapacity(high);
	m_pBatchNodeTop2->increaseAtlasCapacity(high);
	m_pBatchNodeAddGlowTop2->increaseAtlasCapacity(high);
	m_pBatchNodeTop3->increaseAtlasCapacity(high);
	m_pBatchNodeAddTop3->increaseAtlasCapacity(high);
	m_pBatchNodeAddGlowTop3->increaseAtlasCapacity(high);
	m_pBatchNodeAddTop4->increaseAtlasCapacity(mid);

	m_pEffectBatchNodeAddTop4->increaseAtlasCapacity(low);
	m_pEffectBatchNodeTop3->increaseAtlasCapacity(mid);
	m_pEffectBatchNodeAddTop3->increaseAtlasCapacity(mid);
	m_pEffectBatchNodeTop2->increaseAtlasCapacity(mid);
	m_pEffectBatchNodeAddTop2->increaseAtlasCapacity(mid);
	m_pEffectBatchNodeTop1->increaseAtlasCapacity(mid);
	m_pEffectBatchNodeAddTop1->increaseAtlasCapacity(mid);
	m_pEffectBatchNodeBot2->increaseAtlasCapacity(mid);
	m_pEffectBatchNodeAddBot2->increaseAtlasCapacity(mid);
	m_pEffectBatchNodeBot3->increaseAtlasCapacity(mid);
	m_pEffectBatchNodeAddBot3->increaseAtlasCapacity(mid);
	m_pEffectBatchNodeBot4->increaseAtlasCapacity(mid);
	m_pEffectBatchNodeAddBot4->increaseAtlasCapacity(mid);

	m_pBatchNodeTextTop3->increaseAtlasCapacity(low);
	m_pBatchNodeAddTextTop3->increaseAtlasCapacity(low);
	m_pBatchNodeTextTop2->increaseAtlasCapacity(low);
	m_pBatchNodeAddTextTop2->increaseAtlasCapacity(low);
	m_pBatchNodeTextTop1->increaseAtlasCapacity(low);
	m_pBatchNodeAddTextTop1->increaseAtlasCapacity(low);
	m_pBatchNodeText->increaseAtlasCapacity(low);
	m_pBatchNodeAddText->increaseAtlasCapacity(low);
	m_pBatchNodeTextBot2->increaseAtlasCapacity(low);
	m_pBatchNodeAddTextBot2->increaseAtlasCapacity(low);
	m_pBatchNodeTextBot3->increaseAtlasCapacity(low);
	m_pBatchNodeAddTextBot3->increaseAtlasCapacity(low);
	m_pBatchNodeTextBot4->increaseAtlasCapacity(low);
	m_pBatchNodeAddTextBot4->increaseAtlasCapacity(low);
}

std::string GJBaseGameLayer::getCapacityString()
{
	return cocos2d::CCString::createWithFormat("%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i",
		atlasValue(m_pBatchNodeAddTop2->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNode->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAdd->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodePlayer->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddPlayer->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddMid->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeBot->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddBot->getUsedAtlasCapacity()),
		atlasValue(m_pEffectBatchNode->getUsedAtlasCapacity()),
		atlasValue(m_pEffectBatchNodeAdd->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeBot2->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddBot2->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddGlow->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddBotGlow->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddBot2Glow->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeBot4->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddBot4->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddBot4Glow->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeBot3->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddBot3->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddBot3Glow->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeTop2->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddGlowTop2->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeTop3->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddTop3->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddGlowTop3->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddTop4->getUsedAtlasCapacity()),
		atlasValue(m_pEffectBatchNodeTop3->getUsedAtlasCapacity()),
		atlasValue(m_pEffectBatchNodeAddTop3->getUsedAtlasCapacity()),
		atlasValue(m_pEffectBatchNodeTop2->getUsedAtlasCapacity()),
		atlasValue(m_pEffectBatchNodeAddTop2->getUsedAtlasCapacity()),
		atlasValue(m_pEffectBatchNodeTop1->getUsedAtlasCapacity()),
		atlasValue(m_pEffectBatchNodeAddTop1->getUsedAtlasCapacity()),
		atlasValue(m_pEffectBatchNodeBot2->getUsedAtlasCapacity()),
		atlasValue(m_pEffectBatchNodeAddBot2->getUsedAtlasCapacity()),
		atlasValue(m_pEffectBatchNodeBot3->getUsedAtlasCapacity()),
		atlasValue(m_pEffectBatchNodeAddBot3->getUsedAtlasCapacity()),
		atlasValue(m_pEffectBatchNodeBot4->getUsedAtlasCapacity()),
		atlasValue(m_pEffectBatchNodeAddBot4->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeTextTop3->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddTextTop3->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeTextTop2->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddTextTop2->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeTextTop1->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddTextTop1->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeText->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddText->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeTextBot2->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddTextBot2->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeTextBot3->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddTextBot3->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeTextBot4->getUsedAtlasCapacity()),
		atlasValue(m_pBatchNodeAddTextBot4->getUsedAtlasCapacity()),
		atlasValue(m_pEffectBatchNodeAddTop4->getUsedAtlasCapacity())
	)->m_sString;
}

int GJBaseGameLayer::atlasValue(int _capacity);
{
	if (_capacity <= 29) return 0;
	return std::min(_capacity * 1.1, 9999);
}

cocos2d::CCArray* GJBaseGameLayer::getGroup(int _idx)
{
	int index = _idx;
	if (_idx >= 999) index = 999;
	cocos2d::CCArray *group = m_pGroups[index];
	if (!group)
	{
		group = cocos2d::CCArray::create();
		m_pGroupDict->setObject(group, index);
		m_pGroups[index] = group;
	}
	return group;
}

cocos2d::CCArray* GJBaseGameLayer::getStaticGroup(int _idx)
{
	cocos2d::CCArray* group = m_pStaticGroups[_idx];
	if (!group)
	{
		group = cocos2d::CCArray::create();
		m_pGroupDict->setObject(group, _idx);
		m_pStaticGroups[_idx] = group;
	}
	return group;
}

cocos2d::CCArray* GJBaseGameLayer::getOptimizedGroup(int _idx)
{
	cocos2d::CCArray* group = m_pOptimisedGroups[_idx];
	if (!group)
	{
		group = cocos2d::CCArray::create();
		m_pGroupDict->setObject(group, _idx);
		m_pOptimisedGroups[_idx] = group;
	}
	return group;
}

void GJBaseGameLayer::updateLegacyLayerCapacity(int _top, int _topBlending, int _bot, int _botBlending)
{
	int topBlend = std::min(_topBlending, 100);
	int top = std::min(_top, 100);
	int botBlending = std::min(_botBlending, 100);
	int bot = std::min(_bot, 100);
	int player = 50;

	//top nodes
	m_pBatchNode->increaseAtlasCapacity(top);
	m_pBatchNodeAdd->increaseAtlasCapacity(topBlend);

	//playerNodes
	m_pBatchNodePlayer->increaseAtlasCapacity(player);
	m_pBatchNodeAddPlayer->increaseAtlasCapacity(player);

	//B1 Nodes
	m_pBatchNodeBot->increaseAtlasCapacity(bot);
	m_pBatchNodeAddBot->increaseAtlasCapacity(botBlending);

	//B2 Nodes
	m_pBatchNodeBot2->increaseAtlasCapacity(bot);
	m_pBatchNodeAddBot2->increaseAtlasCapacity(botBlending);

	//Glow Nodes
	m_pBatchNodeAddGlow->increaseAtlasCapacity(topBlend >> 1);
	m_pBatchNodeAddBotGlow->increaseAtlasCapacity(botBlending >> 1);
	m_pBatchNodeAddBot2Glow->increaseAtlasCapacity(botBlending >> 1);
}

void GJBaseGameLayer::updateLayerCapacity(std::string _capacityString)
{
	cocos2d::CCArray *batchNodes = RobTop::splitToCCArray(_capacityString, "_");
	if (batchNodes->count() > 0xF)
	{
		m_bUpdatedNormalCapacity = true;
		//2.0
		m_pBatchNodeAddTop2->increaseAtlasCapacity(batchNodes->stringAtIndex(0x0)->intValue());
		m_pBatchNode->increaseAtlasCapacity(batchNodes->stringAtIndex(0x1)->intValue());
		m_pBatchNodeAdd->increaseAtlasCapacity(batchNodes->stringAtIndex(0x2)->intValue());
		m_pBatchNodePlayer->increaseAtlasCapacity(batchNodes->stringAtIndex(0x3)->intValue());
		m_pBatchNodeAddPlayer->increaseAtlasCapacity(batchNodes->stringAtIndex(0x4)->intValue());
		m_pBatchNodeAddMid->increaseAtlasCapacity(batchNodes->stringAtIndex(0x5)->intValue());
		m_pBatchNodeBot->increaseAtlasCapacity(batchNodes->stringAtIndex(0x6)->intValue());
		m_pBatchNodeAddBot->increaseAtlasCapacity(batchNodes->stringAtIndex(0x7)->intValue());
		m_pEffectBatchNode->increaseAtlasCapacity(batchNodes->stringAtIndex(0x8)->intValue());
		m_pEffectBatchNodeAdd->increaseAtlasCapacity(batchNodes->stringAtIndex(0x9)->intValue());
		m_pBatchNodeBot2->increaseAtlasCapacity(batchNodes->stringAtIndex(0xA)->intValue());
		m_pBatchNodeAddBot2->increaseAtlasCapacity(batchNodes->stringAtIndex(0xB)->intValue());
		m_pBatchNodeAddGlow->increaseAtlasCapacity(batchNodes->stringAtIndex(0xC)->intValue());
		//Robert seems to have accidentally skipped index 0xD so the batch nodes after this arent optimised
		//as they are misaligned with the capacity string
		m_pBatchNodeAddBotGlow->increaseAtlasCapacity(batchNodes->stringAtIndex(0xE)->intValue());
		m_pBatchNodeAddBot2Glow->increaseAtlasCapacity(batchNodes->stringAtIndex(0xF)->intValue());
		if (batchNodes->count() > 0x36)
		{
			//2.1
			m_bUpdatedNormalCapacity = false;

			m_pBatchNodeBot4->increaseAtlasCapacity(batchNodes->stringAtIndex(0x10)->intValue());
			m_pBatchNodeAddBot4->increaseAtlasCapacity(batchNodes->stringAtIndex(0x11)->intValue());
			m_pBatchNodeAddBot4Glow->increaseAtlasCapacity(batchNodes->stringAtIndex(0x12)->intValue());
			m_pBatchNodeBot3->increaseAtlasCapacity(batchNodes->stringAtIndex(0x13)->intValue());
			m_pBatchNodeAddBot3->increaseAtlasCapacity(batchNodes->stringAtIndex(0x14)->intValue());
			m_pBatchNodeAddBot3Glow->increaseAtlasCapacity(batchNodes->stringAtIndex(0x15)->intValue());
			m_pBatchNodeTop2->increaseAtlasCapacity(batchNodes->stringAtIndex(0x16)->intValue());
			m_pBatchNodeAddGlowTop2->increaseAtlasCapacity(batchNodes->stringAtIndex(0x17)->intValue());
			m_pBatchNodeTop3->increaseAtlasCapacity(batchNodes->stringAtIndex(0x18)->intValue());
			m_pBatchNodeAddTop3->increaseAtlasCapacity(batchNodes->stringAtIndex(0x19)->intValue());
			m_pBatchNodeAddGlowTop3->increaseAtlasCapacity(batchNodes->stringAtIndex(0x1A)->intValue());
			m_pBatchNodeAddTop4->increaseAtlasCapacity(batchNodes->stringAtIndex(0x1B)->intValue());
			m_pEffectBatchNodeTop3->increaseAtlasCapacity(batchNodes->stringAtIndex(0x1C)->intValue());
			m_pEffectBatchNodeAddTop3->increaseAtlasCapacity(batchNodes->stringAtIndex(0x1D)->intValue());
			m_pEffectBatchNodeTop2->increaseAtlasCapacity(batchNodes->stringAtIndex(0x1E)->intValue());
			m_pEffectBatchNodeAddTop2->increaseAtlasCapacity(batchNodes->stringAtIndex(0x1F)->intValue());
			m_pEffectBatchNodeTop1->increaseAtlasCapacity(batchNodes->stringAtIndex(0x20)->intValue());
			m_pEffectBatchNodeAddTop1->increaseAtlasCapacity(batchNodes->stringAtIndex(0x21)->intValue());
			m_pEffectBatchNodeBot2->increaseAtlasCapacity(batchNodes->stringAtIndex(0x22)->intValue());
			m_pEffectBatchNodeAddBot2->increaseAtlasCapacity(batchNodes->stringAtIndex(0x23)->intValue());
			m_pEffectBatchNodeBot3->increaseAtlasCapacity(batchNodes->stringAtIndex(0x24)->intValue());
			m_pEffectBatchNodeAddBot3->increaseAtlasCapacity(batchNodes->stringAtIndex(0x25)->intValue());
			m_pEffectBatchNodeBot4->increaseAtlasCapacity(batchNodes->stringAtIndex(0x26)->intValue());
			m_pEffectBatchNodeAddBot4->increaseAtlasCapacity(batchNodes->stringAtIndex(0x27)->intValue());
			m_pBatchNodeTextTop3->increaseAtlasCapacity(batchNodes->stringAtIndex(0x28)->intValue());
			m_pBatchNodeAddTextTop3->increaseAtlasCapacity(batchNodes->stringAtIndex(0x29)->intValue());
			m_pBatchNodeTextTop2->increaseAtlasCapacity(batchNodes->stringAtIndex(0x2A)->intValue());
			m_pBatchNodeAddTextTop2->increaseAtlasCapacity(batchNodes->stringAtIndex(0x2B)->intValue());
			m_pBatchNodeTextTop1->increaseAtlasCapacity(batchNodes->stringAtIndex(0x2C)->intValue());
			m_pBatchNodeAddTextTop1->increaseAtlasCapacity(batchNodes->stringAtIndex(0x2D)->intValue());
			m_pBatchNodeText->increaseAtlasCapacity(batchNodes->stringAtIndex(0x2E)->intValue());
			m_pBatchNodeAddText->increaseAtlasCapacity(batchNodes->stringAtIndex(0x2F)->intValue());
			m_pBatchNodeTextBot2->increaseAtlasCapacity(batchNodes->stringAtIndex(0x30)->intValue());
			m_pBatchNodeAddTextBot2->increaseAtlasCapacity(batchNodes->stringAtIndex(0x31)->intValue());
			m_pBatchNodeTextBot3->increaseAtlasCapacity(batchNodes->stringAtIndex(0x32)->intValue());
			m_pBatchNodeAddTextBot3->increaseAtlasCapacity(batchNodes->stringAtIndex(0x33)->intValue());
			m_pBatchNodeTextBot4->increaseAtlasCapacity(batchNodes->stringAtIndex(0x34)->intValue());
			m_pBatchNodeAddTextBot4->increaseAtlasCapacity(batchNodes->stringAtIndex(0x35)->intValue());
			m_pEffectBatchNodeAddTop4->increaseAtlasCapacity(batchNodes->stringAtIndex(0x36)->intValue());
		}
	}
	else
	{
		//1.9
		updateLegacyLayerCapacity(
			batchNodes->stringAtIndex(0x0)->intValue(),
			batchNodes->stringAtIndex(0x1)->intValue(),
			batchNodes->stringAtIndex(0x2)->intValue(),
			batchNodes->stringAtIndex(0x3)->intValue()
		);
	}
}

void GJBaseGameLayer::createTextLayers()
{
	GameManager* GM = GameManager::sharedState();
	cocos2d::CCTexture2D* texture = cocos2d::CCTextureCache::sharedTextureCache()->addImage(GM->getFontTexture(GM->m_nFontID), false);
	cocos2d::ccBlendFunc blendFunc = { GL_SRC_ALPHA, GL_ONE };

	m_pBatchNodeTextTop3 = cocos2d::CCSpriteBatchNode::createWithTexture(texture);
	m_pObjectLayer->addChild(m_pBatchNodeTextTop3, 21);

	m_pBatchNodeTextAddTop3 = cocos2d::CCSpriteBatchNode::createWithTexture(texture);
	m_pBatchNodeTextAddTop3->setBlendFunc(blendFunc);
	m_pObjectLayer->addChild(m_pBatchNodeTextAddTop3, 22);

	m_pBatchNodeTextTop2 = cocos2d::CCSpriteBatchNode::createWithTexture(texture);
	m_pObjectLayer->addChild(m_pBatchNodeTextTop2, 13);

	m_pBatchNodeTextAddTop2 = cocos2d::CCSpriteBatchNode::createWithTexture(texture);
	m_pBatchNodeTextAddTop2->setBlendFunc(blendFunc);
	m_pObjectLayer->addChild(m_pBatchNodeTextAddTop2, 14);

	m_pBatchNodeTextTop1 = cocos2d::CCSpriteBatchNode::createWithTexture(texture);
	m_pObjectLayer->addChild(m_pBatchNodeTextTop1, 6);

	m_pBatchNodeTextAddTop1 = cocos2d::CCSpriteBatchNode::createWithTexture(texture);
	m_pBatchNodeTextAddTop1->setBlendFunc(blendFunc);
	m_pObjectLayer->addChild(m_pBatchNodeTextAddTop1, 7);

	m_pBatchNodeText = cocos2d::CCSpriteBatchNode::createWithTexture(texture);
	m_pObjectLayer->addChild(m_pBatchNodeText, -5);

	m_pBatchNodeAddText = cocos2d::CCSpriteBatchNode::createWithTexture(texture);
	m_pBatchNodeAddText->setBlendFunc(blendFunc);
	m_pObjectLayer->addChild(m_pBatchNodeAddText, -5);

	m_pBatchNodeTextBot2 = cocos2d::CCSpriteBatchNode::createWithTexture(texture);
	m_pObjectLayer->addChild(m_pBatchNodeTextBot2, -12);

	m_pBatchNodeAddTextBot2 = cocos2d::CCSpriteBatchNode::createWithTexture(texture);
	m_pBatchNodeAddTextBot2->setBlendFunc(blendFunc);
	m_pObjectLayer->addChild(m_pBatchNodeAddTextBot2, -11);

	m_pBatchNodeTextBot3 = cocos2d::CCSpriteBatchNode::createWithTexture(texture);
	m_pObjectLayer->addChild(m_pBatchNodeTextBot3, -19);

	m_pBatchNodeAddTextBot3 = cocos2d::CCSpriteBatchNode::createWithTexture(texture);
	m_pBatchNodeAddTextBot3->setBlendFunc(blendFunc);
	m_pObjectLayer->addChild(m_pBatchNodeAddTextBot3, -18);

	m_pBatchNodeTextBot4 = cocos2d::CCSpriteBatchNode::createWithTexture(texture);
	m_pObjectLayer->addChild(m_pBatchNodeTextBot4, -26);

	m_pBatchNodeAddTextBot4 = cocos2d::CCSpriteBatchNode::createWithTexture(texture);
	m_pBatchNodeAddTextBot4->setBlendFunc(blendFunc);
	m_pObjectLayer->addChild(m_pBatchNodeAddTextBot4, -25);
}

void GJBaseGameLayer::setupLayers()
{
	cocos2d::CCTextureCache* textureCache = cocos2d::CCTextureCache::sharedTextureCache();
	cocos2d::CCTexture2D* gSheet1 = textureCache->addImage("GJ_GameSheet.png", false);
	cocos2d::CCTexture2D* gSheet2 = textureCache->addImage("GJ_GameSheet02.png", false);
	cocos2d::CCTexture2D* gSheetGlow = textureCache->addImage("GameSheetGlow.png", false);
	cocos2d::CCTexture2D* gSheetFire = textureCache->addImage("FireSheet_01.png", false);
	cocos2d::ccBlendFunc blendFunc = { GL_SRC_ALPHA, GL_ONE };

	m_pObjectLayer = cocos2d::CCLayer::create();
	this->addChild(m_pObjectLayer, 1);

	m_pDisabledGroupsDictMaybe = cocos2d::CCDictionary::create();
	m_pDisabledGroupsDictMaybe->retain();

	m_pBatchNodeAddTop2 = cocos2d::CCSpriteBatchNode::createWithTexture(gSheet1);
	m_pBatchNodeAddTop2->setBlendFunc(blendFunc);
	m_pObjectLayer->addChild(m_pBatchNodeAddTop2, 16);
	m_pBatchNodeAddTop2->setTag(1001);
	m_pBatchNodeArray->addObject(m_pBatchNodeAddTop2);

	m_pBatchNode = cocos2d::CCSpriteBatchNode::createWithTexture(gSheet1);
	m_pObjectLayer->addChild(m_pBatchNode, 10);
	m_pBatchNode->setTag(1002);
	m_pBatchNodeArray->addObject(m_pBatchNode);

	m_pBatchNodeAdd = cocos2d::CCSpriteBatchNode::createWithTexture(gSheet1);
	m_pBatchNodeAdd->setBlendFunc(blendFunc);
	m_pObjectLayer->addChild(m_pBatchNodeAdd, 9);
	m_pBatchNodeAdd->setTag(1004);
	m_pBatchNodeArray->addObject(m_pBatchNodeAdd);

	m_pBatchNodePlayer = cocos2d::CCSpriteBatchNode::createWithTexture(gSheet2);
	m_pObjectLayer->addChild(m_pBatchNodePlayer, 3);
	m_pBatchNodePlayer->setTag(1003);
	m_pBatchNodeArray->addObject(m_pBatchNodePlayer);

	m_pBatchNodeAddPlayer = cocos2d::CCSpriteBatchNode::createWithTexture(gSheet1);
	m_pBatchNodeAddPlayer->setBlendFunc(blendFunc);
	m_pObjectLayer->addChild(m_pBatchNodeAddPlayer, 2);
	m_pBatchNodeAddPlayer->setTag(1008);
	m_pBatchNodeArray->addObject(m_pBatchNodeAddPlayer);

	m_pBatchNodePlayerGlow = cocos2d::CCSpriteBatchNode::createWithTexture(gSheetGlow);
	m_pBatchNodePlayerGlow->setBlendFunc(blendFunc);
	m_pObjectLayer->addChild(m_pBatchNodePlayerGlow, 2);
	m_pBatchNodeArray->addObject(m_pBatchNodePlayerGlow);

	m_pBatchNodeAddMid = cocos2d::CCSpriteBatchNode::createWithTexture(gSheet1);
	m_pBatchNodeAddMid->setBlendFunc(blendFunc);
	m_pObjectLayer->addChild(m_pBatchNodeAddMid, 1);
	m_pBatchNodeAddMid->setTag(1009);
	m_pBatchNodeArray->addObject(m_pBatchNodeAddMid);

	m_pBatchNodeBot = cocos2d::CCSpriteBatchNode::createWithTexture(gSheet1);
	m_pObjectLayer->addChild(m_pBatchNodeBot, -1);
	m_pBatchNodeBot->setTag(1005);
	m_pBatchNodeArray->addObject(m_pBatchNodeBot);

	m_pBatchNodeAddBot = cocos2d::CCSpriteBatchNode::createWithTexture(gSheet1);
	m_pBatchNodeAddBot->setBlendFunc(blendFunc);
	m_pObjectLayer->addChild(m_pBatchNodeAddBot, -2);
	m_pBatchNodeAddBot->setTag(1006);
	m_pBatchNodeArray->addObject(m_pBatchNodeAddBot);

	m_pEffectBatchNode = cocos2d::CCSpriteBatchNode::createWithTexture(gSheetFire);
	m_pObjectLayer->addChild(m_pEffectBatchNode, -6);
	m_pBatchNodeArray->addObject(m_pEffectBatchNode);

	m_pEffectBatchNodeAdd = cocos2d::CCSpriteBatchNode::createWithTexture(gSheet1);
	m_pEffectBatchNodeAdd->setBlendFunc(blendFunc);
	m_pObjectLayer->addChild(m_pEffectBatchNodeAdd, -7);
	m_pBatchNodeArray->addObject(m_pEffectBatchNodeAdd);

	m_pBatchNodeBot2 = cocos2d::CCSpriteBatchNode::createWithTexture(gSheet1);
	m_pObjectLayer->addChild(m_pBatchNodeBot2, -8);
	m_pBatchNodeBot2->setTag(1007);
	m_pBatchNodeArray->addObject(m_pBatchNodeBot2);

	m_pBatchNodeAddBot2 = cocos2d::CCSpriteBatchNode::createWithTexture(gSheet1);
	m_pBatchNodeAddBot2->setBlendFunc(blendFunc);
	m_pObjectLayer->addChild(m_pBatchNodeAddBot2, -9);
	m_pBatchNodeAddBot2->setTag(1009);
	m_pBatchNodeArray->addObject(m_pBatchNodeAddBot2);

	//will finish the other 26 batch nodes later
}