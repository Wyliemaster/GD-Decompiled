#include <DS_Dictionary>
void GameLevelManager::encodeDataTo(DS_Dictionary *DS_Dictionary)
{
    DS_Dictionary->setDictForKey("GLM_01", officialLevels_);     //Official Levels
    DS_Dictionary->setArrayForKey("GLM_02", localLevels_);       //Created Levels
    DS_Dictionary->setDictForKey("GLM_03", onlineLevels_);       //Online Levels
    DS_Dictionary->setDictForKey("GLM_04", onlineLevelRatings_); //ratings given to levels
}