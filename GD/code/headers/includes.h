#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <string>
#include <cstdlib>
#include <cocos2d.h>

#include "custom.h"
#include "GJRewardItem.h"
#include "GJRewardObject.h"
#include "GJObjectDecoder.h"
#include "GJChallengeItem.h"
#include "GJAccountManager.h"
#include "delegates.h"
#include "DialogObject.h"
#include "GJMapPack.h"
#include "GJGameLevel.h"
#include "GJBaseGameLayer.h"
#include "LevelSettingsLayer.h"
#include "LevelSettingsObject.h"
#include "ObjectToolbox.h"
#include "SetIDLayer.h"
#include "GameObject.h"
#include "EffectGameObject.h"
#include "MenuLayer.h"
#include "GJDropDownLayer.h"
#include "AccountLayer.h"
#include "AccountHelpLayer.h"
#include "AccountLoginLayer.h"
#include "AccountRegisterLayer.h"
#include "GJGarageLayer.h"
#include "SecretLayer.h"
#include "CCTextInputNode.h"
#include "AchievementManager.h"



enum GJHttpType
{
    kGJHttpTypeUploadLevel = 0x1,
    kGJHttpTypeGetOnlineLevels = 0x2,
    kGJHttpTypeGetMapPacks = 0x3,
    kGJHttpTypeDownloadLevel = 0x4,
    kGJHttpTypeUpdateLevel = 0x5,
    kGJHttpTypeRateStars = 0x6,
    kGJHttpTypeDeleteServerLevel = 0x7,
    kGJHttpTypeSetLevelStars = 0x8,
    kGJHttpTypeSetLevelFeatured = 0x9,
    kGJHttpTypeUpdateUserScore = 0xA,
    kGJHttpTypeGetLeaderboardScores = 0xB,
    kGJHttpTypeGetLevelComments = 0xC,
    kGJHttpTypeUploadComment = 0xD,
    kGJHttpTypeDeleteComment = 0xE,
    kGJHttpTypeLikeItem = 0xF,
    kGJHttpTypeRestoreItems = 0x10,
    kGJHttpTypeSubmitUserInfo = 0x11,
    kGJHttpTypeReportLevel = 0x12,
    kGJHttpTypeGetSongInfo = 0x13,
    kGJHttpTypeBackupAccount = 0x14,
    kGJHttpTypeSyncAccount = 0x15,
    kGJHttpTypeRegisterAccount = 0x16,
    kGJHttpTypeLoginAccount = 0x17,
    kGJHttpTypeUpdateDescription = 0x18,
    kGJHttpTypeGetAccountComments = 0x19,
    kGJHttpTypeUpdateAccountSettings = 0x1A,
    kGJHttpTypeGetGJUserInfo = 0x1B,
    kGJHttpTypeGetFriendRequests = 0x1C,
    kGJHttpTypeUploadFriendRequest = 0x1D,
    kGJHttpTypeDeleteFriendRequest = 0x1E,
    kGJHttpTypeAcceptFriendRequest = 0x1F,
    kGJHttpTypeReadFriendRequest = 0x20,
    kGJHttpTypeRemoveFriend = 0x21,
    kGJHttpTypeBlockUser = 0x22,
    kGJHttpTypeUnblockUser = 0x23,
    kGJHttpTypeGetUserList = 0x24,
    kGJHttpTypeGetUserMessages = 0x25,
    kGJHttpTypeDownloadUserMessage = 0x26,
    kGJHttpTypeDeleteUserMessages = 0x27,
    kGJHttpTypeUploadUserMessage = 0x28,
    kGJHttpTypeGetUsers = 0x29,
    kGJHttpTypeBanUser = 0x2A,
    kGJHttpTypeRequestUserAccess = 0x2B,
    kGJHttpTypeGetLevelSaveData = 0x2C,
    kGJHttpTypeSuggestLevelStars = 0x2D,
    kGJHttpTypeGetGJRewards = 0x2E,
    kGJHttpTypeGetGJChallenges = 0x2F,
    kGJHttpTypeGetGJDailyLevelState = 0x30,
    kGJHttpTypeUnknown49 = 0x31,
    kGJHttpTypeRateDemon = 0x32,
    kGJHttpTypeGetLevelLeaderboard = 0x33,
    kGJHttpTypeGetGauntlets = 0x34,
    kGJHttpTypeGetTopArtists = 0x35,
    kGJHttpTypeGetAccountBackupURL = 0x36,
    kGJHttpTypeGetAccountSyncURL = 0x37,
};
