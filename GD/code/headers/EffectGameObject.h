#include "includes.h"
// enums stolen from HJfod


class EffectGameObject : public GameObject
{
public:
	float m_fDuration;
	float m_fOpacity;
	int m_nTargetGroupID;
	int m_nSecondaryGroupID;
	float m_fShakeStrength;
	float m_fShakeInterval;
	bool m_bTintGround;
	bool m_bPlayerCol1;
	bool m_bPlayerCol2;
	bool m_bBlending;
	cocos2d::CCPoint m_obOffset;
	EasingType m_eEasingType;
	float m_fEasingRate;
	bool m_bLockPlayerX;
	bool m_bLockPlayerY;
	bool m_bEnableUseTarget;
	MoveTargetType m_eTargetPosCoordinates;
	int m_nRotationDegrees;
	int m_nRotationCycles;
	bool m_bLockObjectRotation;
	cocos2d::CCPoint m_obFollowMod
	bool UndocuementedLevelProperty74;
	float m_fFollowSpeed;
	float m_fFollowDelay;
	int m_nYOffset;
	float m_fMaxFollowSpeed;
	float m_fFadeIn;
	float m_fHold;
	float m_fFadeOut;
	int m_ePulseMode;
	int m_ePulseTargetType;
	cocos2d::_ccHSVValue m_CopiedHSV;
	int m_nCopiedColourIdx;
	bool m_bCopyOpacity;
	bool m_bMainOnly;
	bool m_bDetailOnly;
	bool m_bExclusive;
	bool m_bActivateGroup;
	bool m_bHoldMode;
	TouchToggleMode m_eToggleMode;
	bool m_bDualMode;
	int m_nAnimationID;
	float m_fSpawnDelay;
	cocos2d::CCPoint m_obSpawnPosition;
	bool m_bMultiTriggered;
	bool m_bEditorDisable;
	int m_nCount;
	bool m_bSubtractCount;
	ComparisonType m_eComparrison;
	bool m_bUnusedLevelProperty104;
	bool m_bTriggerOnExit;
	int m_nBBlockID;
	bool m_bDynamicBlock;
	int m_nItemID;
	PickupMode m_ePickupMode;
	int PAD[9];

	virtual void customObjectSetup();
	virtual void customSetup() override;
	virtual void triggerActivated(float _xPos) override;
	virtual float spawnXPosition();
	void updateSpecialColor();
	void resetSpawnTrigger();
	virtual std::string getSaveString();
	int getTargetColorIndex();
	virtual void customObjectSetup(std::map<std::string, std::string> _saveString);
};
