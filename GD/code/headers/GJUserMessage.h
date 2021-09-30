#include "includes.h"

class GJUserMessage : public cocos2d::CCNode
{
	int m_nMessageID;
	int m_nAccountID;
	int m_nPlayerID;
	std::string m_sSubject;
	std::string m_sContent;
	std::string m_sUsername;
	std::string m_sAge;
	bool m_bRead;
	bool m_bSender;
	bool m_bToggle; // toggle messages for deletion and stuff like that
};
