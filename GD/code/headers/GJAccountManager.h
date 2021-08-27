#include "includes.h"

class GJAccountRegisterDelegate;
class GJAccountLoginDelegate;
class GJAccountDelegate;
class GJAccountBackupDelegate;
class GJAccountSyncDelegate;
class GJAccountSettingsDelegate;

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
    void handleIt(bool RequestSentSuccessfully, std::string _response, std::string _tag, GJHttpType _httpType);
    void onLoginAccountCompleted(std::string _response, std::string _tag);
    void onRegisterAccountCompleted(std::string _response, std::string _tag);
    void onBackupAccountCompleted(std::string _response, std::string _tag);
    void onUpdateAccountSettingsCompleted(std::string _response, std::string _tag);
    void onGetAccountSyncURLCompleted(std::string _response, std::string _tag);
    void onGetAccountBackupURLCompleted(std::string _response, std::string _tag);
    bool syncAccount(std::string _endpoint);
    void ProcessHttpRequest(std::string _endpoint, std::string _params, std::string, _tag, GJHttpType _httpType);
};
