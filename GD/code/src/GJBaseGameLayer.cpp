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