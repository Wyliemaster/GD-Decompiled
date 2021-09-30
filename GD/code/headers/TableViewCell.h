#include "includes.h"

class CCIndexPath;
class TableViewCell : public cocos2d::CCLayer
{
	DWORD dwordEC;
	DWORD dwordF0;
	CCIndexPath* m_pIndexPath;
	DWORD dwordF8;
	DWORD dwordFC;
	int gap100;
	int field_134;
	int field_138;
	int field_13C;
	int field_140;
	int field_144;
	int field_148;
	bool field_14C;
	std::string m_sKey;
	float m_fTableHeight;
	float m_fCellHeight;
	cocos2d::CCLayerColor* m_pColourLayer;
	cocos2d::CCLayer* m_pLayer;
};