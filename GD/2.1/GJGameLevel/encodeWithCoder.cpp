/*
Info
addresses
windows: 0xCECB0
android: TBA
*/

#include <DS_Dictionary>

int __fastcall GJGameLevel::encodeWithCoder(GJGameLevel *this, DS_Dictionary *a2, int a3)
{
    DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "kCEK", 4);
    DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k1", this->levelIDSum - this->levelIDRand);
    DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k35", this->demon);
    DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k18", this->attemptsSum - this->attemptsRand);
    DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k36", this->jumpsSum - this->jumpsRand);
    DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k85", this->clicksSum - this->clicksRand);
    DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k86", this->playerTimeSum - this->playerTimeRand);
    DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k87", this->leaderboardSeed);
    levelProgress = sub_AEB10(this, v9);
    v10 = 0;
    DS_Dictionary::setStringForKey(DS_DictionarySavePath, "k88", levelProgress);
    v10 = -1;

    if (v9[5] >= (void *)0x10)
    {
        operator delete(v9[0]);
    }

    DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k89", this->isChkValid);
    DS_Dictionary::setIntegerForKey(
        DS_DictionarySavePath,
        "k19",
        this->normalModePercentSum - this->normalModePercentRand);

    DS_Dictionary::setIntegerForKey(
        DS_DictionarySavePath,
        "k71",
        this->orbRewardPercentageSum - this->orbRewardPercentageRand);

    DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k90", this->verifiyPercentageSum - this->verifyPercentageRand);
    DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k20", this->practiceModePercent);

    if (this->demonSum - this->demonRand == 1)
    {
        DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k25", 1); // isDemon
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k76", this->demonType);
    }

    if (this->starsSum - this->starsRand > 0)
    {
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k26", this->starsSum - this->starsRand);
        triggeredAntiCheat = this->triggeredAntiCheat;
    }

    if (triggeredAntiCheat)
    {
        DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k68", triggeredAntiCheat);
    }

    DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k74", this->timelyIDSum - this->timelyIDRand);
    DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k77", this->isGauntlet);
    DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k78", this->isGauntlet2);
    levelFavourited = this->isLevelFavourited;

    if (levelFavourited)
    {
        DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k82", levelFavourited);
    }

    if (this->levelFolders > 0)
    {
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k84", this->levelFolders);
    }

    if (!this->demon)
    {
        if (!this->dword10C)
        {
            v6 = (GJGameLevel *)&this->name;

            if (this->dword37C)
            {
                if (v6 != (GJGameLevel *)&this->char36C)
                {
                    sub_1F720(v6, (int)&this->char36C, 0, 0xFFFFFFFF);
                }
            }
            else
            {
                sub_21450("Unknown");
            }
        }

        DS_Dictionary::setStringForKey(DS_DictionarySavePath, "k2", &this->name);
        DS_Dictionary::setStringForKey(DS_DictionarySavePath, "k3", &this->strings[4]);

        if ((this->demon || this->byte340 || this->levelType == 1 || *(_BYTE *)(sub_D4A50() + 262)) && this->levelType != 2 && (this->timelyIDSum - this->timelyIDRand <= 0 || this->byte340))
        {
            sub_1F680((int)levelString, &unk_293988);
            v10 = 1;
            DS_Dictionary::setStringForKey(DS_DictionarySavePath, "k4", levelString);
            v10 = -1;

            if (v8 >= 0x10)
            {
                operator delete((void *)levelString[0]);
            }

            v8 = 15;
            levelString[4] = 0;
            LOBYTE(levelString[0]) = 0;
        }
        else
        {
            DS_Dictionary::setStringForKey(DS_DictionarySavePath, "k4", &this->strings[28]);
        }

        DS_Dictionary::setStringForKey(DS_DictionarySavePath, "k5", &this->strings[52]);

        if (!*(_BYTE *)(sub_D4A50() + 262))
        {
            DS_Dictionary::setStringForKey(DS_DictionarySavePath, "k34", &this->strings[76]);
        }

        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k6", this->userIDSum - this->userIDRand);
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k60", this->accountIDSum - this->accountIDRand);
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k7", this->levelDifficulty);
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k8", this->officialSongIndex);
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k9", this->rating);
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k10", this->ratingSum);
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k11", this->downloads);
        DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k13", this->isEditable);
        DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k14", this->verifiedSum - this->verifiedRand == 1);
        DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k15", this->isUploaded);
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k22", this->likes);
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k24", this->dislikes);
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k23", this->length);
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k21", this->levelType);
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k16", this->levelVersion);
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k17", this->gameVersion);
        DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k69", this->highObjectCount);

        if (this->editorTime > 0)
        {
            DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k80", this->editorTime);
        }

        if (this->editorTimeCopies > 0)
        {

            DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k81", this->editorTimeCopies);
        }

        DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k72", this->hasLDM);
        DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k73", this->toggleLDM);
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k83", this->levelOrder);
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k64", this->totalCoins);
        DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k65", this->coinsVerifiedSum - this->coinsVerifiedRand == 1); // areCoinsVerified
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k27", this->featureScore);
        DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k75", this->isEpic);
        DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k33", this->isAuto);
        DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k79", this->isUnlisted);
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k41", this->levelPasswordSum - this->levelPasswordRand); // levelPassword
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k42", this->uploadIDSum - this->uploadIDRand);           // uploadID
        DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k43", this->isTwoPlayer);
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k45", this->customSongID);
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k50", 35); // binaryVersion
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k46", this->levelRevision);
        DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k47", this->hasBeenModified);
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k48", this->objectCountSum - this->objectCountRand); // objectCount
        DS_Dictionary::setStringForKey(DS_DictionarySavePath, "k67", &this->strings[4]);
        DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k66", this->requestedStars);

        if (this->levelType == 1)
        {
            DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k38", this->isUnlocked);
            DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "k37", this->requiredCoins);
        }

        if (this->levelType == 2)
        {
            DS_Dictionary::setFloatForKey(DS_DictionarySavePath, "kI1", this->editorCameraX);
            DS_Dictionary::setFloatForKey(DS_DictionarySavePath, "kI2", this->editorCameraY);
            DS_Dictionary::setFloatForKey(DS_DictionarySavePath, "kI3", this->editorCameraZoom);
            DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "kI4", this->buildTabPage);
            DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "kI5", this->buildTab);
            DS_Dictionary::setIntegerForKey(DS_DictionarySavePath, "kI7", this->editorLayer);
            DS_Dictionary::setDictForKey(DS_DictionarySavePath, "kI6", this->buildTabPages);
            DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k61", this->coin1Sum - this->coin1Rand == 1); // coin1
            DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k62", this->coin2Sum - this->coin2Rand == 1); // coin2
            DS_Dictionary::setBoolForKey(DS_DictionarySavePath, "k63", this->coin3Sum - this->coin3Rand == 1); // coin3
        }
    }
}