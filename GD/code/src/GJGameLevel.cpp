#include "includes.h"
#include <cocos2d.h>

/* This is the 2.2 Version of GJGameLevel, If you need Wylie's Version Go See: 
 * https://github.com/Wyliemaster/GD-Decompiled/blob/main/GD/code/src/GJGameLevel.cpp
 * https://github.com/Wyliemaster/GD-Decompiled/blob/main/GD/code/headers/GJGameLevel.h
 */


/* Some of these are not written yet since I wanted to 
 * reverse other things but 92% of all the 41 functions have been reversed 
 * (all in the span of 12 hours which is impressive...) 
 * I mainly just needed the class members to reverse any other objects 
 * that needed to interact with this one. 
 * 
 * If you need the class member offsets I will have them avalible
 * in my decomp tools repository so that you don't have to go through 
 * the pain and burden that I had to overcome,
 * 
 * If you Want to do any of the functions that I may have missed 
 * feel free to send a pull request, I am using android v2.205 
 * (and windows v2.204 whenever android's version gets confusing)
 */


bool GJGameLevel::areCoinsVerified() {
    int i = m_secondCoinVerified_Random - m_secondCoinVerified_Seed;
    if (m_firstCoinVerified_Random - m_firstCoinVerified_Seed){
        i++;
    }
    if (m_thirdCoinVerified_Random - m_thirdCoinVerified_Seed){
        i++;
    }
    if (m_coins > 0){
        if (i < m_coins){
            m_coins = 0;
        }
        return (coins <= i) ? true : false;
    }
    return true;
}

bool GJGameLevel::canEncode() {
    return true;
}

void GJGameLevel::copyLevelInfo(GJGameLevel *LevelInfo)
{
    m_levelName = GameLevelManager::sharedState()->getNextLevelName(LevelInfo->m_levelName);
    m_levelString = LevelInfo->m_levelString;
    m_audioTrack = LevelInfo->m_audioTrack;
    m_songID = LevelInfo->m_songID;
    m_twoPlayerMode = LevelInfo->m_twoPlayerMode;
    m_levelLength = LevelInfo->m_levelLength;
    m_timestamp = LevelInfo->m_timestamp;
    m_coins = LevelInfo->m_coins;
    unverifyCoins();
    m_lastBuildTab = LevelInfo->m_lastBuildTab;
    m_lastBuildPage = LevelInfo->m_lastBuildPage;
    m_fastEditorZoom = LevelInfo->m_fastEditorZoom;
    m_lastCameraPos = LevelInfo->m_lastCameraPos;
    m_lastBuildGroupID = LevelInfo->m_lastBuildGroupID;
    m_workingTime2 = LevelInfo->m_workingTime2 + LevelInfo->m_workingTime;
    m_workingTime = 0;
    m_unkString2 = LevelInfo->m_unkString2;
    m_unkPoint = LevelInfo->m_unkPoint;
    m_unkString1 = LevelInfo->m_unkString1;
    m_sfxIDs = LevelInfo->m_sfxIDs;
    m_songIDs = LevelInfo->m_songIDs;
    m_54 = LevelInfo->m_54;
    return;
}

GJGameLevel *static GJGameLevel::create()

{
    GJGameLevel *level = new GJGameLevel;
    level->m_lastBuildSave = new cocos2d::CCDictionary();
    level->m_levelID_Random = 0;
    level->m_levelID_Seed = 0;
    level->m_levelID = 0;
    level->m_levelName = "";
    level->m_levelDesc = "";
    level->m_levelString = "";
    level->m_creatorName = "";
    level->m_recordString = "";
    level->m_uploadDate = "";
    level->m_updateDate = "";
    level->m_unkString1 = "";
    level->m_unkString2 = "";
    level->m_unkPoint = cocos2d::CCPoint();
    level->m_userID_Random = 0;
    level->m_userID_Seed = 0;
    level->m_userID = 0;
    level->m_accountID_Random = 0;
    level->m_accountID_Seed = 0;
    level->m_accountID = 0;
    level->m_difficulty = 0;
    level->m_audioTrack = 0;
    level->m_songID = 0;
    level->m_levelRev = 0;
    level->m_unlisted = false;
    level->m_friendsOnly = false;
    level->m_objectCount_Random = 0;
    level->m_objectCount_Seed = 0;
    level->m_objectCount = 0;
    level->m_levelIndex = 0;
    level->m_ratings = 0;
    level->m_ratingsSum = 0;
    level->m_downloads = 0;
    level->m_isEditable = false;
    level->m_gauntletLevel = false;
    level->m_gauntletLevel2 = false;
    level->m_workingTime = 0;
    level->m_workingTime2 = 0;
    level->m_lowDetailMode = false;
    level->m_lowDetailModeToggled = false;
    level->m_selected = false;
    level->m_localOrSaved = false;
    level->m_disableShake = false;
    level->m_isVerified_Random = 0;
    level->m_isVerified_Seed = 0;
    level->m_isVerifiedRaw = false;
    level->m_isUploaded = false;
    level->m_hasBeenModified = false;
    level->m_levelVersion = 0;
    level->m_gameVersion = 0;
    level->m_attempts_Random = 0;
    level->m_attempts_Seed = 0;
    level->m_attempts = 0;
    level->m_jumps_Random = 0;
    level->m_jumps_Seed = 0;
    level->m_jumps = 0;
    level->m_clicks_Random = 0;
    level->m_clicks_Seed = 0;
    level->m_clicks = 0;
    level->m_attemptTime_Random = 0;
    level->m_attemptTime_Seed = 0;
    level->m_attemptTime = 0;
    level->m_isChkValid = false;
    level->m_isCompletionLegitimate = false;
    level->m_normalPercent = 0;
    level->m_normalPercent_Seed = 0;
    level->m_normalPercent_Random = 0;
    level->m_newNormalPercent_Random = 0;
    level->m_newNormalPercent_Seed = 0;
    level->m_newNormalPercent = 0;
    level->m_newNormalPercent2_Random = 0;
    level->m_newNormalPercent2_Seed = 0;
    level->m_newNormalPercent2 = 0;
    level->m_practicePercent = 0;
    level->m_likes = 0;
    level->m_dislikes = 0;
    level->m_levelLength = 0;
    level->m_featured = 0;
    level->m_isEpic = 0;
    level->m_levelFavorited = false;
    level->m_levelFolder = 0;
    level->m_dailyID_Random = 0;
    level->m_demonDifficulty = 4;
    level->m_dailyID_Seed = 0;
    level->m_dailyID = 0;
    level->m_demon_Random = 0;
    level->m_demon_Seed = 0;
    level->m_demon = 0;
    level->m_stars_Random = 0;
    level->m_stars_Seed = 0;
    level->m_stars = 0;
    level->m_autoLevel = false;
    level->m_coins = 0;
    level->m_coinsVerified_Random = 0;
    level->m_coinsVerified_Seed = 0;
    level->m_coinsVerified = 0;
    level->m_password_Random = 0;
    level->m_password_Seed = 0;
    level->m_originalLevel_Random = 0;
    level->m_originalLevel_Seed = 0;
    level->m_originalLevel = 0;
    level->m_twoPlayerMode = false;
    level->m_failedPasswordAttempts = 0;
    level->m_firstCoinVerified_Random = 0;
    level->m_firstCoinVerified_Seed = 0;
    level->m_firstCoinVerified = 0;
    level->m_secondCoinVerified_Random = 0;
    level->m_secondCoinVerified_Seed = 0;
    level->m_secondCoinVerified = 0;
    level->m_thirdCoinVerified_Random = 0;
    level->m_thirdCoinVerified_Seed = 0;
    level->m_thirdCoinVerified = 0;
    level->m_starsRequested = 0;
    level->m_showedSongWarning = false;
    level->m_starRatings = 0;
    level->m_starRatingsSum = 0;
    level->m_maxStarRatings = 0;
    level->m_minStarRatings = 0;
    level->m_demonVotes = 0;
    level->m_rateStars = 0;
    level->m_rateFeature = 0;
    level->m_rateUser = "";
    level->m_dontSave = false;
    level->m_levelNotDownloaded = false;
    level->m_requiredCoins = 0;
    level->m_isUnlocked = false;
    level->m_lastCameraPos = cocos2d::CCPoint();
    level->m_fastEditorZoom = 0.0;
    level->m_lastBuildTab = 0;
    level->m_lastBuildPage = 0;
    level->m_lastBuildGroupID = 0;
    level->m_levelType = 0;
    level->m_M_ID = 0;
    level->m_tempName = "";
    level->m_capacityString = "";
    level->m_highObjectsEnabled = false;
    level->m_unlimitedObjectsEnabled = false;
    level->m_personalBests = "";
    level->m_timestamp = 0;
    level->m_unkInt = 0;
    level->m_songIDs = "";
    level->m_sfxIDs = "";
    level->m_54 = 0;
    level->m_bestTime = 0;
    level->m_bestPoints = 0;
    level->m_unkString3 = "";
    level->m_unkString4 = "";

    if (!level->init())
    {
        CC_SAFE_RELEASE(level);
        return nullptr;
    }
    else
    {
        level->autorelease();
    }
    return level;
}

/* Sorry if overload function is still messy, or not accurate I was up from 1:00am - 3:00am trying to
    repair this one function from the awful mess ghidra had generated for me.
    At least the result when repaired was satisfying...

    TODO: Ask Robtop if the keys used are actually enums
*/

static GJGameLevel *create(cocos2d::CCDictionary *dict, bool has_password)
{
    auto level = create();
    level->m_levelID = dict->valueForKey("1")->intValue();
    level->m_levelName = dict->valueForKey("2")->getCString();
    level->m_levelDesc = dict->valueForKey("3")->getCString();
    level->m_levelString = dict->valueForKey("4")->getCString();
    level->m_levelVersion = dict->valueForKey("5")->intValue();
    level->m_recordString = dict->valueForKey("26")->getCString();
    level->m_uploadDate = dict->valueForKey("28")->intValue();
    level->m_updateDate = dict->valueForKey("29")->getCString();
    level->m_ratings = dict->valueForKey("8")->intValue();
    level->m_ratingsSum = dict->valueForKey("9")->intValue();
    level->m_downloads = dict->valueForKey("10")->intValue();
    level->m_audioTrack = dict->valueForKey("12")->intValue();
    level->m_gameVersion = dict->valueForKey("13")->intValue();
    level->m_likes = dict->valueForKey("14")->intValue();
    level->m_dislikes = dict->valueForKey("16")->intValue();
    level->m_levelLength = dict->valueForKey("15")->intValue();
    level->setDemon(dict->valueForKey("17")->boolValue());
    level->m_demonDifficulty = dict->valueForKey("43")->intValue();
    level->setStars(dict->valueForKey("18")->intValue());
    level->m_coins = dict->valueForKey("37")->intValue();
    level->setCoinsVerified(dict->valueForKey("38")->boolValue());
    level->m_featured = dict->valueForKey("19")->intValue();
    level->m_isEpic = dict->valueForKey("42")->intValue();
    level->setObjectCount(dict->valueForKey("45")->intValue());
    level->m_autoLevel = dict->valueForKey("25")->intValue();
    level->m_starsRequested = dict->valueForKey("39")->intValue();

    int password;
    if (!has_password) {
        password = cocos2d::CCDictionary::valueForKey("27")->intValue();
    }
    else {
        std::string StrPassword = dict->valueForKey("27")->getCString();
        /* Password is too weak so appearently it's skipped...
         * Robtop definately Thought ahead, I can tell - Calloc */

        /* This is also where cyclic encryption takes place... */
        password = StrPassword.length() < 2 ? 0 : atoi(cocos2d::ZipUtils::base64DecodeEnc(password, "26364")->c_str());
    }
    level->setOriginalLevel(dict->valueForKey("30")->intValue());
    level->m_twoPlayerMode = dict->valueForKey("31")->boolValue();
    level->m_songID = dict->valueForKey("35")->intValue();
    level->m_capacityString = dict->valueForKey("36")->getCString();
    auto userID = accountIDForUserID(dict->valueForKey("6")->intValue());
    auto GLM = GameLevelManager::sharedState();
    accountID = GLM->accountIDForUserID(userID);
    std::string userName = GLM->userNameForUserID(userID);
    if (userName->length() < 2)
    {
        level->m_creatorName = GLM->tryGetUsername(userName);
    }
    else
    {
        level->m_creatorName = userName;
    }
    level->setLevelID(dict->valueForKey("1")->intValue());
    level->m_userID = userID;
    level->m_userID_Seed = rand() * 4.656613e-10 * 1000.0;
    level->m_userID_Random = level->m_userID + userID;
    level->setAccountID(accountID);
    level->m_password_Seed = rand() * 4.656613e-10 * 1000.0;
    level->m_password_Random = level->m_password_Seed + password;
    level->m_lowDetailMode = dict->valueForKey("40")->boolValue();
    level->setDailyID(dict->valueForKey("41")->intValue());
    level->m_gauntletLevel = dict->valueForKey("44")->boolValue();
    level->m_workingTime = dict->valueForKey("46")->intValue();
    level->m_workingTime2 = dict->valueForKey("47")->intValue();
    level->m_timestamp = dict->valueForKey("57")->intValue();
    level->parseSettingsString(dict->valueForKey("48")->getCString());
    level->m_songIDs = dict->valueForKey("52")->getCString();
    level->m_sfxIDs = dict->valueForKey("53")->getCString();
    level->m_54 = dict->valueForKey("54")->intValue();
    level->m_levelType = level->m_demon ? 4 : 3;
    return level;
};

GJGameLevel *GJGameLevel::createWithCoder(DS_Dictionary *dict)
{
    GJGameLevel *level = create();
    level->dataLoaded(dict);
    return level;
}


void GJGameLevel::dataLoaded(DS_Dictionary *dsdict){
    m_levelNotDownloaded = dcdict->getBoolForKey("k35");
    setLevelID(dcdict->getIntegerForKey("k1"));
    setAttempts(dcdict->getIntegerForKey("k18"));
    setNormalPercent(dcdict->getIntegerForKey("k19"));
    setNewNormalPercent(dcdict->getIntegerForKey("k71"));
    setNewNormalPercent2(dcdict->getIntegerForKey("k90"));
    m_practicePercent = dcdict->getIntegerForKey("k20");
    setJumps(dcdict->getIntegerForKey("k36"));
    setClicks(dcdict->getIntegerForKey("k85"));
    setAttemptTime(dcdict->getIntegerForKey("k86"));
    m_chk = dcdict->getIntegerForKey("k87");
    m_personalBests = dsdict->getStringForKey("k88");
    m_isChkValid = dsdict->getBoolForKey("k89");
    m_levelLength = dsdict->getIntegerForKey("k23");
    setDemon(dsdict->getBoolForKey("k25"));
    m_demonDifficulty =  dsdict->getIntegerForKey("k76");
    setStars(dsdict->getIntegerForKey("k26"));
    setDailyID(dsdict->getIndexOfKey("k74"));
    m_isCompletionLegitimate = dsdict->getBoolForKey("k68");
    m_gauntletLevel = dsdict->getBoolForKey("k77");
    m_gauntletLevel2 =  dsdict->getBoolForKey("k78");
    m_levelFavorited = dsdict->getBoolForKey("k82");
    m_levelFolder = dsdict->getIntegerForKey("k84");
    m_bestTime = dsdict->getIntegerForKey("k107");
    m_bestPoints = dsdict->getIntegerForKey("k108");
    m_k111 = dsdict->getIntegerForKey("k111");
    m_unknString3 = dsdict->getStringForKey("k109");
    m_unknString4 = dsdict->getStringForKey("k110");
    if (!m_levelNotDownloaded) {
        m_levelName = dsdict->getStringForKey("k2");
        m_levelDesc = dsdict->getStringForKey("k3");
        m_levelString = dsdict->getStringForKey("k4");
        m_creatorName = dsdict->getStringForKey("k5");
        m_recordString = dsdict->getStringForKey("k34");
        m_timestamp =  dsdict->getIntegerForKey("k95");
        m_unkString1 = dsdict->getStringForKey("k91");
        m_unkString2 = dsdict->getStringForKey("k101");
        m_unkPoint = cocos2d::CCPoint::CCPoint(dsdict->getIntegerForKey("k102"), dsdict->getIntegerForKey("k103"));
        m_coins = dsdict->getIntegerForKey("k64");
        setCoinsVerified(dsdict->getBoolForKey("k65"));
        m_userID = dsdict->getIntegerForKey("k6");
        m_userID_Seed = (int)((float)rand() * 4.656613e-10 * 1000.0);
        m_userID_Random = m_userID_Seed + m_userID;
        setAccountID(dsdict->getIntegerForKey("k60"));
        m_difficulty = dsdict->getIntegerForKey("k7");
        m_audioTrack = dsdict->getIntegerForKey("k8");
        m_ratings = dsdict->getIntegerForKey("k9");
        m_ratingsSum = dsdict->getIntegerForKey("k10");
        m_downloads = dsdict->getIntegerForKey("k11");
        m_isEditable = dsdict->getBoolForKey("k13");
        m_isVerifiedRaw = dsdict->getBoolForKey("k14");
        m_isVerified_Seed =  (int)((float)rand() * 4.656613e-10 * 1000.0);
        m_isVerified_Random = m_isVerified_Seed + m_isVerifiedRaw;
        m_isUploaded = dsdict->getBoolForKey("k15");
        m_likes = dsdict->getIntegerForKey("k22");
        m_dislikes = dsdict->getIntegerForKey("k24");
        m_levelType  = dsdict->getIntegerForKey("k21");
        m_levelVersion = dsdict->getIntegerForKey("k16");
        m_gameVersion = dsdict->getIntegerForKey("k17");
        m_featured = dsdict->getIntegerForKey("k27");
        m_isEpic = dsdict->getIntegerForKey("k75");
        if (!m_isEpic) {
            m_isEpic = (int)dsdict->getBoolForKey("k75");
        }
        m_autoLevel = dsdict->getBoolForKey("k33");;
        m_unlisted = dsdict->getBoolForKey("k79");
        m_friendsOnly  = dsdict->getBoolForKey("k94");
        m_password_Seed = (int)((float)rand() * 4.656613e-10 * 1000.0);
        m_password_Random = m_password_Seed + dsdict->getIntegerForKey("k41");
        setOriginalLevel(dsdict->getIntegerForKey("k42"));
        m_twoPlayerMode  = dsdict->getBoolForKey("k43");
        m_songID = dsdict->getIntegerForKey("k45");
        m_levelRev = dsdict->getIntegerForKey("k46");
        m_hasBeenModified = dsdict->getBoolForKey("k47");
        setObjectCount(dsdict->getIntegerForKey("k48"));
        m_capacityString = dsdict->getStringForKey("k67");
        m_starsRequested = dsdict->getIntegerForKey("k66");;
        m_highObjectsEnabled = dsdict->getBoolForKey("k69");
        m_unlimitedObjectsEnabled = dsdict->getBoolForKey("k93");
        m_workingTime = dsdict->getIntegerForKey("k80");
        m_workingTime2 = dsdict->getIntegerForKey("k81");
        m_lowDetailMode = dsdict->getBoolForKey("k72");
        m_lowDetailModeToggled = dsdict->getBoolForKey("k73");
        m_selected = dsdict->getBoolForKey("k112");
        m_levelIndex = dsdict->getIntegerForKey("k83");
        m_songIDs = dsdict->getStringForKey("k104");
        m_sfxIDs = dsdict->getStringForKey("k105");
        m_54 = dsdict->getIntegerForKey("k106");
    }
    if (m_levelType == 1) {
        m_isUnlocked = dsdict->getBoolForKey("k38");
        m_requiredCoins = dsdict->getIntegerForKey("k37");
    }
    if (m_levelType == 2) {
        m_lastCameraPos = cocos2d::CCPoint::CCPoint(dsdict->getFloatForKey("kI1"),dsdict->getFloatForKey("kI2") >> 0x20);
        m_fastEditorZoom = dsdict->getFloatForKey("kI3");
        m_lastBuildPage = dsdict->getIntegerForKey("kI4");
        m_lastBuildTab = dsdict->getIntegerForKey("kI5");
        m_lastBuildGroupID = dsdict->getIntegerForKey("kI7");
        cocos2d::CCDictionary* _lastBuildSave = dsdict->getDictForKey("kI6",0);
        if (m_lastBuildSave != _lastBuildSave) {
            if (_lastBuildSave != NULL) {
                _lastBuildSave->retain();
            }
            if (m_lastBuildSave != NULL) {
                m_lastBuildSave->release();
            }
                m_lastBuildSave = _lastBuildSave;
        }
        m_firstCoinVerified = dsdict->getBoolForKey("k61");
        m_firstCoinVerified_Seed = (int)((float)rand() * 4.656613e-10 * 1000.0);
        m_firstCoinVerified_Random = m_firstCoinVerified_Seed + m_firstCoinVerified;
        m_secondCoinVerified = dsdict->getBoolForKey("k62");
        m_secondCoinVerified_Seed = (int)((float)rand() * 4.656613e-10 * 1000.0);
        m_secondCoinVerified_Random = m_secondCoinVerified_Seed + m_secondCoinVerified;
        m_thirdCoinVerified = dsdict->getBoolForKey("k63");
        m_thirdCoinVerified_Seed = (int)((float)rand() * 4.656613e-10 * 1000.0);
        m_thirdCoinVerified_Random = m_thirdCoinVerified_Seed + m_thirdCoinVerified;
    }      
    int MaybelevelStrSize = dsdict->getIntegerForKey("k50");
    if (MaybelevelStrSize < 0xf) {
        if (m_levelString == "") {
            if (m_levelType == 2) {
                m_levelString = cocos2d::ZipUtils::compressString(m_levelString,0,0xb);
            }
            else {
                m_levelString = "";
            }
        }
    } else if (MaybelevelStrSize < 0x1a) {
        /* IDK Exactly what this part of the code is... */
        m_levelDesc = LevelTools::base64EncodeString(m_levelDesc);
    }
}



static int GJGameLevel::demonIconForDifficulty(DemonDifficultyType demonDiff){
    if (demonDiff - 3 < 4){
        /* IDK What DAT_0098b18d is... */
        // return &DAT_0098b18d[param_1];
    }
    return 6;
}

/* void __thiscall GJGameLevel::encodeWithCoder(GJGameLevel *DS_Dictionary *param_1,char *param _2) Saved for tomorrow */

/* IDK Why it exists Feels Pretty Useless... */
std::string GJGameLevel::generateSettingsString()
{
    return "";
}

std::string GJGameLevel::getAudioFileName()
{
    return m_songID ? MusicDownloadManager::sharedState()->pathForSong(m_songID) : LevelTools::getAudioFileName(m_audioTrack);
}

long GJGameLevel::getAverageDifficulty(){
    return m_ratings < 5 ? 0 : lroundf(m_ratingsSum);
}

const char *GJGameLevel::getCoinKey(int unknInt)
{
    if (m_dailyID_Random - m_dailyID_Seed < 1){
        return cocos2d::CCString::createWithFormat(m_gauntletLevel ? "%i_%i_g" : "%i_%i", m_levelID_Random - m_levelID_Seed, unknInt)->getCString();
    }
    else {
        return cocos2d::CCString::createWithFormat("%i_%i_%i", m_levelID_Random - m_levelID_Seed, unknInt)->getCString();
    }
}
int GJGameLevel::getLastBuildPageForTab(int page){
    return m_lastBuildSave->valueForKey(cocos2d::CCString::createWithFormat("%i", page)->getCString())->intValue();
}

GJLength GJGameLevel::getLengthKey(int seconds, bool platformer) {
    if (platformer){
        return kGJLengthPlat;
    }
    if (seconds < 10){
        return kGJLengthTiny;
    }
    if (seconds < 30){
        return kGJLengthShort;
    }
    if (seconds < 60){
        return kGJLengthMedium;
    }
    return seconds < 120 ? kGJLengthLong : kGJLengthXL;
}

GJGameLevel *GJGameLevel::getListSnapshot(){
    auto snapShot = create();
    snapShot->setLevelID(m_levelID_Random - m_levelID_Seed);
    snapShot->m_levelName =  m_levelName);
    snapShot->m_levelLength = m_levelLength;
    snapShot->m_timestamp = m_timestamp;
    snapShot->setAccountID(m_accountID_Random - m_accountID_Seed);
    snapShot->m_creatorName = m_creatorName;
    snapShot->m_likes = m_likes;
    snapShot->m_downloads = m_downloads;
    snapShot->m_audioTrack = m_audioTrack;
    snapShot->m_songID = m_songID;
    snapShot->m_levelType = m_levelType;
    snapShot->m_ratings = m_ratings;
    snapShot->m_ratingsSum = m_ratingsSum;
    snapShot->setDemon(m_demon_Random - m_demon_Seed);
    snapShot->m_demonDifficulty = m_demonDifficulty;
    snapShot->m_autoLevel = m_autoLevel;
    snapShot->m_featured = m_featured;
    snapShot->m_isEpic = m_isEpic;
    snapShot->setStars(m_stars_Random - m_stars_Seed);
    snapShot->m_coins = m_coins;
    snapShot->setCoinsVerified(m_coinsVerified_Random - m_coinsVerified_Seed);
    originalLevel = m_originalLevel_Random - m_originalLevel_Seed;
    if (originalLevel != 0){
        originalLevel = 1;
    }
    snapShot->setOriginalLevel(originalLevel);
    snapShot->setObjectCount(m_objectCount_Random - m_objectCount_Seed);
    return snapShot;
}

int GJGameLevel::getNormalPercent(){
    return m_normalPercent_Random - m_normalPercent_Seed;
}

/* TODO: GJGameLevel::getSongName() */

std::string GJGameLevel::getUnpackedLevelDescription(){
    return m_levelDesc.length() ? LevelTools::base64DecodeString(m_levelDesc) : "";
}


void GJGameLevel::handleStatsConflict(GJGameLevel * otherLevel){
    // TODO: Optimize
    auto attempts = otherLevel->m_attempts_Random - otherLevel->m_attempts_Seed;
    auto attempts2 = m_attempts_Random - m_attempts_Seed;
    if (attempts < attempts2)
    {
        attempts = attempts2;
    }
    setAttempts(attempts);
    auto jumps = otherLevel->m_jumps_Random - otherLevel->m_jumps_Seed;
    auto jumps2 = m_jumps_Random - m_jumps_Seed;
    if (jumps < jumps2)
    {
        jumps = jumps2;
    }
    setJumps(jumps);
    auto OtherClicks = otherLevel->m_clicks_Random - otherLevel->m_clicks_Seed;
    auto clicks = m_clicks_Random - m_clicks_Seed;
    if (OtherClicks < clicks){
        clicks = OtherClicks;
    }
    setClicks(_random);
    default_normalPercent = getNormalPercent();
    other_normalPercent = otherLevel->getNormalPercent();
    auto level = otherLevel;
    if (default_normalPercent <= other_normalPercent){
        level = this;
    }
    setNormalPercent(level->getNormalPercent());
    int other_new_normalPercent = otherLevel->m_newNormalPercent_Random - otherLevel->m_newNormalPercent_Seed;
    int newNormalPercent = m_newNormalPercent_Random - m_newNormalPercent_Seed;
    if (other_new_normalPercent < m_newNormalPercent_Random - m_newNormalPercent_Seed){
        other_new_normalPercent = newNormalPercent;
    }
    setNewNormalPercent(other_new_normalPercent);
    newNormalPercent2 = otherLevel->m_newNormalPercent2_Random - otherLevel->m_newNormalPercent2_See d;
    saveNewScore(otherLevel->m_bestTime, 0);
    saveNewScore(otherLevel->m_bestPoints, 1);
    if (m_newNormalPercent2_Random - m_newNormalPercent2_Seed < newNormalPercent2){
        setNewNormalPercent2(newNormalPercent2);
        setClicks(otherLevel->m_clicks_Random - otherLevel->m_clicks_Seed);
        setAttemptTime(otherLevel->m_attemptTime_Random - otherLevel->m_attemptTime_Seed);
        m_chk = otherLevel->m_chk;
        m_personalBests = otherLevel->m_personalBests)
        m_isChkValid = otherLevel->m_isChkValid;
    }
    m_practicePercent = otherLevel->m_practicePercent <= m_practicePercent ? m_practicePercent : therLevel->m_practicePercent;
    m_levelIndex = otherLevel->m_levelIndex <= m_levelIndex ? m_levelIndex : otherLevel->m_levelIndex;
}

bool GJGameLevel::init(){
    m_levelName = "";
    m_levelDesc = "";
    m_levelString = "";
    m_personalBests = "";
    m_levelVersion = 1;
    m_levelType = 0;
    // Unknown Global Variable...
    //  m_M_ID = DAT_00aa4e94; 
    setAttempts(0);
    setJumps(0);
    setClicks(0);
    setAttemptTime(0);
    m_chk = 0;
    m_coins = 0;
    setStars(0);
    setDemon(0);
    m_dontSave = false;
    m_levelNotDownloaded = false;
    auto dict = cocos2d::CCDictionary::create();
    if (m_lastBuildSave != dict){
        if (dict != NULL){
            dict->release();
        }
        if (m_lastBuildSave != NULL){
            m_lastBuildSave->release();
        }
        m_lastBuildSave = dict;
    }
    return true;
}

bool GJGameLevel::isPlatformer(){
    return m_levelLength == kGJLengthPlat;
}

const char* GJGameLevel::lengthKeyToString(GJLength lengthKey)
{
    /* How Do I Know it's this way? Robtop Streamed one of
    his Switch blocks in his code although not this exact one. */
    switch (lengthKey){
        case kGJLengthTiny: return "Tiny";
        case kGJLengthShort: return "Short";
        case kGJLengthMedium: return "Medium";
        case kGJLengthLong: return "Long";
        case kGJLengthXL: return "XL";
        case kGJLengthPlat: return "Plat.";
        default: return "XL";
    }
}

void GJGameLevel::levelWasAltered(){
    m_hasBeenModified = true;
    m_isVerifiedRaw = false;
    m_isVerified_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_isVerified_Random = m_isVerified_Seed;
    unverifyCoins();
    m_capacityString = "";
    if (m_isUploaded != false) {
        m_isUploaded = false;
        m_levelVersion = m_levelVersion + 1;
    }
}

void GJGameLevel::levelWasSubmitted(){
    m_isUploaded = true;
}

/* Robtop Abandoned this function it appears to be just an ordinary Noop... */
void GJGameLevel::parseSettingsString(std::string Settings){
    return;
}

void GJGameLevel::saveNewScore(int newTime, int newPoints){
    if (newPoints == 0)
    {
        if ((newTime < 1) || ((m_bestTime <= newTime && (m_bestTime != 0))))
            goto StoreAndExit;
        m_bestTime = newTime;
    }
    else
    {
        if ((newPoints <= m_bestPoints) && (m_bestPoints != 0))
            goto StoreAndExit;
        m_bestPoints = newPoints;
    }
    m_k111 = generateBestHash(m_bestTime, newTime);
StoreAndExit:
    storeNewLocalScore(newTime, newPoints);
}

/* TODO: GJGameLevel::savePercentage(int, bool, int, int, bool) */

/* TODO: */
/* std::vector<std::string> GJGameLevel::scoreStringToVector(std::string, std::vector<int, std::allocator<int> >&) */
/* std::string GJGameLevel::scoreVectorToString(std::vector<int, std::allocator<int> >&, int) */




/* I had a python script write me write and reverse this RSV shit
 * since it got repettative and annoying. I will have it in my
 * micellaneous tools repository for you soon... */

void GJGameLevel::setAccountID(int accountID){
    m_accountID = accountID;
    m_accountID_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_accountID_Random = m_accountID_Seed + m_accountID;
}

void GJGameLevel::setAttempts(int attempts){
    m_attempts = attempts;
    m_attempts_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_attempts_Random = m_attempts_Seed + m_attempts;
}

void GJGameLevel::setAttemptTime(int attemptTime){
    m_attemptTime = attemptTime;
    m_attemptTime_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_attemptTime_Random = m_attemptTime_Seed + m_attemptTime;
}

void GJGameLevel::setClicks(int clicks){
    m_clicks = clicks;
    m_clicks_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_clicks_Random = m_clicks_Seed + m_clicks;
}

void GJGameLevel::setCoinsVerified(int coinsVerified){
    m_coinsVerified = coinsVerified;
    m_coinsVerified_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_coinsVerified_Random = m_coinsVerified_Seed + m_coinsVerified;
}
void GJGameLevel::setDailyID(int dailyID){
    m_dailyID = dailyID;
    m_dailyID_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_dailyID_Random = m_dailyID_Seed + m_dailyID;
}

void GJGameLevel::setDemon(int demon){
    m_demon = demon;
    m_demon_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_demon_Random = m_demon_Seed + m_demon;
}

void GJGameLevel::setJumps(int jumps){
    m_jumps = jumps;
    m_jumps_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_jumps_Random = m_jumps_Seed + m_jumps;
}

void GJGameLevel::setLevelID(int levelID){
    m_levelID = levelID;
    m_levelID_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_levelID_Random = m_levelID_Seed + m_levelID;
}

void GJGameLevel::setNewNormalPercent(int newNormalPercent){
    m_newNormalPercent = newNormalPercent;
    m_newNormalPercent_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_newNormalPercent_Random = m_newNormalPercent_Seed + m_newNormalPercent;
}

void GJGameLevel::setNewNormalPercent2(int newNormalPercent2){
    m_newNormalPercent2 = newNormalPercent2;
    m_newNormalPercent2_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_newNormalPercent2_Random = m_newNormalPercent2_Seed + m_newNormalPercent2;
}

void GJGameLevel::setNormalPercent(int normalPercent){
    m_normalPercent = normalPercent;
    m_normalPercent_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_normalPercent_Random = m_normalPercent_Seed + m_normalPercent;
}

void GJGameLevel::setObjectCount(int objectCount){
    m_objectCount = objectCount;
    m_objectCount_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_objectCount_Random = m_objectCount_Seed + m_objectCount;
}

void GJGameLevel::setOriginalLevel(int copiedID){
    m_originalLevel = copiedID;
    m_originalLevel_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_originalLevel_Random = m_originalLevel_Seed + m_originalLevel;
}

void GJGameLevel::setStars(int stars){
    m_stars = stars;
    m_stars_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_stars_Random = m_stars_Seed + m_stars;
}


/* AntiCheat */
bool GJGameLevel::shouldCheatReset(){  
  if ((7 < m_stars_Random - m_stars_Seed) && (m_jumps_Random - m_jumps_Seed < 0x32)) {
        int clicks = m_clicks_Random - m_clicks_Seed;
        return clicks > 49 ? false : (bool)(clicks < 50);
  }
  return false;
}


/* TODO: GJGameLevel::storeNewLocalScore(int, int) */


void GJGameLevel::unverifyCoins() {
    m_firstCoinVerified = 0;
    m_secondCoinVerified = 0;
    m_thirdCoinVerified = 0;
    m_firstCoinVerified_Seed = (int)((float)rand() * 4.656613e-10 * 1000.0);
    m_firstCoinVerified_Random = m_firstCoinVerified_Seed + m_firstCoinVerified;
    m_secondCoinVerified_Seed = (int)((float)rand() * 4.656613e-10 * 1000.0);
    m_secondCoinVerified_Random = m_secondCoinVerified_Seed + m_secondCoinVerified;
    m_thirdCoinVerified_Seed =  (int)((float)rand() * 4.656613e-10 * 1000.0);  
    m_thirdCoinVerified_Random = m_thirdCoinVerified_Seed + m_thirdCoinVerified;;
}


