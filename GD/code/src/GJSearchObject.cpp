#include "includes.h"
/* Will fix this later... */
#include "GJSearchObject.h"

static GJSearchObject *GJSearchObject::create(
    SearchType searchType, std::string searchQuery, std::string difficulty,
    std::string length, int page, bool star, bool uncompleted, bool featured,
    int songID, bool original, bool twoPlayer, bool customSong, bool songFilter,
    bool noStar, bool coins, bool epic, bool legendary, bool mythic,
    bool onlyCompleted, int demonFilter, int folder, int searchMode)
{

    GJSearchObject *searchObject = new GJSearchObject;

    if (searchObject->init(searchType, searchQuery, difficulty,
                           length, page, star, uncompleted, featured, songID, original, twoPlayer,
                           customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter,
                           folder, searchMode))
        searchObject->autorelease();
    return searchObject;

    CC_SAFE_DELETE(searchObject);
    return nullptr;
}
static GJSearchObject *GJSearchObject::create(SearchType searchType, std::string searchQuery)
{
    return create(searchType, searchQuery, "-", "-", 0, false, false, false, 0, false, false, false, false, false, false, false, false, false, false, 0, 0, 0);
}

static GJSearchObject *GJSearchObject::create(SearchType searchType)
{
    return create(searchType, "", "-", "-", 0, false, false, false, 0, false, false, false, false, false, false, false, false, false, false, 0, 0, 0);
}

const char *GJSearchObject::getKey()
{
    return getSearchKey(m_seachType, m_searchQuery, m_difficulty,
                        m_length, m_page, m_starFilter,
                        m_searchIsOverlay, m_original, m_songID,
                        m_originalFilter, m_twoPlayerFilter,
                        m_customSong, m_songFilter, m_noStarFilter,
                        m_coins, m_epic, m_legendary,
                        m_mythic, m_onlyCompleted, m_demonFilter,
                        m_folder, m_searchMode);
}

const char *GJSearchObject::getNextPageKey()
{
    return getSearchKey(m_seachType, m_searchQuery, m_difficulty,
                        m_length, m_page + 1, m_starFilter,
                        m_searchIsOverlay, m_original, m_songID,
                        m_originalFilter, m_twoPlayerFilter,
                        m_customSong, m_songFilter, m_noStarFilter,
                        m_coins, m_epic, m_legendary,
                        m_mythic, m_onlyCompleted, m_demonFilter,
                        m_folder, m_searchMode);
}

GJSearchObject *GJSearchObject::getNextPageObject()
{
    getPageObject(m_page + 1);
    return;
}

GJSearchObject *GJSearchObject::getPageObject(int page)
{

    GJSearchObject *searchObject = create(m_searchType, m_searchQuery, m_difficulty,
                                          m_length, page, m_starFilter, m_searchIsOverlay,
                                          m_original, m_songID, m_originalFilter,
                                          m_twoPlayerFilter, m_customSong,
                                          m_songFilter, m_noStarFilter, m_coins,
                                          m_epic, m_legendary, m_mythic,
                                          m_onlyCompleted, m_demonFilter, m_folder,
                                          m_searchMode);
    searchObject->m_total = m_total;
    return searchObject;
}

GJSearchObject *GJSearchObject::getPrevPageObject()
{
    return getPageObject((m_page < 1) ? 0 : m_page - 1);
}

static const char *GJSearchObject::getSearchKey(
    SearchType searchType, std::string searchQuery, std::string difficulty, std::string length,
    int page, bool star, bool uncompleted, bool featured, int songID, bool original, bool twoPlayer,
    bool customSong, bool songFilter, bool noStar, bool coins, bool epic, bool legendary, bool mythic,
    bool onlyCompleted, int demonFilter, int folder, int searchMode)
{

    /* TODO: Translate Enums... */
    if (searchType == 0xe)
    {
        return cocos2d::CCString::createWithFormat("%i_%s_%i", 0xe, searchQuery, page)->getCString();
    }
    return cocos2d::CCString::createWithFormat(
               "%i_%s_%s_%s_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i",
               searchType, searchQuery, difficulty,
               length, page, star, uncompleted, featured,
               songID, original, twoPlayer, customSong, songFilter,
               noStar, coins, epic, legendary, mythic,
               onlyCompleted, demonFilter, folder, searchMode)
        ->getCString();
};

bool GJSearchObject::init(
    SearchType searchType, std::string searchQuery, std::string difficulty, std::string length,
    int page, bool star, bool uncompleted, bool featured, int songID, bool original, bool twoPlayer,
    bool customSong, bool songFilter, bool noStar, bool coins, bool epic, bool legendary, bool mythic,
    bool onlyCompleted, int demonFilter, int folder, int searchMode)
{
    m_seachType = searchType;
    m_searchQuery = searchQuery;
    m_difficulty = difficulty;
    m_length = length;
    m_page = page;
    m_starFilter = star;
    m_searchIsOverlay = uncompleted;
    m_original = featured;
    m_songID = songID;
    m_originalFilter = original;
    m_twoPlayerFilter = twoPlayer;
    m_customSong = customSong;
    m_songFilter = songFilter;
    m_noStarFilter = noStar;
    m_coins = coins;
    m_epic = epic;
    m_mythic = mythic;
    m_legendary = legendary;
    m_onlyCompleted = onlyCompleted;
    m_demonFilter = demonFilter;
    m_folder = folder;
    m_searchMode = searchMode;
    return true;
}

bool GJSearchObject::isLevelSearchObject()
{
    if (m_seachType < 0xb){
        if ((m_searchType < 9) && (m_searchType != 5)){
            return this->m_searchMode == 0;
        }
    }
    else if ((m_searchType != 0xe) && ((m_searchType < 0xe || (1 < m_searchType - 0x65))))
    {
        return this->m_searchMode == 0;
    }
    return false;
}

