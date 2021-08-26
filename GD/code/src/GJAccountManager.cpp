#include "../headers/includes.h"

cocos2d::CCObject *GJAccountManager::getDLObject(const char *_tag)
{
    return m_pDLObject->objectForKey(_tag);
}

bool GJAccountManager::isDLActive(const char *_tag)
{
    return getDLObject(_tag); //i think this works?
}

void GJAccountManager::addDLToActive(const char *_tag, cocos2d::CCObject *_obj)
{
    //R0->0xEC->setObject(R1,R2)
    m_pDLObject->setObject(_obj, _tag);
}

void GJAccountManager::addDLToActive(const char *_tag)
{
    cocos2d::CCNode *obj = cocos2d::CCNode::create();
    addDLToActive(_tag, obj);
}

void GJAccountManager::removeDLFromActive(const char *_tag)
{
    m_pDLObject->removeObjectForKey(_tag);
}

std::string GJAccountManager::getGJP()
{
    return cocos2d::ZipUtils::base64EncodeEnc(m_sPlayerPassword, Globals::XORAccountPassword);
}

void GJAccountManager::encodeDataTo(DS_Dictionary *_dict)
{
    _dict->setStringForKey("GJA_002", m_sPlayerPassword);
    _dict->setStringForKey("GJA_001", m_sPlayerUsername);
    _dict->setIntegerForKey("GJA_003", m_nPlayerAccountID);
}

void GJAccountManager::dataLoaded(DS_Dictionary *_dict)
{
    m_sPlayerPassword = _dict->getStringForKey("GJA_002");
    m_sPlayerUsername = _dict->getStringForKey("GJA_001");
    m_nPlayerAccountID = _dict->getIntegerForKey("GJA_003");
}

void GJAccountManager::firstSetup() {}

void GJAccountManager::onLoginAccountCompleted(std::string _response, std::string _tag)
{
    removeDLFromActive(_tag.c_str());
    if (stoi(_response) == AccountError::kAccountErrorAccountDisabled || stoi(_response) == AccountError::kAccountErrorLinkedToDifferentSteamAccount || stoi(_response) == AccountError::kAccountErrorGeneric)
    {
    errorLabel:
        if (!m_pLoginAccountDelegate)
            return;
        return m_pLoginAccountDelegate->loginAccountFailed(static_cast<AccountError>(std::stoi(_response)));
    }
    cocos2d::CCArray *resArr = RobTop::splitToCCArray(_response, ",");
    if (resArr->count() <= 2)
        goto errorLabel;

    int accountID = resArr->stringAtIndex(0)->intValue();
    int playerID = resArr->stringAtIndex(1)->intValue();

    if (accountID <= 0 || playerID <= 0)
        goto errorLabel;

    if (m_pLoginAccountDelegate)
        m_pLoginAccountDelegate->loginAccountFinished(accountID, playerID);
}

void GJAccountManager::handleIt(bool _requestSentSuccessfully, std::string _response, std::string _tag, GJHttpType _httpType)
{
    std::string serverResponse = _response;
    if (!_requestSentSuccessfully)
        serverResponse = "-1";

    switch (_httpType)
    {
    case GJHttpType::kGJHttpTypeLoginAccount:
        onLoginAccountCompleted(serverResponse, _tag);
        break;
    case GJHttpType::kGJHttpTypeRegisterAccount:
        onRegisterAccountCompleted(serverResponse, _tag);
        break;
    case GJHttpType::kGJHttpTypeGetAccountBackupURL:
        onGetAccountBackupURLCompleted(serverResponse, _tag);
        break;
    case GJHttpType::kGJHttpTypeGetAccountSyncURL:
        onGetAccountSyncURLCompleted(serverResponse, _tag);
        break;
    case GJHttpType::kGJHttpTypeUpdateAccountSettings:
        onUpdateAccountSettingsCompleted(serverResponse, _tag);
        break;
    case GJHttpType::kGJHttpTypeSyncAccount:
        onSyncAccountCompleted(serverResponse, _tag);
        break;
    case GJHttpType::kGJHttpTypeBackupAccount:
        onBackupAccountCompleted(serverResponse, _tag);
        break;
    default:
        return;
    }
}