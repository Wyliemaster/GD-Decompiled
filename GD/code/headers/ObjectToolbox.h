#include "includes.h"

class ObjectToolbox : public cocos2d::CCNode
{
public:
	cocos2d::CCDictionary* m_pframeToKey;
	cocos2d::CCDictionary* m_pkeyToFrame;

	virtual bool init();
};
