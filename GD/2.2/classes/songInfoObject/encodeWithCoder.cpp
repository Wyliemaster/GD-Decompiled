#include <DS_Dictionary>

void SongInfoObject::encodeWithCoder(SongInfoObject *this, DS_Dictionary *DS_Dictionary)
{
    GameManager = GameManager::sharedState(this)
        DS_Dictionary->setIntegerForKey("kCEK", 6);
    DS_Dictionary->setIntegerForKey('1', songID);
    DS_Dictionary->setStringForKey('2', songName);
    DS_Dictionary->setStringForKey('4', artistName);
    DS_Dictionary->setIntegerForKey('3', artistID);
    DS_Dictionary->setFloatForKey('5', downloadSize);
    if (GameManager == 1)
    {
        if (this->songYT != 0)
        {
            DS_Dictionary->setStringForKey("6", songYT);
        }
        if (this->artistYT != 0)
        {
            DS_Dictionary->setStringForKey('7', artistYT);
        }
        DS_Dictionary->setStringForKey("10", downloadLink);
    }
    DS_Dictionary->setIntegerForKey('9', songPriority);
}
