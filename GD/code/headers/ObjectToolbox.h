#include "includes.h"

#define ADD_TO_TOOLBOX(__KEY, __VALUE) \
	m_pframeToKey->setObject(cocos2d::CCString::createWithFormat("%s", __VALUE), __KEY); \
	m_pkeyToFrame->setObject(cocos2d::CCString::createWithFormat("%i", __KEY), __VALUE);

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
