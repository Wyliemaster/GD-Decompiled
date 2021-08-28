#include "includes.h"

enum GJDifficulty
{
	kGJDifficultyAuto = 0,
	kGJDifficultyEasy = 1,
	kGJDifficultyNormal = 2,
	kGJDifficultyHard = 3,
	kGJDifficultyHarder = 4,
	kGJDifficultyInsane = 5,
	kGJDifficultyDemon = 6,
	kGJDifficultyDemonEasy = 7,
	kGJDifficultyDemonMedium = 8,
	kGJDifficultyDemonInsane = 9,
	kGJDifficultyDemonExtreme = 10,
};

class GJMapPack : public cocos2d::CCNode
{
public:
	cocos2d::CCArray* m_pLevels;
	int m_nPackID;
	GJDifficulty m_eDifficulty;
	int m_nStars;
	int m_nCoins;
	std::string m_sPackName;
	std::string m_sLevels;
	cocos2d::ccColor3B m_tTextColour;
	cocos2d::ccColor3B m_tBarColour;
	int m_nMId;
	bool m_bIsGauntlet;

	GJMapPack();
	inline int getPackID();
	inline GJDifficulty getPackDifficulty();
	inline int getPackStars();
	inline int getPackCoins();
	inline cocos2d::ccColor3B getColor1();
	inline cocos2d::ccColor3B getColor2();
	inline int getM_ID();
	inline std::string getPackLevels();
	inline std::string getPackName();
	inline void setPackID(int _packID);
	inline void setPackDifficulty(GJDifficulty _diff);
	inline void setPackStars(int _stars);
	inline void setPackCoins(int _coins);
	inline void setColor1(cocos2d::ccColor3B _col);
	inline void setColor2(cocos2d::ccColor3B _col);
	inline void setPackLevels(std::string _levels);
	inline void setPackName(std::string _name);
	virtual bool init();
	static GJMapPack* create();
	static GJMapPack* create(cocos2d::CCDictionary *_dict);
	void parsePackLevels(std::string _levels);
	void parsePackColors(std::string _text, std::string _bar);
	int totalMaps();
	int completedMaps();
	bool hasCompletedMapPack();
};
