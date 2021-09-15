#include "includes.h"

class GJAccountDelegate;
class FLAlertLayerProtocol;
class TextArea;
class LoadingCircle;

class AccountHelpLayer : public GJDropDownLayer, GJAccountDelegate, FLAlertLayerProtocol
{
public:
	cocos2d::CCLabelBMFont* m_pTitleText;
	TextArea* m_pErrorText;
	CCMenuItemSpriteExtra* m_pRefreshLoginBtn;
	CCMenuItemSpriteExtra* m_pUnlinkBtn;
	bool m_bLinked;
};
