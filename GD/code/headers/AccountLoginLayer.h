#include "includes.h"

class TextInputDelegate;
class GJAccountLoginDelegate;
class FLAlertLayerProtocol;
class CCTextInputNode;

class AccountLoginLayer : public FLAlertLayer, TextInputDelegate, GJAccountLoginDelegate, FLAlertLayerProtocol
{
	CCTextInputNode* m_pUsernameInput;
	CCTextInputNode* m_pPasswordInput;
	cocos2d::CCLabelBMFont* m_pUsernameLabel;
	cocos2d::CCLabelBMFont* m_pPasswordLabel;
	LoadingCircle* m_pLoadingCircle;
	std::string m_sUsername;
	std::string m_sPassword;
};
