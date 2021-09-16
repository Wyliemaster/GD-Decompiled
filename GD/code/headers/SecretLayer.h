#include "includes.h"

class SecretLayer : public cocos2d::CCLayer, TextInputDelegate, FLAlertLayerProtocol
{
	int m_nBasicMessageIdx;
	int m_nThreadID;
	int m_nMessageID;
	int m_nUnk;
	int m_nSecretNumberComboIdx;
	CCTextInputNode* m_pCodeInput;
	cocos2d::CCLabelBMFont* m_pMessageLabel;
	CCMenuItemSpriteExtra* m_pSubmitBtn;
	cocos2d::CCDictionary* m_pResponseDict;
	int m_nUnredeemedCodeIdx;
};
