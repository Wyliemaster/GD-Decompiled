#include <cocos2d.h>

enum GJRewardType
{
    kGJRewardTypeUnknown = 0x0,
    kGJRewardTypeSmall = 0x1,
    kGJRewardTypeLarge = 0x2,
};

class GJRewardItem : public cocos2d::CCObject
{
public:
    int m_nChestID;
    int m_nTimeRemaining;
    GJRewardType m_eRewardType;
    cocos2d::CCArray *m_pRewardObjects;
    bool m_bUnk;

    GJRewardItem();
    virtual bool canEncode();
    virtual void encodeWithCoder(DS_Dictionary *_dict);
    void setObjects(cocos2d::CCArray *_rewardObjects);
    bool init(int _chestID, int _timeRemaining, std::string _rewardString);
};