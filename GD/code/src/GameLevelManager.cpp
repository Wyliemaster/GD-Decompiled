include "../headers/includes.h"
#include <cocos-ext.h>
#include "GameToolbox.h"



/* In other words this means is the download we have running?
 This is very simillar to that of a thread_lock or mutex - Calloc */
bool GameLevelManager::isDLActive(const char *DLKey)
{
    /* TODO try using */
    return (bool)m_pDLObject->objectForKey(DLKey);
}


bool GameLevelManager::isFollowingUser(int ID){
    return (bool)m_pFollowedCreators->objectForKey(cocos2d::CCString::createWithFormat("%i", ID)->getCString());
}

const char* GameLevelManager::getDiffKey (int Diff){
    return cocos2d::CCString::createWithFormat("Diff%i",Diff)->getCString();
}



/* Should be the same as the one for the GJAccountManager They maybe even are the same function who knows...
TODO: (Calloc) Add the Overload Function for addDLToActive...
*/
void GameLevelManager::addDLToActive(const char *_tag)
{
    cocos2d::CCNode *obj = cocos2d::CCNode::create();
    m_pDLObject->setObject(obj, _tag);
}

void GameLevelManager::removeDLFromActive(const char *_tag)
{
    m_pDLObject->removeObjectForKey(_tag);
}

int GameLevelManager::accountIDForUserID(int accountID)
{
    return m_pAccountIDDict->valueForKey(accountID)->intValue();
}

/* TODO: (Calloc) Complete this function */
std::string GameLevelManager::getBasePostString()
{
    auto GM = GameManager::sharedState();

    std::string BasePostString;
    BasePostString += cocos2d::CCString::createWithFormat("gameVersion=%i&binaryVersion=%i&udid=%s&uuid=%i", 22, 0x28, GM->m_sPlayerUDID, GM->m_nChkRand - GM->m_nChkSeed)->getCString();
    /* There is more to this function but I have yet to find all of it out...*/
    return BasePostString;
}

/*
"&userName=%s&levelID=%i&levelName=%s&levelDesc=%s&levelVersion=%i&levelLength=%i&audioTrack=%i&auto=%i&password=%i&original=%i&twoPlayer=%i&songID=%i
&objects=%i&coins=%i& requestedStars=%i&unlisted=%i&wt=%i&wt2=%i&ldm=%i&ts=%i

char*, userName
int levelID,
char* levelName,
char* levelDesc,
int levelVersion,
int levelLength,
int audioTrack,
int auto,
int password,
int original,
int twoPlayer,
int songID,
int objects,
int coins,
int requestedStars,
int unlisted,
int wt,
int wt2,
int ldm,
int ts


char*, int, char*, char*, int , int , int , int , int , int , int , int , int , int , int , int , int , int , int , int

*/

const char *GameLevelManager::getCommentKey(int ID, int page, int mode, CommentKeyType keytype)
{
    /* IT Honstesly should be only one line which is very surprising...*/
    return cocos2d::CCString::createWithFormat("comment_%i_%i_%i_%i", page, mode, keytype, ID)->getCString();
};

const char *GameLevelManager::getLevelKey(int levelID)
{
    return cocos2d::CCString::createWithFormat("%i", levelID)->getCString();
};

int GameLevelManager::accountIDForUserID(int accountID)
{
    return m_pAccountIDDict->valueForKey(accountID)->intValue();
}

void GameLevelManager::cleanupDailyLevels()
{
    auto dailylevelkeys = m_pDailyLevels->allKeys();
    if (dailylevelkeys->count())
    {
        m_pDailyLevels->objectForKey(reinterpret_cast<cocos2d::CCString *> dailylevelkeys->objectAtIndex(dailylevelkeys->count() - 1)->getCString());
    }
}

/* TODO: Fix code as needed in the future... */

void GameLevelManager::getLevelComments(int ID, int page, int total, int mode, CommentKeyType keytype)
{
    const char *key = getCommentKey(ID, page, mode, keytype);
    /* is the same request running for our key? if so do not run... */
    if (!isDLActive((char*)key))
    {
        /* Throw this key into our mutex... */
        addDLToActive(key);
        /* Start our HTTP Request this poststring contains
         * some of our other params like gameVersion, binaryVersion, udid, uuid , accountID , gjp and more... */
        std::string postString = getBasePostString();
        /* Wonder why Robtop wrote in his secret parameter this way? It's not really so secret... */
        const char *secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s", 'W', "mfd", "2893", 'g', 'b', "7")->getCString();
        postString += cocos2d::CCString::createWithFormat("&page=%i&total=%i&secret=%s&mode=%i", page, total, secret, total)->getCString();
        /* set levelID or userID */
        postString.append(keytype == kCommentKeyTypeLevelType ? "&levelID=" : "&userID=");
        /* Add in our userID or levelID */
        postString += cocos2d::CCString::createWithFormat("%i", ID)->getCString();

        int count = GameManager::sharedState()->getGameVariable("0088") ? 10 : 20;
        /* The Settings to make the pages smaller is checked here */
        if (GameManager::sharedState()->getGameVariable("0094"))
            count *= 2;
        std::string endpoint = (keytype == kCommentKeyTypeLevelType) ? "https://www.boomlings.com/database/getGJComments21.php" : "https://www.boomlings.com/database/getGJCommentHistory.php";

        /* prepare for sendoff */
        ProcessHttpRequest(endpoint, postString, key, kGJHttpTypeGetLevelComments);
    }
}

const char *GameLevelManager::getAccountCommentKey(int accountID, int page)
{
    return cocos2d::CCString::createWithFormat("a_%i_%i", accountID, page)->getCString();
}

/* This is the comments made on the user's profile... */
void GameLevelManager::getAccountComments(int accountID, int page, int total)
{
    const char *key = getAccountCommentKey(accountID, page);
    if (!isDLActive(key))
    {
        addDLToActive(key);
        std::string poststr = getBasePostString();
        auto secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s", 'W', "mfd", "2893", 'g', 'b', "7")->getCString();
        poststr += cocos2d::CCString::createWithFormat("&accountID=%i&page=%i&total=%i&secret=%s", accountID, page, total, secret)->getCString();
        ProcessHttpRequest("https://www.boomlings.com/database/getGJAccountComments20.php", poststr, key, kGJHttpTypeGetAccountComments);
    }
}

const char *GameLevelManager::getFriendRequestKey(bool sent, int page)
{
    return cocos2d::CCString::createWithFormat("fReq_%i_%i", (int)sent, page)->getCString();
}

void GameLevelManager::getFriendRequests(bool sent, int page, int total)
{
    const char *key = getFriendRequestKey(sent, page);
    if (!isDLActive())
    {
        addDLToActive(key);
        std::string poststr = getBasePostString();
        auto secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s", 'W', "mfd", "2893", 'g', 'b', "7")->getCString();
        poststr += cocos2d::CCString::createWithFormat("&page=%i&total=%i&secret=%s", page, total, secret)->getCString();
        if (sent)
            poststr += "&getSent=1";
        ProcessHttpRequest("https://www.boomlings.com/database/getGJFriendRequests20.php", poststr, key, kGJHttpTypeGetFriendRequests);
    }
}

bool GameLevelManager::areGauntletsLoaded()
{
    return m_pGauntletLevels->count() > 0;
}

const char *GameLevelManager::getGauntletKey(int key)
{
    return cocos2d::CCString::createWithFormat("%i", key)->getCString();
}

const char *GameLevelManager::getGauntletSearchKey(int searchKey)
{
    return cocos2d::CCString::createWithFormat("gaunlet_%i", searchKey)->getCString();
}

void GameLevelManager::getGauntlets()
{
    if (!isDLActive("get_gauntlets"))
    {
        addDLToActive("get_gauntlets");
        std::string poststr = getBasePostString();
        auto secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s", 'W', "mfd", "2893", 'g', 'b', "7")->getCString();
        poststr += cocos2d::CCString::createWithFormat("&secret=%s&special=1", secret)->getCString();
        ProcessHttpRequest("https://www.boomlings.com/database/getGJGauntlets21.php", poststr, "get_gauntlets", kGJHttpTypeGetGauntlets);
    }
}

/* TODO (Calloc) Change levelType to an enum when it's been figured out, I will let wyliemaster be in charge of figuring that stuff out...*/
void GameLevelManager::getGJDailyLevelState(int levelType)
{
    const char *key;
    if (levelType == 1)
    {
        key = 0xde;
    }
    else if (levelType == 2)
    {
        key = 0xeb;
    }
    else
    {
        key = 0xcc;
    }
    if (!isDLActive(key))
    {
        addDLToActive(key);
        std::string poststr = getBasePostString();
        const char *secert = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s", 'W', "mfd", "2893", 'g', 'b', "7")->getCString();
        poststr += cocos2d::CCString::createWithFormat("&secret=%s&type=%i", secret, levelType);
        ProcessHttpRequest("https://www.boomlings.com/database/getGJDailyLevel.php", poststr, key, kGJHttpTypeGetGJDailyLevelState);
    }
}

const char *GameLevelManager::getUserInfoKey(int targetAccountID)
{
    return cocos2d::CCString::createWithFormat("account_%i", targetAccountID)->getCString();
}

void GameLevelManager::getGJUserInfo(int targetAccountID)
{
    const char *key = getUserInfoKey(targetAccountID);
    if (!isDLActive(key))
    {
        addDLToActive(key);
        std::string postStr = getBasePostString();
        const char *secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s", 'W', "mfd", "2893", 'g', 'b', "7")->getCString();
        postStr += cocos2d::CCString::createWithFormat("&targetAccountID=%i&secret=%s", targetAccountID, secret)->getCString();
        ProcessHttpRequest("https://www.boomlings.com/database/getGJUserInfo20.php", postStr, key, kGJHttpTypeGetGJUserInfo);
    }
}

const char *GameLevelManager::getLenKey(int Len)
{
    return cocos2d::CCString::createWithFormat("Len%i", len)->getCString();
};

void GameLevelManager::getLevelSaveData()
{
    if (!isDLActive("lvl_data"))
    {
        addDLToActive("lvl_data");
        std::string postStr = getBasePostString();
        postStr += "&secret=";
        postStr += cocos2d::CCString::createWithFormat("%c%s%s%c%c%s", 'W', "mfd", "2893", 'g', 'b', "7")->getCString();
        ProcessHttpRequest("https://www.boomlings.com/database/getSaveData.php", postStr, "lvl_data", kGJHttpTypeGetLevelSaveData);
    }
}

const char *GameLevelManager::getMapPackKey(int pack)
{
    return cocos2d::CCString::createWithFormat("pack_%i", pack)->getCString();
}


bool GameLevelManager::hasDownloadedLevel(int levelID){
    return (bool)m_pDownloadedLevels->objectForKey(getLevelKey(levelID));
}

const char *GameLevelManager::getPostCommentsKey(int seconds_left)
{
    return cocos2d::CCString::createWithFormat("c_%i", seconds_left)->getCString();
}

const char *GameLevelManager::getRateStarsKey(int key)
{
    return cocos2d::CCString::createWithFormat("%i", key)->getCString();
}

const char *GameLevelManager::getReportKey(int levelID)
{
    return cocos2d::CCString::createWithFormat("%i", levelID)->getCString();
}

bool GameLevelManager::hasReportedLevel(int levelID)
{
    return (bool)m_pReportedLevels->objectForKey(getReportKey(levelID));
}

void GameLevelManager::reportLevel(int levelID)
{
    if (!hasReportedLevel(levelID))
    {
        markLevelAsReported(levelID);
        std::string postStr = getBasePostString();
        const char *secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s", 'W', "mfd", "2893", 'g', 'b', "7")->getCString();
        postStr += cocos2d::CCString::createWithFormat("levelID=%i&secret=%s", levelID, secret)->getCString();
        const char *key = cocos2d::CCString::createWithFormat("%i", levelID)->getCString();
        ProcessHttpRequest("https://www.boomlings.com/database/reportGJLevel.php", postStr, key, kGJHttpTypeReportLevel);
    }
}

const char *GameLevelManager::getTopArtistsKey(int page)
{
    return cocos2d::CCString::createWithFormat("topArtists_%i", page)->getCString();
}

void GameLevelManager::getTopArtists(int page, int total)
{
    const char *key = getTopArtistsKey(page);
    if (!isDLActive(key))
    {
        addDLToActive(key);
        std::string postStr = getBasePostString();
        const char *secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s", 'W', "mfd", "2893", 'g', 'b', "7")->getCString();
        postStr += cocos2d::CCString::createWithFormat("&page=%i&secret=%s&total=%i", page, secret, total)->getCString();
        ProcessHttpRequest("https://www.boomlings.com/database/getGJTopArtists.php", postStr, key, kGJHttpTypeGetTopArtists);
    }
};

void GameLevelManager::getUserList(UserListType listType)
{
    const char *key;
    if (listType == kUserListTypeGetFriends)
    {
        key = "get_friends";
    }
    else
    {
        key = "get_blocked";
    }
    if (!isDLActive(key))
    {
        addDLToActive(key);
        std::string postStr = getBasePostString();
        const char *secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s", 'W', "mfd", "2893", 'g', 'b', "7")->getCString();
        postStr += cocos2d::CCString::createWithFormat("&type=%i&secret=%s", listType, secret)->getCString();
        ProcessHttpRequest("https://www.boomlings.com/database/getGJUserList20.php", postStr, key, kGJHttpTypeGetUserList);
    }
}

const char *GameLevelManager::getMessagesKey(bool getSent, int page)
{
    return cocos2d::CCString::createWithFormat("messages_%i_%i", (int)getSent, page)->getCString();
}

void GameLevelManager::getUserMessages(bool getSent, int page, int total)
{
    const char *key = getMessagesKey(getSent, page);
    if (!isDLActive(key))
    {
        addDLToActive(key);
        std::string postStr = getBasePostString();
        const char *secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s", 'W', "mfd", "2893", 'g', 'b', "7")->getCString();
        postStr += cocos2d::CCString::createWithFormat("&page=%i&total=%i&secret=%s", page, total, secret)->getCString();
        if (getSent)
            postStr += "&getSent=1";
        ProcessHttpRequest("https://www.boomlings.com/database/getGJMessages20.php", postStr, key, kGJHttpTypeGetUserMessages);
    }
}

void GameLevelManager::getUsers(GJSearchObject *searchObject)
{
    const char *key = searchObject->getKey();
    if (!isDLActive(key))
    {
        addDLToActive(key);
        std::string postStr = getBasePostString();
        const char *secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s", 'W', "mfd", "2893", 'g', 'b', "7")->getCString();
        postStr += cocos2d::CCString::createWithFormat("&str=%s&total=%i&page=%i&secret=%s", searchObject->m_sSearchQuery, searchObject->m_nTotal, searchObject->m_nPage, secret)->getCString();
        ProcessHttpRequest("https://www.boomlings.com/database/getGJUsers20.php", postStr, key, kGJHttpTypeGetUsers);
    }
}

const char *GameLevelManager::getMessageKey(bool param_1, int param_2)
{
    return cocos2d::CCString::createWithFormat("messages_%i_%i", param_1, param_2)->getCString();
}

void GameLevelManager::blockUser(int accountID)
{
    if (0 < accountID)
    {
        /* If the user is now blocked in our blacklist do this...*/
        auto blockedUserKey = cocos2d::CCString::createWithFormat("blockUser_%i", accountID)->getCString();
        if (m_pUnkDict->objectForKey(blockedUserKey) == NULL)
        {
            /* Set the user as being blocked... */
            m_pUnkDict->setObject(cocos2d::CCNode::create(), blockedUserKey);
            std::string postData = getBasePostString();
            auto secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s", 'W', "mfd", "2893", 'g', 'b', "7")->getCString();
            postData += cocos2d::CCString::createWithFormat("&targetAccountID=%i&secret=%s", accountID, secret)->getCString();
            ProcessHttpRequest("https://www.boomlings.com/database/blockGJUser20.php", postStr, blockedUserKey, kGJHttpTypeBlockUser);
        }
    }
}

/* CCHttpClient Info...
_timeoutForRead 0x38
_timeoutForConnect 0x34  NOTE: Robtop has this variable modified to "10" and not "30"...
std::vector<std::string> _headers 0x5c

*/
/* CCHttpRequest Info...
_requestType 0x34 (Looks to have been set to 5 Not Sure what for...)
_url 0x38
_tag 0x48
_pSelector 0x50
_requestData 0x3c
_pUserData 0x54
_requestTypeGJ 0x68
*/

void GameLevelManager::ProcessHttpRequest(std::string endpoint, std::string params, std::string tag, GJHttpType httpType)
{
    if (GameManager::sharedState()->getGameVariable("0055"))
    {
        /* Seems to have had a typo on Robtop's End
         * URL Should've been named: "https://www.boomlings.com/database/checkIfServerOnline.php"
         * where "databas" should've been named "database"...*/
        endpoint = "https://www.boomlings.com/databas/checkIfServerOnline.php";
    };
    cocos2d::extension::CCHttpRequest *request = new cocos2d::extension::CCHttpRequest();
    request->setUrl(endpoint.c_str());
    request->setRequestType(cocos2d::extension::CCHttpRequest::kHttpPost);
    request->setResponseCallback(this, onProcessHttpRequestCompleted);
    request->setUserData(NULL);
    if (this != NULL)
    {
        retain();
    }
    request->setRequestData(params.c_str(), params.size());
    request->setTag(tag.c_str());
    request->_requestTypeGJ = (int)httpType;
    /* Send-Off */
    cocos2d::extension::CCHttpClient::getInstance()->send(request);
    request->release();
}

void GameLevelManager::performNetworkTest()
{
    if (!b_NetworkTested)
    {
        b_NetworkTested = true;
        std::string postData = "temp";
        cocos2d::extension::CCHttpRequest *request = new cocos2d::extension::CCHttpRequest();
        request->setUrl("https://www.google.com");
        /* Unknown Field Call where variable 0x74 is set to 1 */
        request->setRequestType(cocos2d::extension::CCHttpRequest::kHttpPost);
        request->setResponseCallback(this, onProcessHttpRequestCompleted);
        request->setUserData(NULL);
        retain();
        request->setRequestData(postData.c_str(), postData.size());
        request->setTag("tag");
        cocos2d::extension::CCHttpClient::getInstance()->send(request);
        request->release();
    }
};

void GameLevelManager::onProcessHttpRequestCompleted(cocos2d::extension::CCHttpClient *client, cocos2d::extension::CCHttpResponse *response)
{
    GameToolbox::getResponse(response);
    handleIt(true, response->getResponseData()->data(),response->getHttpRequest()->getTag(), (GJHttpType)response->getHttpRequest()->get_requestTypeGJ());
}


// void GameLevelManager::handleIt(bool success, std::string _response, std::string _tag, GJHttpType httpType){
    
// };


void GameLevelManager::resetStoredUserInfo(int key){
    m_pUserInfoDict->removeObjectForKey(key);
}


