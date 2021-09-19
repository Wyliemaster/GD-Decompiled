#include "includes.h"

class DialogLayer : public cocos2d::CCLayerColor, TextAreaDelegate
{
public:
	float m_fTime;
	cocos2d::CCLayer* m_pLayer;
	cocos2d::CCLabelBMFont* m_pTitle;
	TextArea* m_pDialog;
	cocos2d::CCSprite* m_pIcon;
	cocos2d::CCArray* m_pDialogObjects;
	int m_eCCTouchEventMaybe;
	cocos2d::CCSprite* m_pChatBtn;
	bool m_bUnk;
	bool m_bCanSkip;
	DialogDelegate* m_pDialogDelegate;
	bool m_bUnk2;
	int m_nUnk;
};