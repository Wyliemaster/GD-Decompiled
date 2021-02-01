#include <DS_Dictionary>
void GameLevelManager::encodeDataTo(DS_Dictionary *DS_Dictionary)
{
    DS_Dictionary->setDictForKey("GLM_01", GLM01_);  //Official Levels
    DS_Dictionary->setArrayForKey("GLM_02", GLM02_); //Created Levels
    DS_Dictionary->setDictForKey("GLM_03", GLM03_);  //Online Levels
    DS_Dictionary->setDictForKey("GLM_04", GLM04_);  //ratings given to levels
}