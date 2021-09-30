#include "includes.h"

class TableViewDelegate;
class TableViewDataSource;
class TableView;
class TableViewCell;

// thanks fod for the enum :) will go through and give better names later
enum BoomListType {
	kBoomListTypeDefault = 0x0,
	kBoomListTypeUser = 0x2,
	kBoomListTypeStats = 0x3,
	kBoomListTypeAchievement = 0x4,
	kBoomListTypeLevelOnline = 0x5,
	kBoomListTypeLevelLocal = 0x6,
	kBoomListTypeComment = 0x7,
	kBoomListTypeComment2 = 0x8,
	kBoomListTypeSong = 0xb,
	kBoomListTypeScore = 0xc,
	kBoomListTypeMapPack = 0xd,
	kBoomListTypeCustomSong = 0xe,
	kBoomListTypeComment3 = 0xf,
	kBoomListTypeUser2 = 0x10,
	kBoomListTypeRequest = 0x11,
	kBoomListTypeMessage = 0x12,
	kBoomListTypeLevelScore = 0x13,
	kBoomListTypeArtist = 0x14,
};

class BoomListView : public cocos2d::CCLayer, public TableViewDelegate, public TableViewDataSource
{
	TableView* m_pTableView;
	cocos2d::CCArray* m_pRowsInSection;
	BoomListType m_eCellType;
	cocos2d::CCSize m_obTable;
	float m_fCellHeight;
	int m_nIdx;
};