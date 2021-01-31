#include <DS_Dictionary>

int __fastcall encodeWithCoder(SongInfoObject *this, DS_Dictionary *DS_Dictionary)
{
    GameManager = GameManager::sharedState(this)
        DS_Dictionary->setIntegerForKey("kCEK", 6);
    DS_Dictionary->setIntegerForKey('1', this->songID);
    DS_Dictionary->setStringForKey('2', &this->songName);
    DS_Dictionary->setStringForKey('4', &this->artistName);
    DS_Dictionary->setIntegerForKey('3', this->artistID);
    DS_Dictionary->setFloatForKey('5', this->downloadSize);
    if (GameManager == 1)
    {
        if (this->songYT != 0)
        {
            DS_Dictionary->setStringForKey("6", &this->songYT);
        }
        if (this->artistYT != 0)
        {
            DS_Dictionary->setStringForKey('7', &this->artistYT);
        }
        DS_Dictionary->setStringForKey("10", &this->downloadLink);
    }
    return DS_Dictionary->setIntegerForKey('9', this->songPriority);
}
