#include "includes.h"

class NumberInputLayer : public FLAlertLayer
{
	cocos2d::CCLabelBMFont* m_pNumberLabel;
	CCMenuItemSpriteExtra* m_pOnNumberBtn;
	int m_nMinNumLength;
	int m_nMaxNumLength;
	std::string m_sNumber;
	void* someDelegate;
};
