#include "includes.h"
#include "enums.h"
#include <cocos2d.h>


/* In other words this means is the download we have running? 
 This is very simillar to that of a thread_lock or mutex - Calloc */
bool GameLevelManager::isDLActive(char * DLKey){
    return m_pDLObject->objectForKey(DLKey);
}

/* Should be the same as the one for the GJAccountManager They maybe even are the same function who knows... 
TODO: (Calloc) Add the Overload Function for addDLToActive...
*/
void GameLevelManager::addDLToActive(const char* _tag){
    cocos2d::CCNode *obj = cocos2d::CCNode::create();
    m_pDLObject->setObject(obj, _tag);
}

/* TODO: (Calloc) Complete this function */
std::string GameLevelManager::getBasePostString(){
    auto GM = GameManager::sharedState();
 
    std::string BasePostString;
    BasePostString += cocos2d::CCString::createWithFormat("gameVersion=%i&binaryVersion=%i&udid=%s&uuid=%i", 22 , 0x28, GM->m_sPlayerUDID,  GM->m_nChkRand - GM->m_nChkSeed)->getCString();
    /* There is more to this function but I have yet to find all of it out...*/
    return BasePostString;
}



const char * GameLevelManager::getCommentKey (int ID, int page, int mode, CommentKeyType keytype){
    /* IT Honstesly should be only one line which is very surprising...*/
    return cocos2d::CCString::createWithFormat("comment_%i_%i_%i_%i", page, mode, keytype, ID)->getCString();
};

const char* GameLevelManager::getLevelKey(int levelID){
    return cocos2d::CCString::createWithFormat("%i", levelID)->getCString();
};

int GameLevelManager::accountIDForUserID(int accountID){
    return m_pAccountIDDict->valueForKey(accountID)->intValue();
}

void GameLevelManager::cleanupDailyLevels(){
    auto dailylevelkeys =  m_pDailyLevels->allKeys();
    if (dailylevelkeys->count()){
        m_pDailyLevels->objectForKey(reinterpret_cast<cocos2d::CCString*>dailylevelkeys->objectAtIndex(dailylevelkeys->count() - 1)->getCString());
    }
}


/* TODO: Fix code as needed in the future... */

void GameLevelManager::getLevelComments(int ID, int page, int total, int mode, CommentKeyType keytype){
    char* key = getCommentKey(ID, page, mode, keytype);
    /* is the same request running for our key? if so do not run... */
    if (!isDLActive(key)){
        /* Throw this key into our mutex... */
        addDLToActive(key);
        /* Start our HTTP Request this poststring contains 
        * some of our other params like gameVersion, binaryVersion, udid, uuid , accountID , gjp and more... */
        std::string postString = getBasePostString();
        /* Wonder why Robtop wrote in his secret parameter this way? It's not really so secret... */
        const char* secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'W',"mfd","2893",'g','b',"7")->getCString();
        postString += cocos2d::CCString::createWithFormat("&page=%i&total=%i&secret=%s&mode=%i",page, total, secret, total)->getCString();
        /* set levelID or userID */
        postString.append(keytype == kCommentKeyTypeLevelType ? "&levelID=" : "&userID=");
        /* Add in our userID or levelID */
        postString += cocos2d::CCString::createWithFormat("%i", ID)->getCString();
    
        int count =  GameManager::sharedState()->getGameVariable("0088") ? 10 : 20;
        /* The Settings to make the pages smaller is checked here */
        if (GameManager::sharedState()->getGameVariable("0094")) 
            count *= 2;
        std::string endpoint = (keytype == kCommentKeyTypeLevelType) ? "https://www.boomlings.com/database/getGJComments21.php" : "https://www.boomlings.com/database/getGJCommentHistory.php";

        /* prepare for sendoff */
        ProcessHttpRequest(endpoint, postString, key, kGJHttpTypeGetLevelComments);
    }
}


const char* GameLevelManager::getAccountCommentKey(int accountID, int page){
    return cocos2d::CCString::createWithFormat("a_%i_%i",accountID,page)->getCString();
}


/* This is the comments made on the user's profile... */
void GameLevelManager::getAccountComments(int accountID, int page, int total){
    const char* key = getAccountCommentKey(accountID, page);
    if (!isDLActive(key)){
        addDLToActive(key);
        std::string poststr = getBasePostString();
        auto secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'W',"mfd","2893",'g','b',"7")->getCString();
        poststr += cocos2d::CCString::createWithFormat("&accountID=%i&page=%i&total=%i&secret=%s",accountID,page,total,secret)->getCString();
        ProcessHttpRequest("https://www.boomlings.com/database/getGJAccountComments20.php", poststr, key, kGJHttpTypeGetAccountComments);
    }
}




const char* GameLevelManager::getFriendRequestKey(bool sent, int page){
    return cocos2d::CCString::createWithFormat("fReq_%i_%i",(int)sent, page)->getCString();
}

void GameLevelManager::getFriendRequests(bool sent, int page, int total){
    const char* key = getFriendRequestKey(sent, page);
    if (!isDLActive()){
        addDLToActive(key);
        std::string poststr = getBasePostString();
        auto secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'W',"mfd","2893",'g','b',"7")->getCString();
        poststr += cocos2d::CCString::createWithFormat("&page=%i&total=%i&secret=%s",page,total, secret)->getCString();
        if (sent)
            poststr += "&getSent=1";
        ProcessHttpRequest("https://www.boomlings.com/database/getGJFriendRequests20.php");
    }

}

const char* GameLevelManager::getGaunletKey(int key){
    return cocos2d::CCString::createWithFormat("%i", key)->getCString();
}

const char* GameLevelManager::getGauntletSearchKey(int searchKey){
    return cocos2d::CCString::createWithFormat("gaunlet_%i", searchKey)->getCString();
}


void GameLevelManager::getGauntlets(){
    if (!isDLActive("get_gauntlets")){
        addDLToActive("get_gauntlets");
        std::string poststr = getBasePostString();
        auto secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'W',"mfd","2893",'g','b',"7")->getCString();
        poststr += cocos2d::CCString::createWithFormat("&secret=%s&special=1", secret)->getCString();
        ProcessHttpRequest("https://www.boomlings.com/database/getGJGauntlets21.php", poststr, "get_gauntlets", kGJHttpTypeGetGauntlets);
    }
}


/* TODO (Calloc) Change levelType to an enum when it's been figured out, I will let wyliemaster be in charge of figuring that stuff out...*/
void GameLevelManager::getGJDailyLevelState(int levelType){
    const char* key;
    if (levelType == 1){
        key = 0xde;
    } else if (levelType == 2){
        key = 0xeb;
    } else {
        key = 0xcc;
    }
    if (!isDLActive(key)){
        addDLToActive(key);
        std::string poststr = getBasePostString();
        const char* secert = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'W',"mfd","2893",'g','b',"7")->getCString();
        poststr += cocos2d::CCString::createWithFormat("&secret=%s&type=%i", secret, levelType);
        ProcessHttpRequest("https://www.boomlings.com/database/getGJDailyLevel.php", poststr, key, kGJHttpTypeGetGJDailyLevelState);
    }
}


const char* GameLevelManager::getUserInfoKey(int targetAccountID){
    return cocos2d::CCString::createWithFormat("account_%i", targetAccountID)->getCString(); 
}

void GameLevelManager::getGJUserInfo(int targetAccountID){
    const char* key = getUserInfoKey(targetAccountID);
    if (!isDLActive(key)){
        addDLToActive(key);
        std::string postStr = getBasePostString();
        const char* secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'W',"mfd","2893",'g','b',"7")->getCString();
        postStr += cocos2d::CCString::createWithFormat("&targetAccountID=%i&secret=%s",targetAccountID, secret)->getCString();
        ProcessHttpRequest("https://www.boomlings.com/database/getGJUserInfo20.php", postStr, key, kGJHttpTypeGetGJUserInfo);
    }
}

const char* GameLevelManager::getLenKey(int Len){
    return cocos2d::CCString::createWithFormat("Len%i", len)->getCString();
};

void GameLevelManager::getLevelSaveData(){
    if (!isDLActive("lvl_data")){
        addDLToActive("lvl_data");
        std::string postStr = getBasePostString();
        postStr += "&secret=";
        postStr +=  cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'W',"mfd","2893",'g','b',"7")->getCString();
        ProcessHttpRequest("https://www.boomlings.com/database/getSaveData.php", postStr, "lvl_data", kGJHttpTypeGetLevelSaveData);
    }
}

const char* GameLevelManager::getMapPackKey(int pack){
    return cocos2d::CCString::createWithFormat("pack_%i", pack)->getCString();
}

const char* GameLevelManager::getPostCommentsKey(int seconds_left){
    return cocos2d::CCString::createWithFormat("c_%i", seconds_left)->getCString();
}

const char* GameLevelManager::getRateStarsKey(int key){
    return cocos2d::CCString::createWithFormat("%i", key)->getCString();
}

const char* GameLevelManager::getReportKey(int levelID){
    return cocos2d::CCString::createWithFormat("%i", levelID)->getCString();
}

bool GameLevelManager::hasReportedLevel(int levelID){
    return (bool)this->m_pReportedLevels->objectForKey(getReportKey(levelID));
}

void GameLevelManager::reportLevel(int LevelID){
    if (!hasReportedLevel(levelID)){
        markLevelAsReported(levelID);
        std::string postStr = getBasePostString();
        const char* secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'W',"mfd","2893",'g','b',"7")->getCString();
        postStr += cocos2d::CCString::createWithFormat("levelID=%i&secret=%s", levelID, secret)->getCString();
        const char* key = cocos2d::CCString::createWithFormat("%i", levelID)->getCString();
        ProcessHttpRequest("https://www.boomlings.com/database/reportGJLevel.php", postStr, key, kGJHttpTypeReportLevel);
    }
}



const char* GameLevelManager::getTopArtistsKey(int page){
    return cocos2d::CCString::createWithFormat("topArtists_%i", page)->getCString();
}

void GameLevelManager::getTopArtists(int page, int total){
    const char* key = getTopArtistsKey(page);
    if (!isDLActive(key)){
        addDLToActive(key);
        std::string postStr = getBasePostString();
        const char* secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'W',"mfd","2893",'g','b',"7")->getCString();
        postStr += cocos2d::CCString::createWithFormat("&page=%i&secret=%s&total=%i",page,secret,total)->getCString();
        ProcessHttpRequest("https://www.boomlings.com/database/getGJTopArtists.php", postStr, key, kGJHttpTypeGetTopArtists);
    }
};


void GameLevelManager::getUserList(UserListType listType){
    const char* key;
    if (listType == kUserListTypeGetFriends){
        key = "get_friends";
    } else {
        key = "get_blocked";
    }
    if (!isDLActive(key)){
        addDLToActive(key);
        std::string postStr = getBasePostString();
        const char* secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'W',"mfd","2893",'g','b',"7")->getCString();
        postStr += cocos2d::CCString::createWithFormat("&type=%i&secret=%s",listType, secret)->getCString();
        ProcessHttpRequest("https://www.boomlings.com/database/getGJUserList20.php",postStr, key, kGJHttpTypeGetUserList);
    }
}

const char* GameLevelManager::getMessagesKey(bool getSent, int page){
    return cocos2d::CCString::createWithFormat("messages_%i_%i",(int)getSent, page)->getCString();
}

void GameLevelManager::getUserMessages(bool getSent, int page, int total){
    const char* key = getMessagesKey(getSent, page);
    if (!isDLActive(key)){
        addDLToActive(key);
        std::string postStr = getBasePostString();
        const char* secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'W',"mfd","2893",'g','b',"7")->getCString();
        postStr += cocos2d::CCString::createWithFormat("&page=%i&total=%i&secret=%s",page, total, secret)->getCString();
        if (getSent)
            postStr += "&getSent=1";
        ProcessHttpRequest("https://www.boomlings.com/database/getGJMessages20.php",postStr, key, kGJHttpTypeGetUserMessages);
    }
}


void GameLevelManager::getUsers (GJSearchObject * searchObject){
    const char* key = searchObject->getKey();
    if (!isDLActive(key)){
        addDLToActive(key);
        std::string postStr = getBasePostString();
        const char* secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'W',"mfd","2893",'g','b',"7")->getCString();
        postStr += cocos2d::CCString::createWithFormat("&str=%s&total=%i&page=%i&secret=%s",searchObject->m_sSearchQuery, searchObject->m_nTotal, searchObject->m_nPage, secret)->getCString();
        ProcessHttpRequest("https://www.boomlings.com/database/getGJUsers20.php", postStr, key, kGJHttpTypeGetUsers);
    }
}
