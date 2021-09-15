#include "includes.h"

class GJAccountDelegate;
class GJAccountBackupDelegate;
class GJAccountSyncDelegate;
class FLAlertLayerProtocol;
class TextArea;
class LoadingCircle;

class AccountLayer : public GJDropDownLayer, GJAccountDelegate, GJAccountBackupDelegate, GJAccountSyncDelegate, FLAlertLayerProtocol
{
public:
	cocos2d::CCLabelBMFont* m_pTitleText;
	TextArea* m_pErrorText;
	CCMenuItemSpriteExtra* m_pLoginBtn;
	CCMenuItemSpriteExtra* m_pRegisterBtn;
	CCMenuItemSpriteExtra* m_pBackupBtn;
	CCMenuItemSpriteExtra* m_pSyncBtn;
	CCMenuItemSpriteExtra* m_pHelpBtn;
	CCMenuItemSpriteExtra* m_pMoreBtn;
	LoadingCircle* m_pLoadingCircle;
	int m_nButtonID;
	bool m_bLinked;
};
