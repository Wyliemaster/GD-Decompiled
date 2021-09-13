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

void EffectGameObject::customObjectSetup(std::map<std::string, std::string> _saveString)
{
	int objID = m_nObjectID;
	m_bTouchTriggered = atoi(_saveString["11"]) != 0;
	m_bSpawnTriggered = atoi(_saveString["62"]) != 0;
	m_bMultiTriggered = atoi(_saveString["87"]) != 0;
	m_bBlending = false;
	m_fOpacity = 1.0;

	switch (objID) {
	case 1347:// Follow Trigger
		m_nTargetGroupID = atoi(_saveString["51"]);
		m_nSecondaryGroupID = atoi(_saveString["71"]);
		m_fDuration = strtod(_saveString["10"], nullptr);
		m_obFollowMod.x = strtod(_saveString["72"], nullptr);
		m_obFollowMod.y = strtod(_saveString["73"], nullptr);
		UndocuementedLevelProperty74 = atoi(_saveString["74"]) ? 1 : 0;
		break;
	case 1611:  // Count Trigger
		m_nItemID = atoi(_saveString["80"]);
		m_nTargetGroupID = atoi(_saveString["51"]);
		m_nCount = atoi(_saveString["77"]);
		m_bActivateGroup = atoi(_saveString["56"]) != 0;
		m_bUnusedLevelProperty104 = atoi(_saveString["104"]) != 0;
		break;
	case 1595:  // Touch Trigger
		m_nTargetGroupID = atoi(_saveString["51"]);
		m_bActivateGroup = atoi(_saveString["56"]) != 0;
		m_bHoldMode = atoi(_saveString["81"]) != 0;
		m_eToggleMode = static_cast<TouchToggleMode>(atoi(_saveString["82"]));
		m_bDualMode = atoi(_saveString["89"]) != 0;
		break;
	case 1585:  // Animate Trigger
		m_nTargetGroupID = atoi(_saveString["51"]);
		m_nAnimationID = atoi(_saveString["76"]);
		break;
	case 1520:  // Shake Trigger
		m_fDuration = strtod(_saveString["10"], nullptr);
		m_fShakeStrength = strtod(_saveString["75"], nullptr);
		m_fShakeInterval = strtod(_saveString["84"], nullptr);
		break;
	case 1814: // Follow Player Y
		m_nTargetGroupID = atoi(_saveString["51"]);
		m_fDuration = strtod(_saveString["10"], nullptr);
		m_fFollowSpeed = strtod(_saveString["90"], nullptr);
		m_fFollowDelay = strtod(_saveString["91"], nullptr);
		m_nYOffset = atoi(_saveString["92"]);
		m_fMaxFollowSpeed = strtod(_saveString["105"]);
		break;
	case 1816:  // Collision Block
		m_nItemID = atoi(_saveString["80"]);
		m_bDynamicBlock = atoi(_saveString["94"]) != 0;
		m_nTargetGroupID = atoi(_saveString["51"]);
		m_bActivateGroup = atoi(_saveString["56"]) != 0;
		break;
	case 1815: // Collision Trigger
		m_nItemID = atoi(_saveString["80"]);
		m_nBBlockID = atoi(_saveString["95"]);
		m_nTargetGroupID = atoi(_saveString["51"]);
		m_fDuration = strtod(_saveString["10"], nullptr);
		m_bTriggerOnExit = atoi(_saveString["93"]) != 0;
		m_bActivateGroup = atoi(_saveString["56"]) != 0;
		break;
	case 1817: // Pickup Trigger
		m_nItemID = atoi(_saveString["80"]);
		m_nCount = atoi(_saveString["77"]);
		m_nTargetGroupID = atoi(_saveString["51"]);
		m_bActivateGroup = atoi(_saveString["56"]) != 0;
		break;
	case 1811: // Instant Count Trigger
		m_nItemID = atoi(_saveString["80"]);
		m_nTargetGroupID = atoi(_saveString["51"]);
		m_nCount = atoi(_saveString["77"]);
		m_bActivateGroup = atoi(_saveString["56"]) != 0;
		break;
	case 1616: // Stop Trigger
		m_nTargetGroupID = atoi(_saveString["51"]);
		break;
	case 1268: // Spawn Trigger
		m_nTargetGroupID = atoi(_saveString["51"]);
		m_fSpawnDelay = strtod(_saveString["63"], nullptr);
		m_bEditorDisable = atoi(_saveString["102"]) != 0;
		break;
	case 1614: // Pickup Coin
		m_nTargetGroupID = atoi(_saveString["51"]);
		m_bSubtractCount = atoi(_saveString["78"]) != 0;
		m_ePickupMode = static_cast<PickupMode>(atoi(_saveString["79"]));
		m_nItemID = atoi(_saveString["80"]);
		m_bActivateGroup = atoi(_saveString["56"]) != 0;
		break;
	case 901: // Move Trigger
		m_nTargetGroupID = atoi(_saveString["51"]);
		m_obOffset.x = atoi(_saveString["28"]);
		m_obOffset.y = atoi(_saveString["29"]);
		m_fDuration = strtod(_saveString["10"], nullptr);
		m_eEasingType = static_cast<EasingType>(atoi(_saveString["30"]));
		m_fEasingRate = strtod(_saveString["85"], nullptr);
		m_bLockPlayerX = atoi(_saveString["58"]) != 0;
		m_bLockPlayerY = atoi(_saveString["59"]) != 0;
		m_bEnableUseTarget = atoi(_saveString["100"]) != 0;
		m_nSecondaryGroupID = atoi(_saveString["71"]);
		m_eTargetPosCoordinates = atoi(_saveString["101"]);
		break;

	case 1006: // Pulse Trigger
		m_nTargetGroupID = atoi(_saveString["51"]);
		m_fFadeIn = strtod(_saveString["45"], nullptr);
		m_fHold = strtod(_saveString["46"], nullptr);
		m_fFadeOut = strtod(_saveString["47"], nullptr);
		m_ePulseMode = atoi(_saveString["48"]);
		m_bMainOnly = atoi(_saveString["65"]) != 0;
		m_bDetailOnly = atoi(_saveString["66"]) != 0;
		m_ePulseTargetType = atoi(_saveString["52"]);
		m_bExclusive = atoi(_saveString["86"]) != 0;
		if (m_ePulseMode)
		{
			m_CopiedHSV = GameToolbox::hsvFromString(_saveString["49"], "a");
			m_nCopiedColourIdx = atoi(_saveString["50"]);
		}
		else
		{
			m_Colour.r = atoi(_saveString["7"]);
			m_Colour.g = atoi(_saveString["8"]);
			m_Colour.b = atoi(_saveString["9"]);
		}
		break;
	case 1007: // Alpha Trigger
		m_nTargetGroupID = atoi(_saveString["51"]);
		m_fDuration = strtod(_saveString["10"], nullptr);
		m_fOpacity = strtod(_saveString["35"], nullptr);
		break;
	case 915: // Line Col Trigger
		m_Colour.r = atoi(_saveString["7"]);
		m_Colour.g = atoi(_saveString["8"]);
		m_Colour.b = atoi(_saveString["9"]);
		m_fDuration = strtod(_saveString["10"], nullptr);
		m_bTintGround = atoi(_saveString["14"]) != 0;
		m_bPlayerCol1 = atoi(_saveString["15"]) != 0;
		m_bPlayerCol2 = atoi(_saveString["16"]) != 0;
		m_bBlending = atoi(_saveString["17"]) != 0;
		m_bCopyOpacity = atoi(_saveString["60"]) != 0;
		m_nColourIdx = atoi(_saveString["23"]);

		m_fOpacity = 1.0f;
		if(strtod(_saveString["36"], nullptr) <= 0 )
			m_fOpacity = strtod(_saveString["35"], nullptr); // i can't tell if this was intentional or not?

		m_CopiedHSV = GameToolbox::hsvFromString(_saveString["49"], "a");
		m_nCopiedColourIdx = atoi(_saveString["50"]);
		break;
	}
}