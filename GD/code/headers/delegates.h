enum AccountError
{
    kAccountErrorUnknown = 0,
    kAccountErrorGeneric = -1,
    kAccountErrorTakenUsername = -2,
    kAccountErrorTakenEmail = -3,
    kAccountErrorInvalidUsername = -4,
    kAccountErrorInvalidPassword = -5,
    kAccountErrorInvalidEmail = -6,
    kAccountErrorPasswordsDontMatch = -7,
    kAccountErrorPasswordTooShort = -8,
    kAccountErrorUsernameTooShort = -9,
    kAccountErrorLinkedToDifferentAccount = -10,
    kAccountErrorUnk = -11,
    kAccountErrorAccountDisabled = -12,
    kAccountErrorLinkedToDifferentSteamAccount = -13,
    kAccountErrorEmailsDontMatch = -99
};

enum BackupAccountError
{
    kBackupAccountErrorUnknown = 0,
    kBackupAccountErrorGeneric = -1,
    kBackupAccountErrorLoginFailed = -2
};

class GJAccountRegisterDelegate
{
    virtual void registerAccountFinished();
    virtual void registerAccountFailed(AccountError _err);
};

class GJAccountLoginDelegate
{
    virtual void loginAccountFinished();
    virtual void loginAccountFailed(AccountError _err);
};

class GJAccountDelegate
{
    virtual void accountStatusChanged();
};

class GJAccountBackupDelegate
{
    virtual void backupAccountFinished();
    virtual void backupAccountFailed(BackupAccountError _err);
};

class GJAccountSyncDelegate
{
    virtual void syncAccountFinished();
    virtual void syncAccountFailed(BackupAccountError _err);
};

class GJAccountSettingsDelegate
{
    virtual void updateSettingsFinished();
    virtual void updateSettingsFailed();
};