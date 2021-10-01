#include "includes.h"

class UndoObject : public cocos2d::CCObject
{
	GameObject* m_pObject;
	int m_eUndoCommand;
	cocos2d::CCArray* m_pUndoArray;
	bool m_bRedo;
};
