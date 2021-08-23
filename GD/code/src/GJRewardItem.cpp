#include "includes.h"

GJRewardItem::GJRewardItem()
{
    m_nChestID = 0;
    m_nTimeRemaining = 0;
    m_eRewardType = GJRewardType::kGJRewardTypeUnknown;
    m_pRewardObjects = NULL;
    m_bUnk = false;
}

bool GJRewardItem::canEncode()
{
    return true;
}

void GJRewardItem::encodeWithCoder(DS_Dictionary *_dict)
{
    _dict->setIntegerForKey("kCEK", CoderKey::kCoderKeyRewardItem);
    _dict->setIntegerForKey("1", m_nChestID);
    _dict->setIntegerForKey("2", m_eRewardType);
    _dict->setArrayForKey("3", m_pRewardObjects);
}

void GJRewardItem::setObjects(cocos2d::CCArray *_rewardObjects)
{
    if (m_pRewardObjects != _rewardObjects)
    {
        if (_rewardObjects)
            _rewardObjects->retain();

        if (m_pRewardObjects)
            m_pRewardObjects->release();

        m_pRewardObjects = _rewardObjects;
    }
}

bool GJRewardItem::init(int _chestID, int _timeRemaining, std::string _rewardString)
{
    int ShardsTotal, bonusItem;
    m_nChestID = _chestID;
    m_nTimeRemaining = _timeRemaining;
    cocos2d::CCArray *rewards = RobertFuncs::split(_rewardString, ",");

    if (rewards->count() > 3)
    {

        int orbs = rewards->stringAtIndex(0)->intValue();
        int diamonds = rewards->stringAtIndex(1)->intValue();
        int shard = rewards->stringAtIndex(2)->intValue();
        int bonus = rewards->stringAtIndex(3)->intValue();

        if (shard == bonus)
        {
            ShardsTotal = 2;
            bonusItem = 0;
        }
        else
            ShardsTotal = 1;

        cocos2d::CCArray *rewardObjects = cocos2d::CCArray::create();

        if (orbs > 0)
        {
            GJRewardObject *orbObj = GJRewardObject::create(SpecialRewardItem::kSpecialRewardItemOrbs, orbs, 0);
            rewardObjects->addObject(orbObj);
        }
        if (diamonds > 0)
        {
            GJRewardObject *diamondObj = GJRewardObject::create(SpecialRewardItem::kSpecialRewardItemDiamonds, diamonds, 0);
            rewardObjects->addObject(diamondObj);
        }
        if (shard)
        {
            GJRewardObject *shardObj = GJRewardObject::create((SpecialRewardItem)shard, ShardsTotal, 0);
            rewardObjects->addObject(shardObj);
        }
        if (bonus)
        {
            GJRewardObject *bonusObj = GJRewardObject::create((SpecialRewardItem)bonusItem, 1, 0);
            rewardObjects->addObject(bonusObj);
        }

        if (rewardObjects->count())
            setObjects(rewardObjects);
    }
}