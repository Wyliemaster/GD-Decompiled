#include "includes.h"

class AccountRegisterLayer : public FLAlertLayer, TextInputDelegate, GJAccountRegisterDelegate, FLAlertLayerProtocol
{
	CCTextInputNode* m_pUsernameInput;
	CCTextInputNode* m_pPasswordInput;
	CCTextInputNode* m_pConfirmPasswordInput;
	CCTextInputNode* m_pEmailInput;
	CCTextInputNode* m_pVerifyEmailInput;
	cocos2d::CCLabelBMFont* m_pUsernameLabel;
	cocos2d::CCLabelBMFont* m_pPasswordLabel;
	cocos2d::CCLabelBMFont* m_pConfirmPasswordLabel;
	cocos2d::CCLabelBMFont* m_pEmailLabel;
	cocos2d::CCLabelBMFont* m_pVerifyEmailLabel;
	LoadingCircle* m_pLoadingCircle;
	bool m_bAllowTextInput;
};
