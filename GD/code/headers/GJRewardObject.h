#include "includes.h"

enum SpecialRewardItem
{
    kSpecialRewardItemUnknown = 0x0,
    kSpecialRewardItemFireShard = 0x1,
    kSpecialRewardItemIceShard = 0x2,
    kSpecialRewardItemPoisonShard = 0x3,
    kSpecialRewardItemShadowShard = 0x4,
    kSpecialRewardItemLavaShard = 0x5,
    kSpecialRewardItemBonusKey = 0x6,
    kSpecialRewardItemOrbs = 0x7,
    kSpecialRewardItemDiamonds = 0x8,
    kSpecialRewardItemCustomItem = 0x9,
};

enum ItemType
{
    kItemTypeCube = 0x1,
    kItemTypeCol1 = 0x2,
    kItemTypeCol2 = 0x3,
    kItemTypeShip = 0x4,
    kItemTypeBall = 0x5,
    kItemTypeBird = 0x6,
    kItemTypeDart = 0x7,
    kItemTypeRobot = 0x8,
    kItemTypeSpider = 0x9,
    kItemTypeStreak = 0xA,
    kItemTypeDeath = 0xB,
    kItemTypeGJItem = 0xC,
};

class GJRewardObject : public cocos2d::CCObject
{
public:
    SpecialRewardItem m_eSpecialRewardItem;
    ItemType m_eUnlockType;
    int m_nItemID;
    int m_nTotal;

    GJRewardObject();
    virtual bool canEncode();
    virtual void encodeWithCoder(DS_Dictionary *_DSDictionary);
    bool init(SpecialRewardItem _specialRewardItem, int _total, int _itemID);
    static GJRewardObject *create(SpecialRewardItem _specialRewardItem, int _total, int _itemID);
    static GJRewardObject *createItemUnlock(ItemType _itemType, int _itemID);
    static GJRewardObject *create();
    bool isSpecialType();
    void dataLoaded(DS_Dictionary *_DSDictionary);
    GJRewardObject *createWithCoder(DS_Dictionary *_DSDictionary);
};
