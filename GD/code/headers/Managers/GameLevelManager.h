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
	cocos2d::CCObject* m_pReportedLevel;
};
