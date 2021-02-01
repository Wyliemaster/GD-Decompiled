#include <DS_Dictionary>
void GameLevelManager::encodeDataTo(DS_Dictionary *DS_Dictionary)
{
    DS_Dictionary->setDictForKey("GLM_01", GLM01_);
    DS_Dictionary->setArrayForKey("GLM_02", GLM02_);
    DS_Dictionary->setDictForKey("GLM_03", GLM03_);
    DS_Dictionary->setDictForKey("GLM_04", GLM04_);
}