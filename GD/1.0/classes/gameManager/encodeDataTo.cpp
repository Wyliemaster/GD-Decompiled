#include <DS_Dictionary>

void GameManager::encodeDataTo(DS_Dictionary *DS_Dictionary)
{
    DS_Dictionary->setDictForKey("scoreKeeper", scoreKeeperDict_);

    ValueKeeper = DS_Dictionary->setDictForKey("valueKeeper", valueKeeperDict_);
    AchievementManager = AchievementManager::sharedState(ValueKeeper);
    reportedAchievementsDict_ = getCompletedAchievements(AchievementManager)
                                    DS_Dictionary->setDictForKey(DS_Dictionary, "reportedAchievements", reportedAchievementsDict_);

    DS_Dictionary->setBoolForKey("gameCenterEnabled", gameCenterEnabled_);
    DS_Dictionary->setBoolForKey("firstSetup", firstSetup);
    DS_Dictionary->setBoolForKey("showedFirstTutorial", firstTutorial_);
    DS_Dictionary->setBoolForKey("musicEnabled", musicEnabled_);
    DS_Dictionary->setBoolForKey("fxEnabled", fxEnabled_);
    DS_Dictionary->setStringForKey("playerUDID", playerUDID_);
    DS_Dictionary->setStringForKey("playerName", playerName_);
    DS_Dictionary->setIntegerForKey("playerFrame", playerCube_);
    DS_Dictionary->setIntegerForKey("playerColor", playerColour1_);

    moreGamesManager = DS_Dictionary->setIntegerForKey("playerColor2", playerColour2_);
    MGM = MoreGamesManager::sharedState(moreGamesManager);

    gameLevelManager = MoreGamesManager::encodeDataTo(MGM, DS_Dictionary);
    GLM = GameLevelManager::sharedState(gameLevelManager);

    gameStatsManager = GameLevelManager::encodeDataTo(GLM, DS_Dictionary);
    GS = GameStatsManager::sharedState(gameStatsManager);

    GameStatsManager::encodeDataTo(GS, DS_Dictionary);
    DS_Dictionary->setBoolForKey("autoCheckpoints", toggleAutoCheckpoints_);
    DS_Dictionary->setBoolForKey("showSongMarkers", showSongMarkers_);
    DS_Dictionary->setBoolForKey("showBPMMarkers", showBPMMarkers_);
    DS_Dictionary->setBoolForKey("clickedGarage", clickedGarage_);
    DS_Dictionary->setBoolForKey("clickedEditor", clickedEditor_);
    DS_Dictionary->setBoolForKey("clickedName", clickedName_);
    DS_Dictionary->setBoolForKey("showedEditorGuide", showedEditorGuide_);
}