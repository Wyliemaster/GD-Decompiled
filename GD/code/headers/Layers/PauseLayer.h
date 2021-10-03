#include "../includes.h"

class PauseLayer : public cocos2d::CCLayerColor
{
	BYTE m_bUnk[2]; // unk bools with no Xrefs
	bool m_bPaused;
	bool m_bHasQuit;
};
