#ifndef __GJGAMELEVEL_H__
#define __GJGAMELEVEL_H__


/* NOTE: I put a TODO docstring 
 * next to each function that still 
 * needs to be reversed - Calloc 
 * 
 * You can help me by doing those missing 
 * functions if you wish... 
 */


#pragma once
#include "includes.h"

enum GJSong;

enum GJLength {
	kGJLengthTiny = 0,
	kGJLengthShort = 1,
	kGJLengthMedium = 2,
	kGJLengthLong = 3,
	kGJLengthXL = 4,
	kGJLengthPlat = 5
};

enum GJLevelType;


/* Functions Completed 38 / 41  (92.7%) */


class GJGameLevel : public cocos2d::CCNode
{
public:
	cocos2d::CCDictionary* m_lastBuildSave;
	int m_levelID_Random;
	int m_levelID_Seed;
	int m_levelID;
	std::string m_levelName;
	std::string m_levelDesc;
	std::string m_levelString;
	std::string m_creatorName;
	std::string m_recordString;
	std::string m_uploadDate;
	std::string m_updateDate;
	std::string m_unkString1;
	std::string m_unkString2;
	/* I have a strong theory this class-member 
	 * belongs to the start position camera when 
	 * a level is about to be played... */
	cocos2d::CCPoint m_unkPoint;
	int m_userID_Random;
	int m_userID_Seed;
	int m_userID;
	int m_accountID_Random;
	int m_accountID_Seed;
	int m_accountID;
	GJDifficulty m_difficulty;
	int m_audioTrack;
	int m_songID;
	int m_levelRev;
	bool m_unlisted;
	bool m_friendsOnly;
	int m_objectCount_Random;
	int m_objectCount_Seed;
	int m_objectCount;
	int m_levelIndex;
	int m_ratings;
	int m_ratingsSum;
	int m_downloads;
	bool m_isEditable;
	bool m_gauntletLevel;
	bool m_gauntletLevel2;
	int m_workingTime;
	int m_workingTime2;
	bool m_lowDetailMode;
	bool m_lowDetailModeToggled;
	bool m_selected;
	bool m_localOrSaved;
	bool m_disableShake;
	int m_isVerified_Random;
	int m_isVerified_Seed;
	bool m_isVerifiedRaw;
	bool m_isUploaded;
	bool m_hasBeenModified;
	int m_levelVersion;
	int m_gameVersion;
	int m_attempts_Random;
	int m_attempts_Seed;
	int m_attempts;
	int m_jumps_Random;
	int m_jumps_Seed;
	int m_jumps;
	int m_clicks_Random;
	int m_clicks_Seed;
	int m_clicks;
	int m_attemptTime_Random;
	int m_attemptTime_Seed;
	int m_attemptTime;
	int m_chk;
	bool m_isChkValid;
	bool m_isCompletionLegitimate;
	int m_normalPercent_Seed;
	int m_normalPercent;
	int m_normalPercent_Random;
	int m_orbCompletion_Random;
	int m_orbCompletion_Seed;
	int m_orbCompletion;
	int m_newNormalPercent_Random;
	int m_newNormalPercent_Seed;
	int m_newNormalPercent;
	int m_newNormalPercent2_Random;
	int m_newNormalPercent2_Seed;
	int m_newNormalPercent2;
	int m_practicePercent;
	int m_likes;
	int m_dislikes;
	GJLength m_levelLength;
	int m_featured;
	int m_isEpic;
	int m_levelFavorited;
	int m_levelFolder;
	int m_dailyID_Random;
	int m_dailyID_Seed;
	int m_dailyID;
	int m_demon_Random;
	int m_demon_Seed;
	int m_demon;
	int m_demonDifficulty;
	int m_stars_Random;
	int m_stars_Seed;
	int m_stars;
	int m_autoLevel;
	int m_coins;
	int m_coinsVerified_Random;
	int m_coinsVerified_Seed;
	int m_coinsVerified;
	int m_password_Random;
	int m_password_Seed;
	int m_originalLevel_Random;
	int m_originalLevel_Seed;
	int m_originalLevel;
	bool m_twoPlayerMode;
	int m_failedPasswordAttempts;
	int m_firstCoinVerified_Random;
	int m_firstCoinVerified_Seed;
	int m_firstCoinVerified;
	int m_secondCoinVerified_Random;
	int m_secondCoinVerified_Seed;
	int m_secondCoinVerified;
	int m_thirdCoinVerified_Random;
	int m_thirdCoinVerified_Seed;
	int m_thirdCoinVerified;
	int m_starsRequested;
	int m_showedSongWarning;
	int m_starRatings;
	int m_starRatingsSum;
	int m_maxStarRatings;
	int m_minStarRatings;
	int m_demonVotes;
	int m_rateStars;
	int m_rateFeature;
	std::string m_rateUser;
	bool m_dontSave;
	bool m_levelNotDownloaded;
	int m_requiredCoins;
	int m_isUnlocked;
	cocos2d::CCPoint m_lastCameraPos;
	float m_fastEditorZoom;
	int m_lastBuildTab;
	int m_lastBuildPage;
	int m_lastBuildGroupID;
	GJLevelType m_levelType;
	int m_M_ID;
	std::string m_tempName;
	std::string m_capacityString;
	bool m_highObjectsEnabled;
	int m_unlimitedObjectsEnabled;
	std::string m_personalBests;
	int m_timestamp;
	int m_unkInt;
	std::string m_songIDs;
	std::string m_sfxIDs;
	int m_54;
	int m_bestTime;
	int m_bestPoints;
	int m_k111;
	std::string m_unkString3;
	std::string m_unkString4;

	bool areCoinsVerified();
	bool canEncode();
	static GJGameLevel* create();
	static GJGameLevel* create(cocos2d::CCDictionary* dict, bool unkwnbool);
	void copyLevelInfo (GJGameLevel * LevelInfo);
	void dataLoaded(DS_Dictionary *dsdict);
	static int demonIconForDifficulty(DemonDifficultyType demonDiff);
	std::string getAudioFileName();
	long getAverageDifficulty();
	const char *getCoinKey(int unknInt);
	GJLength getLengthKey(int seconds, bool platformer);
	GJGameLevel *getListSnapshot();
	/* Might be Inlined on windows... */
	int getNormalPercent();
	std::string getUnpackedLevelDescription();
	void handleStatsConflict(GJGameLevel * otherLevel);
	bool init();
	bool isPlatformer();
	const char* lengthKeyToString(int lengthKey);
	void levelWasAltered();
	void levelWasSubmitted();
	void parseSettingsString(std::string Settings);
	void saveNewScore(int newTime, int newPoints);
	/* TODO */
	void savePercentage(int, bool, int, int, bool);
	/* TODO */
	std::vector<std::string> scoreStringToVector(std::string, std::vector<int, std::allocator<int> >&);
	/* TODO */
	std::string scoreVectorToString(std::vector<int, std::allocator<int> >&, int);
	void setAccountID(int accountID);
	void setAttempts(int attempts);
	void setAttemptTime(int attemptTime);
	void setClicks(int clicks);
	void setCoinsVerified(int coinsVerified);
	void setDailyID(int dailyID);
	void setDemon(int demon);
	void setJumps(int jumps);
	void setLevelID(int levelID);
	void setNewNormalPercent(int newNormalPercent);
	void setNewNormalPercent2(int newNormalPercent2);
	void setNormalPercent(int normalPercent);
	void setObjectCount(int objectCount);
	void setOriginalLevel(int copiedID);
	void setStars(int stars)
	bool shouldCheatReset();
	/* TODO */
	void storeNewLocalScore(int newTime, int newPoints);
	void unverifyCoins();



};

#endif // __GJGAMELEVEL_H__