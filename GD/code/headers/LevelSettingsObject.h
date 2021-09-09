#include "includes.h"

enum GameMode {};

class GJEffectManager;
class GJGameLevel;

class LevelSettingsObject : public cocos2d::CCNode
{
	GJEffectManager* m_pEffectManager;
	GameMode m_eGameMode;
	Speed m_eSpeed;
	bool m_bMini;
	bool m_bDual;
	bool m_bTwoPlayer;
	float m_fSongOffset;
	bool m_bFadeIn;
	bool m_bFadeOut;
	int m_nBackgroundID;
	int m_nGroundID;
	int m_nFontID;
	bool m_bStartPos;
	bool m_bFlipGravity;
	GJGameLevel* m_pGameLevel;
	std::string m_sGuidelineString;
	bool m_bCustomSong;
	int m_nColourPage;
	int m_nLineID;
};
