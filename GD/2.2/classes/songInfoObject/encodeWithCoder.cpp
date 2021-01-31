#include <DS_Dictionary>

void SongInfoObject::encodeWithCoder(DS_Dictionary *DS_Dictionary)
{

    DS_Dictionary->setIntegerForKey("kCEK", 6);
    DS_Dictionary->setIntegerForKey('1', songID_);
    DS_Dictionary->setStringForKey('2', songName_);
    DS_Dictionary->setStringForKey('4', artistName_);
    DS_Dictionary->setIntegerForKey('3', artistID_);
    DS_Dictionary->setFloatForKey('5', downloadSize_);
    if (!GM->quickSave_)
    {
        if (songYT_ != 0)
        {
            DS_Dictionary->setStringForKey("6", songYT_);
        }
        if (artistYT_ != 0)
        {
            DS_Dictionary->setStringForKey('7', artistYT_);
        }
        DS_Dictionary->setStringForKey("10", downloadLink_);
    }
    DS_Dictionary->setIntegerForKey('9', songPriority_);
}
