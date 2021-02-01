#include <DS_Dictionary>
void GameStatsManager::encodeDataTo(DS_Dictionary *DS_Dictionary)
{
    DS_Dictionary->setDictForKey("GS_value", GSValue_);         //all your account Stats
    DS_Dictionary->setDictForKey("GS_completed", GSCompleted_); //All the completed levels
}