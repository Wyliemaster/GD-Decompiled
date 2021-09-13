#include "../headers/includes.h"	

void EffectGameObject::customSetup()
{
	int idx = 0;
	bool blending = false;
	GameObject::customSetup();
	switch (m_nObjectID)
	{
	case 29: // BG trigger
		idx = 1000;
		break;
	case 30: // Ground1 Trigger
		idx = 1001;
		break;
	case 105: // Obj Trigger
		idx = 1004;
		break;
	case 744: // 3DLine trigger
		idx = 1003;
		break;
	case 900: // Ground2 Trigger
		idx = 1009;
		break;
	case 915: // Line Trigger
		idx = 1002;
		blending = true;
	}

	m_nColourIdx = idx;
	m_bBlending = blending;
	m_fOpacity = 1.0f;
}

void EffectGameObject::triggerActivated(float _xPos)
{
	GameObject::triggerActivated(this, _xPos);
	m_obSpawnPosition.x = _xPos
}

float EffectGameObject::spawnXPosition()
{
	if (m_bSpawnTriggered || m_bTouchTriggered) return m_obSpawnPosition.x;
	return getPosition().x;
}

void EffectGameObject::updateSpecialColor()
{
	cocos2d::ccColor3B col;
	if (m_nObjectID == 1049) // Toggle Trigger
	{
		cocos2d::CCSprite *trigger = reinterpret_cast<cocos2d::CCSprite *>(getChildByTag(998));
		m_bActivateGroup ? col = { 0xFF, 0x00, 0x7F } : col = { 0x3F, 0xFF, 0x3F };
		trigger->setColor(col);
	}
}

void EffectGameObject::resetSpawnTrigger()
{
	m_bUniqueActivated = false;
	m_bActivated = false;
	m_obSpawnPosition.x = getPosition().x;
}

int EffectGameObject::getTargetColorIndex()
{
	switch (m_nObjectID)
	{
	case 29: // BG
		return 1000;
	case 30: // G1
		return 1001;
	case 915: // Line
		return 1002;
	case 744: // 3DL
		return 1003;
	case 105: // Obj
		return 1004;
	case 900: // G2
		return 1009;
	}
	return m_nColourIdx;
}