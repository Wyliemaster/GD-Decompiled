#include <cocos2d>

GJRewardObject *__fastcall GJRewardObject::create(int itemType, int rewardAmount, int customItemID)
{
    GJRewardObject = operator new(0x30u);                           //memory allocation
    cocos2d::CCObject::CCObject(GJRewardObject);                    //create cocos object
    GJRewardObject->GJRewardObjectVftable = 0x86F628;               //this pointer now stores the virtual function table location
    if (GJRewardObject->init(itemType, rewardAmount, customItemID)) //if init returns true
    {
        cocos2d::CCObject::autorelease(GJRewardObject); //Free memory
    }
    else
    {
        RewardObject = GJRewardObject->GJRewardObjectVftable; //give rewardObject VFtable pointer
        GJRewardObjectValue = GJRewardObject;                 //transfers the struct to GJRewardObjectValue
        GJRewardObject = 0;
        RewardObject->encodeToCoder(GJRewardObjectValue); //sends values to encodeToCoder so they get put in GJRewardObject
    }
    return GJRewardObject;
}

