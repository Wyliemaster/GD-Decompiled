#include <cocos2d.h>
#include "delegates.h"

class GJAccountManager : public cocos2d::CCNode
{
public:
    cocos2d::CCDictionary *m_pDLObject;
    std::string m_sPlayerPassword;
    std::string m_sPlayerUsername;
    int m_nPlayerAccountID;
    int m_nPlayerAccountIDSeed;
    int m_nPlayerAccountIDRand;
    GJAccountRegisterDelegate *m_pRegisterAccountDelegate;
    GJAccountLoginDelegate *m_pLoginAccountDelegate;
    GJAccountDelegate *m_pAccountDelegate;
    GJAccountBackupDelegate *m_pBackupAccountDelegate;
    GJAccountSyncDelegate *m_pSyncAccountDelegate;
    GJAccountSettingsDelegate *m_pAccountSettingsDelegate;

    cocos2d::CCObject *getDLObject(const char *_tag);
    bool isDLActive(const char *_tag);
    void addDLToActive(const char *_tag, cocos2d::CCObject *_obj);
    void addDLToActive(const char *_tag);
    void removeDLFromActive(const char *_tag);
    std::string getGJP();
    void encodeDataTo(DS_Dictionary *_dict);
    void dataLoaded(DS_Dictionary *_dict);
    void firstSetup();
    void GJAccountManager::onLoginAccountCompleted(std::string a2, std::string a3);
};
