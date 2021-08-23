#include "../headers/GJRewardObject.h"

GJRewardObject::GJRewardObject()
{
}

bool GJRewardObject::canEncode()
{
    return true;
}

void GJRewardObject::encodeWithCoder(DS_Dictionary *_DSDictionary)
{
    _DSDictionary->setIntegerForKey("kCEK", 9);
    _DSDictionary->setIntegerForKey("1", m_eSpecialRewardItem);
    _DSDictionary->setIntegerForKey("2", m_nItemID);
    _DSDictionary->setIntegerForKey("3", m_nTotal);
    _DSDictionary->setIntegerForKey("4", m_eUnlockType);
}

bool GJRewardObject::init(SpecialRewardItem _specialRewardItem, int _total, int _itemID)
{
    m_eSpecialRewardItem = _specialRewardItem;
    m_nItemID = _itemID;
    m_nTotal = _total;
    return true;
}

GJRewardObject *GJRewardObject::create(SpecialRewardItem _specialRewardItem, int _total, int _itemID)
{
    auto pRet = new GJRewardObject;

    if (pRet && pRet->init(_specialRewardItem, _total, _itemID))
    {
        pRet->autorelease();
        return pRet;
    }

    CC_SAFE_DELETE(pRet);
    return nullptr;
}

GJRewardObject *GJRewardObject::createItemUnlock(ItemType _itemType, int _itemID)
{
    GJRewardObject *reward = GJRewardObject::create(SpecialRewardItem::kSpecialRewardItemCustomItem, 1, _itemID);
    reward->m_eUnlockType = _itemType;
    return reward;
}

GJRewardObject *GJRewardObject::create()
{
    return GJRewardObject::create(SpecialRewardItem::kSpecialRewardItemUnknown, 0, 0);
}

bool GJRewardObject::isSpecialType()
{
    return m_eSpecialRewardItem <= 6;
}

void GJRewardObject::dataLoaded(DS_Dictionary *_DSDictionary)
{
    m_eSpecialRewardItem = (SpecialRewardItem)_DSDictionary->getIntegerForKey("1");
    m_nItemID = _DSDictionary->getIntegerForKey("2");
    m_nTotal = _DSDictionary->getIntegerForKey("3");
    m_eUnlockType = (ItemType)_DSDictionary->getIntegerForKey("4");
}

GJRewardObject *GJRewardObject::createWithCoder(DS_Dictionary *_DSDictionary)
{
    GJRewardObject *reward = GJRewardObject::create();
    reward->dataLoaded(_DSDictionary);
    return reward;
}