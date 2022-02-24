#include "includes.h"




class GJAccountRegisterDelegate
{
public:
    virtual void registerAccountFinished();
    virtual void registerAccountFailed(AccountError _err);
};

class GJAccountLoginDelegate
{
public:
    virtual void loginAccountFinished(int accountID, int playerID);
    virtual void loginAccountFailed(AccountError _err);
};

class GJAccountDelegate
{
public:
    virtual void accountStatusChanged();
};

class GJAccountBackupDelegate
{
public:
    virtual void backupAccountFinished();
    virtual void backupAccountFailed(BackupAccountError _err);
};

class GJAccountSyncDelegate
{
public:
    virtual void syncAccountFinished();
    virtual void syncAccountFailed(BackupAccountError _err);
};

class GJAccountSettingsDelegate
{
public:
    virtual void updateSettingsFinished();
    virtual void updateSettingsFailed();
};

// credits to 13laze for this
class TriggerEffectDelegate
{
public:
    bool defaultEnterEffect_;

    virtual void toggleGroupTriggered(int _idx, bool _toggle);
    virtual void spawnGroup(int _idx);
};

class TextInputDelegate;
class UploadPopupDelegate;
class UploadActionDelegate;
class LikeItemDelegate;
class LevelCommentDelegate;
class CommentUploadDelegate;
class AnimatedSpriteDelegate;
class DialogDelegate;