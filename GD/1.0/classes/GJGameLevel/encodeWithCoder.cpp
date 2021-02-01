#include <DS_Dictionary>

void GJGameLevel::encodeWithCoder(DS_Dictionary *DS_Dictionary)
{
    DS_Dictionary->setIntegerForKey("kCEK", 4);
    DS_Dictionary->setIntegerForKey("k1", levelID_);
    DS_Dictionary->setStringForKey("k2", strings_);
    DS_Dictionary->setStringForKey("k3", Description_);
    DS_Dictionary->setStringForKey("k4", LevelString_);
    DS_Dictionary->setStringForKey("k5", Creator_);
    DS_Dictionary->setIntegerForKey("k6", userID_);
    DS_Dictionary->setIntegerForKey("k7", levelDifficulty_);
    DS_Dictionary->setIntegerForKey("k8", officialSongID_);
    DS_Dictionary->setIntegerForKey("k9", rating_);
    DS_Dictionary->setIntegerForKey("k10", ratingSum_);
    DS_Dictionary->setIntegerForKey("k11", downloads_);
    DS_Dictionary->setIntegerForKey("k12", setCompletes_);
    DS_Dictionary->setBoolForKey("k13", isEditable_);
    DS_Dictionary->setBoolForKey("k14", isVerified_);
    DS_Dictionary->setBoolForKey("k15", isUploaded_);
    DS_Dictionary->setIntegerForKey("k18", attempts_);
    DS_Dictionary->setIntegerForKey("k19", normalModePercent_);
    DS_Dictionary->setIntegerForKey("k20", practiceModePercent_);
    DS_Dictionary->setIntegerForKey("k22", likeRating_);
    DS_Dictionary->setIntegerForKey("k23", length_);
    DS_Dictionary->setIntegerForKey("k21", levelType_);
    DS_Dictionary->setIntegerForKey("k16", levelVersion_);
    DS_Dictionary->setIntegerForKey("k17", gameVersion_);
}