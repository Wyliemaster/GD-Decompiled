#include <DS_Dictionary>

int __fastcall encodeWithCoder(SongInfoObject *this, DS_Dictionary *DS_DictionaryPath)
{
    GameManagerExists = GameManager::sharedState(this)
        DS_Dictionary::setIntegerForKey(DS_DictionaryPath, "kCEK", 6);
    DS_Dictionary::setIntegerForKey(DS_DictionaryPath, '1', this->songID);
    DS_Dictionary::setStringForKey(DS_DictionaryPath, '2', &this->songName);
    DS_Dictionary::setStringForKey(DS_DictionaryPath, '4', &this->artistName);
    DS_Dictionary::setIntegerForKey(DS_DictionaryPath, '3', this->artistID);
    DS_Dictionary::setFloatForKey(DS_DictionaryPath, '5', this->downloadSize);
    if (GameManager == 1)
    {
        if (this->songYT != 0)
        {
            DS_Dictionary::setStringForKey(DS_DictionaryPath, "6", &this->songYT);
        }
        if (this->artistYT != 0)
        {
            DS_Dictionary::setStringForKey(DS_DictionaryPath, '7', &this->artistYT);
        }
        DS_Dictionary::setStringForKey(DS_DictionaryPath, "10", &this->downloadLink);
    }
    return DS_Dictionary::setIntegerForKey(DS_DictionaryPath, '9', this->songPriority);
}