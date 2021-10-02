#include "includes.h"

class GJSearchObject : public cocos2d::CCNode
{
	GJSearchType m_eSearchType;
	std::string m_sSearchQuery;
	std::string m_sDifficulty;
	std::string m_sLength;
	int m_nPage;
	bool m_bStarFilter;
	bool m_bNoStarFilter;
	int m_nTotal;
	bool m_bUncompletedFilter;
	bool m_bCompletedFilter;
	bool m_bFeaturedFilter;
	bool m_bOriginalFilter;
	bool m_bTwoPlayerFilter;
	bool m_bCoinsFilter;
	bool m_bEpicFilter;
	GJDifficulty m_eDemonFilter;
	int m_nFolderNumber;
	int m_nSongID;
	bool m_bCustomSongFilter;
	bool m_bSongFilter;
};
