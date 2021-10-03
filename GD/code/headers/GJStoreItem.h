#include "includes.h"

class GJStoreItem : public cocos2d::CCNode
{
	int m_nListingIDSeed;
	int m_nListingIDRand;
	int m_nListingID;
	int m_nItemIDSeed;
	int m_nItemIDRand;
	int m_nItemID;
	int m_nItemTypeSeed;
	int m_nItemTypeRand;
	ItemType m_eItemType;
	int m_nCostSeed;
	int m_nCostRand;
	int m_nCost;
	ShopType m_eShopType;
};
