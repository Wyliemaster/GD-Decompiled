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