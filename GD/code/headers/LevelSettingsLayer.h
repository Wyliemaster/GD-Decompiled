#include "includes.h"

class FLAlertLayerProtocol;
class ColorChannelSprite;
class LevelSettingsDelegate;
class CCMenuItemSpriteExtra;
class CustomSongWidget;
class LevelEditorLayer;

enum Speed
{
	kSpeedNormal = 0x0,
	kSpeedSlow = 0x1,
	kSpeedFast = 0x2,
	kSpeedFaster = 0x3,
	kSpeedFastest = 0x4,
};

class LevelSettingsLayer : public FLAlertLayer
{
	DWORD m_unkPicker;
	DWORD m_unkBackgroundAndGroundArt;
	FLAlertLayerProtocol* m_pNewgroundTOSProtocol;
	DWORD m_unkCustomSongSelect;
	int m_nSongIndex;
	Speed m_eSpeed;
	ColorChannelSprite* m_pBackgroundChannelSprite;
	ColorChannelSprite* m_pGround1ChannelSprite;
	ColorChannelSprite* m_pGround2ChannelSprite;
	ColorChannelSprite* m_pLineChannelSprite;
	ColorChannelSprite* m_pObjectChannelSprite;
	ColorChannelSprite* m_p3DChannelSprite;
	cocos2d::CCSprite* m_pColourBtnSprite;
	cocos2d::CCSprite* m_pBackgroundSprite;
	cocos2d::CCSprite* m_pGroundSprite;
	LevelSettingsObject* m_pSettingObject;
	cocos2d::CCLabelBMFont* m_pMainSongLabel;
	cocos2d::CCArray* m_pGameModeArray;
	cocos2d::CCArray* m_pSpeedArray;
	LevelSettingsDelegate* m_pLevelSettingsDelegate;
	LevelEditorLayer* m_pLevelEditorLayer;
	cocos2d::CCArray* m_pMainSongArray;
	cocos2d::CCArray* m_pBtnArray;
	CCMenuItemSpriteExtra* m_pMainSongBtn;
	CCMenuItemSpriteExtra* m_pCustomSongBtn;
	CCMenuItemSpriteExtra* m_pSelectCustomSongBtn;
	CCMenuItemSpriteExtra* m_pChangeSongBtn;
	CustomSongWidget* m_pCustomSongWidget;
};