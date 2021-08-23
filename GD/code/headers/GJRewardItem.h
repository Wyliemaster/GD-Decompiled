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
    static GJRewardItem *create(int _chestID, int _timeRemaining, char *_rewardString);
    static GJRewardItem *create();
    static GJRewardItem *createWithObjects(GJRewardType _rewardType, cocos2d::CCArray *_rewardObjects);
    static GJRewardItem *createSpecial(GJRewardType _rewardType, int _orbTotal, int _diamondTotal, SpecialRewardItem _optionalItemType, int optionItemTotal, SpecialRewardItem _optionalItemType2, int _optionalItemTotal2, ItemType _itemType, int _itemUnlockID);
    static GJRewardItem *createWithObject(GJRewardType _rewardType, GJRewardObject *_rewardObject);
    const char *rewardItemToStat(SpecialRewardItem _rewardItem);
    bool isShardType(SpecialRewardItem _specialItem);
    int getNextShardType(SpecialRewardItem _specialRewardItem);
};