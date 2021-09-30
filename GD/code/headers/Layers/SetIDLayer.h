#include "includes.h"

class GameObject;

class SetIDLayer : public FLAlertLayer
{
	cocos2d::CCLabelBMFont* m_pIDLabel;
	GameObject* m_pGameObject;

	SetIDLayer();
	bool init(GameObject* obj);
	static SetIDLayer* create(GameObject* obj);
	void onUp(cocos2d::CCObject* btn);
	void onDown(cocos2d::CCObject* btn);
	void onClose(cocos2d::CCObject* btn);
	void updateID(cocos2d::CCObject* btn);
};
