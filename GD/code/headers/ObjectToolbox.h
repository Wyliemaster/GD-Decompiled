#include "includes.h"

class ObjectToolbox : public cocos2d::CCNode
{
public:
	cocos2d::CCDictionary* m_pframeToKey;
	cocos2d::CCDictionary* m_pkeyToFrame;

	static ObjectToolbox* g_toolbox = nullptr;

	ObjectToolbox* ObjectToolbox();
	virtual bool init();
	cocos2d::CCArray* allKeys();
	static ObjectToolbox* sharedState();
};
