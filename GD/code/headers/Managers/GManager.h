#ifndef __GMANAGER_H__
#define __GMANAGER_H__

#include "../includes.h"
#include "cocos-ext.h"

/* Special Base Class for all The Game Managers... */

class GManager: cocos2d::CCNode {

    virtual void encodeDataTo(DS_Dictionary *dsdict);
    virtual bool dataLoaded(DS_Dictionary *dsdict);
    virtual bool firstLoad();

    std::string getCompressedSaveString();
    std::string getSaveString();
    bool init();
    bool load();
    bool loadDataFromFile(std::string fileName);
    bool loadFromCompressedString(std::string compressedStr);
    bool loadFromString(std::string data);

    void save();
    bool saveData(DS_Dictionary *dsdict, std::string fileName);
    void saveGMTo(std::string fileName);
    void setup();
    bool tryLoadData(DS_Dictionary* dsdict, std::string fileName);

    std::string m_fileName;
    bool m_setup;
    bool m_saved;
    bool m_quickSave;
};


#endif // __GMANAGER_H__
