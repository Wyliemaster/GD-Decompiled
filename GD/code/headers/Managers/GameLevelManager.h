#include "includes.h"

class GameLevelManager : public cocos2d::CCNode
{
	cocos2d::CCDictionary* m_pMainLevels;
	cocos2d::CCDictionary* m_pSettings;
	cocos2d::CCDictionary* m_pSavedLevels;
	cocos2d::CCDictionary* m_pUnkDict;
	cocos2d::CCDictionary* m_pFollowedCreators;
	cocos2d::CCDictionary* m_pDownloadedLevels;
	cocos2d::CCDictionary* m_pLikes;
	cocos2d::CCDictionary* m_pRatedLevels;
	cocos2d::CCDictionary* m_pRatedDemons;
	cocos2d::CCDictionary* m_pReportedLevels;
	cocos2d::CCDictionary* m_pSavedLevelFolders;
	cocos2d::CCDictionary* m_pLocalLevelFolders;
	cocos2d::CCDictionary* m_pDailyLevels;
	int m_nStoredDailyTimer;
	int m_nStoredDailyID;
	int m_nActiveDailyID;
	DWORD unk6;
	int m_nStoredWeeklyTimer;
	int m_nStoredWeeklyID;
	int m_nActiveWeeklyID;
	cocos2d::CCDictionary* m_pGauntletLevels;
	cocos2d::CCDictionary* m_pUnkFilterMember;
	DWORD unk5;
	DWORD UnkFilterMemberValue;
	DWORD unk3;
	DWORD unk4;
	DWORD unk2;
	cocos2d::CCDictionary* m_pTimerDict;
	cocos2d::CCDictionary* m_pUsernameDict;
	cocos2d::CCDictionary* m_pUserIDDict;
	cocos2d::CCDictionary* m_pAccountIDDict;
	cocos2d::CCDictionary* m_pOnlineLevelsDict;
	cocos2d::CCDictionary* m_pPageInfoDict;
	cocos2d::CCDictionary* m_pUnkDict2;
	cocos2d::CCDictionary* m_pSavedPacksDict;
	cocos2d::CCDictionary* m_pSavedGauntletsDict;
	cocos2d::CCDictionary* m_pDLObject;
	cocos2d::CCDictionary* m_pLevelManagerDict;
	cocos2d::CCDictionary* m_pUserInfoDict;
	cocos2d::CCDictionary* m_pFriendRequestsDict;
	cocos2d::CCDictionary* m_pUserMessageDict;
	cocos2d::CCDictionary* m_pUserReplyDict;
	std::string m_sSearchKey;
	std::string m_sUnkString2;
	LeaderboardState m_eLeaderboardState;
	bool m_bUnkEditLevelLayerOnBack;

	// some of these delegates may be incorrect, i found these at 3am and havent double checked them

	OnlineListDelegate* m_pOnlineListDelegate;
	LevelDownloadDelegate* m_pLevelDownloadDelegate;
	LevelCommentDelegate* m_pLevelCommentDelegate;
	CommentUploadDelegate* m_pCommentUploadDelegate;
	LevelUploadDelegate* m_pLevelUploadDelegate;
	LevelUpdateDelegate* m_pLevelUpdateDelegate;
	LeaderboardManagerDelegate* m_pLeaderboardManagerDelegate;
	LevelDeleteDelegate* m_pLevelDeleteDelegate;
	UserInfoDelegate* m_pUserInfoDelegate;
	LevelManagerDelegate* m_pLevelManagerDelegate;
	void* m_pUnkDelegate;
	FriendRequestDelegate* m_pFriendRequestDelegate;
	MessageListDelegate* m_pMessageListDelegate;
	DownloadMessageDelegate* m_pDownloadMessageDelegate;
	UploadMessageDelegate* m_pUploadMessageDelegate;
	GJRewardDelegate* m_pGJRewardDelegate;
	GJChallengeDelegate* m_pGJChallengeDelegate;
	GJDailyLevelDelegate* m_pGJDailyLevelDelegate;
	MusicDownloadDelegate* m_pMusicDownloadDelegate;
	int m_nUnkDownload;
	DWORD unk;
	std::string m_sUnkString;
	cocos2d::CCDictionary* m_pReportedLevel;

	void handleIt(bool success, std::string _response,std::string _tag, GJHttpType httpType);
	void getLevelComments(int ID, int page, int total, int mode, CommentKeyType keytype);
	const char* getCommentKey (int ID, int page, int mode, CommentKeyType keytype);
	const char* getAccountCommentKey(int accountID, int page);
	void getAccountComments(int accountID,int page,int total);
	bool isDLActive (char * DLKey);
	void addDLToActive(const char *_tag);
	void cleanupDailyLevels();

	const char* getFriendRequestKey(bool sent, int page);
	void getFriendRequests(bool sent, int page, int total);

	const char* getGauntletKey(int key);
	const char* getGauntletSearchKey(int searchKey);
	void getGauntlets();

	/* TODO turn levelType Variable back into a GJTimedLevelType once figured out...*/
	void getGJDailyLevelState(int levelType);
	const char* getUserInfoKey(int targetAccountID);
	void getGJUserInfo(int targetAccountID);
	const char* getLenKey(int Len);	

	void getLevelSaveData();

	const char* getMapPackKey(int pack);

	const char* getPostCommentsKey(int seconds_left);
	const char* getRateStarsKey(int key);
	const char* getReportKey(int levelID);
	bool hasReportedLevel(int levelID);
	void markLevelAsReported(int levelID); /* TODO (Calloc): Reverse Engineer markLevelAsReported() */
	void reportLevel(int levelID);
	void getUsers (GJSearchObject * searhObject);

	void getTopArtists(int page,int total);
	const char* getTopArtistsKey(int key);

	void getUserList(UserListType listType);

	const char* char * getMessagesKey (bool sent, int page);
	void getUserMessages(bool getSent, int page, int total);

	/* TODO: Rervse engineer all of getBasePostString() */
	std::string getBasePostString();
	void ProcessHttpRequest(std::string _endpoint, std::string _params, std::string _tag, GJHttpType _httpType);
	int accountIDForUserID(int accountID);
	const char* getLevelKey(int levelID);
};
