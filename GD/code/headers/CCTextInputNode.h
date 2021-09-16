#include "includes.h"

class CCTextInputNode : public cocos2d::CCLayer, cocos2d::CCIMEDelegate, cocos2d::CCTextFieldDelegate
{
	bool m_bFinishedTypingMaybe;
	std::string m_sText;
	int m_Unk;
	bool m_bIME;
	std::string m_sAllowedChars;
	float m_fMaxLabelWidth;
	float m_fMaxLabelScale;
	float m_fPlaceholderScale;
	cocos2d::ccColor3B m_cPlaceholderColour;
	cocos2d::ccColor3B m_cColour;
	cocos2d::CCLabelBMFont* m_pBlinkLabel;
	cocos2d::CCTextFieldTTF* m_pTextField;
	TextInputDelegate* m_pDelegate;
	int m_nCharLength;
	cocos2d::CCLabelBMFont* m_pPlaceholderLabel;
	bool m_bUnk;
	bool m_bShowPlaceholder;
	bool m_bForceOffset;
};