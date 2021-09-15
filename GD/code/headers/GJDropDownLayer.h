#include "includes.h"

class GJListLayer;
class GJDropDownLayerDelegate;

class GJDropDownLayer : public cocos2d::CCLayerColor
{
public:
	cocos2d::CCPoint m_obEndPosition;
	cocos2d::CCPoint m_obStartPosition;
	cocos2d::CCMenu* m_pUIMenu;
	GJListLayer* m_pListLayer;
	bool m_bControllerEnabled;
	cocos2d::CCLayer* m_pLayer;
	bool m_bCleanup;
	GJDropDownLayerDelegate* m_pDelegate;
};