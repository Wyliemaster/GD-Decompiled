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

GJRewardItem *GJRewardItem::create(int _chestID, int _timeRemaining, char *_rewardString)
{
    auto pRet = new GJRewardItem;

    if (pRet && pRet->init(_chestID, _timeRemaining, _rewardString))
    {
        pRet->autorelease();
        return pRet;
    }

    CC_SAFE_DELETE(pRet);
    return nullptr;
}

GJRewardItem *GJRewardItem::create()
{
    return GJRewardItem::create(0, 0, "");
}

GJRewardItem *GJRewardItem::createWithObjects(GJRewardType _rewardType, cocos2d::CCArray *_rewardObjects)
{
    GJRewardItem *rewardItem = GJRewardItem::create();

    rewardItem->m_eRewardType = _rewardType;
    rewardItem->setObjects(_rewardObjects);
    return rewardItem;
}

GJRewardItem *GJRewardItem::createSpecial(GJRewardType _rewardType, int _orbTotal, int _diamondTotal, SpecialRewardItem _optionalItemType, int optionItemTotal, SpecialRewardItem _optionalItemType2, int _optionalItemTotal2, ItemType _itemType, int _itemUnlockID)
{
    bool itemTypeExists = false;
    cocos2d::CCArray *rewardObjects = cocos2d::CCArray::create();

    if (_orbTotal > 0)
    {
        GJRewardObject *orbs = GJRewardObject::create(SpecialRewardItem::kSpecialRewardItemOrbs, _orbTotal, 0);
        rewardObjects->addObject(orbs);
    }

    if (_diamondTotal > 0)
    {
        GJRewardObject *diamonds = GJRewardObject::create(SpecialRewardItem::kSpecialRewardItemDiamonds, _diamondTotal, 0);
        rewardObjects->addObject(diamonds);
    }

    if (_optionalItemType)
    {
        GJRewardObject *optional1 = GJRewardObject::create(_optionalItemType, optionItemTotal, 0);
        rewardObjects->addObject(optional1);
    }

    if (_optionalItemType2)
    {
        GJRewardObject *optional2 = GJRewardObject::create(_optionalItemType2, _optionalItemTotal2, 0);
        rewardObjects->addObject(optional2);
    }

    if (_itemUnlockID > 0)
        itemTypeExists = _itemType > 0;

    if (itemTypeExists)
    {
        GJRewardObject *itemUnlock = GJRewardObject::createItemUnlock(_itemType, _itemUnlockID);
        rewardObjects->addObject(itemUnlock);
    }

    return GJRewardItem::createWithObjects(_rewardType, rewardObjects);
}

GJRewardItem *GJRewardItem::createWithObject(GJRewardType _rewardType, GJRewardObject *_rewardObject)
{

    cocos2d::CCArray *rewardObjects = cocos2d::CCArray::createWithObject(_rewardObject);
    return GJRewardItem::createWithObjects(_rewardType, rewardObjects);
}

const char *GJRewardItem::rewardItemToStat(SpecialRewardItem _rewardItem)
{
    const char *statString = "";
    switch (_rewardItem)
    {
    case SpecialRewardItem::kSpecialRewardItemFireShard:
        statString = "18";
        break;
    case SpecialRewardItem::kSpecialRewardItemIceShard:
        statString = "19";
        break;
    case SpecialRewardItem::kSpecialRewardItemPoisonShard:
        statString = "17";
        break;
    case SpecialRewardItem::kSpecialRewardItemShadowShard:
        statString = "16";
        break;
    case SpecialRewardItem::kSpecialRewardItemLavaShard:
        statString = "20";
        break;
    case SpecialRewardItem::kSpecialRewardItemBonusKey:
        statString = "21";
        break;
    default:
        break;
    }
    return statString;
}

bool GJRewardItem::isShardType(SpecialRewardItem _specialItem)
{
    return _specialItem <= 5;
}

int GJRewardItem::getNextShardType(SpecialRewardItem _specialRewardItem)
{
    int shard = 0;
    if (_specialRewardItem < 6)
        shard = Globals::ShardTypes[_specialRewardItem - 1];

    return shard;
}