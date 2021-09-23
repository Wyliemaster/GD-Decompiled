#include "includes.h"

class DrawGridLayer : public cocos2d::CCLayer
{
	// no idea what type these guidelines will be. they're used with the ccDraw Functions in the cocos2d namespace
	void* m_pCommonLines;
	void* m_pYellowGuidelines;
	void* m_pGreenGuidelines;
	float m_fSongOffset1;
	float m_fSongOffset2;
	float m_fXPos;
	bool m_bDrawEffects;
	LevelEditorLayer* m_pEditor;
	std::string m_sGuidelineString;
	cocos2d::CCNode* m_pGrid;
	cocos2d::CCArray* m_pGuidelines;
	cocos2d::CCArray* m_pEffects;
	cocos2d::CCArray* m_pGuides;
	cocos2d::CCArray* m_pSpeedObjects1; // one is with checked speed objects, one is without
	cocos2d::CCArray* m_pSpeedObjects2;
	cocos2d::CCArray* m_pPlayerNodePoints;
	cocos2d::CCArray* m_pPlayer2NodePoints;
	double UnkDouble;
	float m_fGuidelineSpacing;
	float m_fSlowGuidelineSpacing;
	float m_fNormalGuidelineSpacing;
	float m_fFastGuidelineSpacing;
	float m_fFasterGuidelineSpacing;
	float m_fFastestGuidelineSpacing;
	bool m_pUpdatingTimeMarkers;
	bool m_bUpdatingSpeedObjects;
	float m_fGridSquareSize;
};



