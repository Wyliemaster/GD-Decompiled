#include "./2.1/headers/GJGameLevel.hpp";
#include "cocos2d.h"

void GJGameLevel::setLevelName(std::string levelName)
{
    levelName_ = levelName;
}

void GJGameLevel::setDemon(bool demon)
{
    demon_ = demon;
    int rand = rand();
    demonRand_ = rand;
    demonSeed_ = demon + rand;
}

void GJGameLevel::setStars(int stars)
{
    stars_ = stars;
    int rand = rand();
    starsRand_ = rand;
    starsSeed_ = stars + rand;
}

void GJGameLevel::setCapacityString(std::string capacityString)
{
    capacityString_ = capacityString;
}

std::string GJGameLevel::getLevelName()
{
    return levelName_;
}

void GJGameLevel::setPassword(int password)
{
    int rand = rand();
    passwordRand_ = rand;
    passwordSeed_ = password + rand;
}

bool GJGameLevel::canEncode()
{
    return true;
}

//GJGameLevel::GJGameLevel
void GJGameLevel::constructor()
{
    lastBuildSave_ = 0;
    levelIDSeed_ = 0;
    levelIDRand_ = 0;
    levelID_ = 0;
    levelName_ = "";
    levelDescription_ = "";
    levelString_ = "";
    userName_ = "";
    recordString_ = "";
    userIDSeed_ = 0;
    userIDRand_ = 0;
    userID_ = 0;
    field_110 = 0;
    field_114 = 0;
    accountIDSeed_ = 0;
    accountIDRand_ = 0;
    accountID_ = 0;
    levelDifficulty_ = 0;
    songIndex_ = 0;
    customSongID_ = 0;
    levelRevision_ = 0;
    isUnlisted_ = false;
    objectCountSeed_ = 0;
    objectCountRand_ = 0;
    objectCount_ = 0;
    levelOrder_ = 0;
    ratings_ = 0;
    ratingsSum_ = 0;
    downloads_ = 0;
    isEditable_ = false;
    isGauntlet_ = false;
    isGauntlet2_ = false;
    editorTime_ = 0;
    editorCopiesTime_ = 0;
    hasLDM_ = false;
    toggleLDM_ = false;
    isVerifiedSeed_ = 0;
    isVerifiedRand_ = 0;
    isVerified_ = false;
    isUploaded_ = false;
    hasBeenAltered_ = false;
    levelVersion_ = 0;
    gameVersion_ = 0;
    attemptsSeed_ = 0;
    attemptsRand_ = 0;
    attempts_ = 0;
    jumpsSeed_ = 0;
    jumpsRand_ = 0;
    jump_ = 0;
    clicksSeed_ = 0;
    clicksRand_ = 0;
    clicks_ = 0;
    playerTimeSeed_ = 0;
    playerTimeRand_ = 0;
    playerTime_ = 0;
    chkValid_ = false;
    triggeredAnticheat_ = false;
    normalModePercentage_ = 0;
    normalPercentageRand_ = 0;
    normalPercentageSeed_ = 0;
    normalNewPercentageSeed_ = 0;
    normalNewPercentageRand_ = 0;
    normalNewPercentage_ = 0;
    normalNew2PercentageSeed_ = 0;
    normalNew2PercentageRand_ = 0;
    normalNew2Percentage_ = 0;
    practicePercentage_ = 0;
    likes_ = 0;
    dislikes_ = 0;
    length_ = 0;
    featureScore_ = 0;
    isEpic_ = false;
    levelFavourited_ = false;
    levelFolder_ = 0;
    timelyIDSeed_ = 0;
    timelyIDRand_ = 0;
    timelyID_ = 0;
    demonSeed_ = 0;
    demonRand_ = 0;
    demon_ = false;
    demonDifficulty_ = 4;
    starsSeed_ = 0;
    starsRand_ = 0;
    stars_ = 0;
    isAuto_ = false;
    totalCoins_ = 0;
    coinsVerifiedSeed_ = 0;
    coinsVerifiedRand_ = 0;
    coinsVerified_ = false;
    passwordSeed_ = 0;
    passwordRand_ = 0;
    copiedIDSeed_ = 0;
    copiedIDRand_ = 0;
    copiedID_ = 0;
    isTwoPlayer_ = false;
    gap24D[3] = 0;
    coin1Seed_ = 0;
    coin1Rand_ = 0;
    coin1_ = false;
    coin2Seed_ = 0;
    coin2Rand_ = 0;
    coin2_ = false;
    coin3Seed_ = 0;
    coin3Rand_ = 0;
    coin3_ = false;
    requestedStars_ = 0;
    gap27C[0] = 0;
    gap27C[4] = 0;
    gap27C[8] = 0;
    gap27C[12] = 0;
    gap27C[16] = 0;
    gap27C[20] = 0;
    gap27C[24] = 0;
    gap27C[28] = 0;
    gap27C[32] = 0;
    isChallenge_ = false;
    isLevelPlayable_ = false;
    requiredCoins_ = 0;
    isUnlocked_ = false;
    cocos2d::CCPoint::CCPoint(cameraXPos_);
    buildTab_ = 0;
    cameraZoom_ = 0.0;
    buildTabPage = 0;
    editorLayer_ = 0;
    levelType_ = 0;
    gap2C8[4] = 0;
    tempName_ = "";
    capacityString_ = "";
    highObjectCount_ = 0;
    levelProgress_ = "";
}