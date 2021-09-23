#include "includes.h"

class SetGroupIDLayer : public FLAlertLayer, TextInputDelegate
{
	GameObject* m_pObj;
	cocos2d::CCArray* m_pObjects;
	cocos2d::CCArray* m_pZLayerArray;
	cocos2d::CCArray* m_pGroupArray;
	cocos2d::CCLabelBMFont* m_pEditorLayerLabel;
	cocos2d::CCLabelBMFont* m_pEditorLayer2Label;
	cocos2d::CCLabelBMFont* m_pZOrderLabel;
	CCTextInputNode* m_pGroupIDInput;
	int m_nGroupID;
	int m_nEditorLayer;
	int m_nEditorLayer2;
	int m_nZOrder;
	int m_nZLayer;
	bool m_bExecutingFunction; // Unsure about this
	bool m_bRemovedGroup;
	bool m_bHighDetail;
	bool m_bDontFade;
	bool m_bDontEnter;
	int m_nTag;
	bool m_bGroupParent;
	bool m_bHasEditedGroups;
	int m_nNextFreeGroup;
};
