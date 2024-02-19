#ifndef __GJSEARCHOBJECT_H__
#define __GJSEARCHOBJECT_H__

#include "includes.h"

typedef int SearchType;

// TODO: Make SearchType Enum...
// enum SearchType {

// };


class GJSearchObject : public cocos2d::CCNode
{
    SearchType m_seachType;
    std::string m_searchQuery;
    std::string m_difficulty;
    std::string m_length;
    int m_page;
    bool m_starFilter;
    bool m_noStarFilter;
    int m_total;
    bool m_featuredFilter;
    bool m_uncompletedFilter;
    bool m_searchIsOverlay;
    bool m_onlyCompleted;
    bool m_original;
    bool m_originalFilter;
    bool m_twoPlayerFilter;
    bool m_coins;
    bool m_epic;
    bool m_legendary;
    bool m_mythic;
    int m_demonFilter;
    int m_folder;
    int m_songID;
    bool  m_customSong;
    bool  m_songFilter;
    int m_searchMode;

	static GJSearchObject* create(SearchType searchType, std::string searchQuery, std::string difficulty, std::string length, int page, bool star, bool uncompleted, bool featured, int songID, bool original, bool twoPlayer, bool customSong, bool songFilter, bool noStar, bool coins, bool epic, bool legendary, bool mythic, bool onlyCompleted, int demonFilter, int folder, int searchMode);
	static GJSearchObject* create(SearchType searchType, std::string searchQuery);
	static GJSearchObject* create(SearchType searchType);
	static GJSearchObject* createFromKey(char const* key);

	bool init(
		SearchType searchType, std::string searchQuery, std::string difficulty, std::string length, 
		int page, bool star, bool uncompleted, bool featured, int songID, bool original, bool twoPlayer, 
		bool customSong, bool songFilter, bool noStar, bool coins, bool epic, bool legendary, bool mythic, 
		bool onlyCompleted, int demonFilter, int folder, int searchMode
	);

	const char * getSearchKey (SearchType searchType, std::string searchQuery, std::string difficulty, std::string length, int page, bool star, bool uncompleted, bool featured, int songID, bool original, bool twoPlayer, bool customSong, bool songFilter, bool noStar, bool coins, bool epic, bool legendary, bool mythic, bool onlyCompleted, int demonFilter, int folder, int searchMode);
	GJSearchObject* getPageObject(int page);
	GJSearchObject * getPrevPageObject();
	static GJSearchObject * createFromKey(char *key);
	const char* getKey();
	bool isLevelSearchObject();
};

#endif // __GJSEARCHOBJECT_H__
