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
};
