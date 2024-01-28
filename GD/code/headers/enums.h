enum AccountError
{
    kAccountErrorUnknown = 0,
    kAccountErrorGeneric = -1,
    kAccountErrorTakenUsername = -2,
    kAccountErrorTakenEmail = -3,
    kAccountErrorInvalidUsername = -4,
    kAccountErrorInvalidPassword = -5,
    kAccountErrorInvalidEmail = -6,
    kAccountErrorPasswordsDontMatch = -7,
    kAccountErrorPasswordTooShort = -8,
    kAccountErrorUsernameTooShort = -9,
    kAccountErrorLinkedToDifferentAccount = -10,
    kAccountErrorUnk = -11,
    kAccountErrorAccountDisabled = -12,
    kAccountErrorLinkedToDifferentSteamAccount = -13,
    kAccountErrorEmailsDontMatch = -99
};

enum BackupAccountError
{
    kBackupAccountErrorUnknown = 0,
    kBackupAccountErrorGeneric = -1,
    kBackupAccountErrorLoginFailed = -2
};

enum EasingType {
	kEasingTypeNone = 0,
	kEasingTypeEaseInOut = 1,
	kEasingTypeEaseIn = 2,
	kEasingTypeEaseOut = 3,
	kEasingTypeElasticInOut = 4,
	kEasingTypeElasticIn = 5,
	kEasingTypeElasticOut = 6,
	kEasingTypeBounceInOut = 7,
	kEasingTypeBounceIn = 8,
	kEasingTypeBounceOut = 9,
	kEasingTypeExponentialInOut = 10,
	kEasingTypeExponentialIn = 11,
	kEasingTypeExponentialOut = 12,
	kEasingTypeSineInOut = 13,
	kEasingTypeSineIn = 14,
	kEasingTypeSineOut = 15,
	kEasingTypeBackInOut = 16,
	kEasingTypeBackIn = 17,
	kEasingTypeBackOut = 18,
};

enum ComparisonType {
	kComparisonTypeEquals = 0,
	kComparisonTypeLarger = 1,
	kComparisonTypeSmaller = 2,
};

enum MoveTargetType {
	kMoveTargetTypeBoth = 0,
	kMoveTargetTypeXOnly = 1,
	kMoveTargetTypeYOnly = 2,
};

enum TouchToggleMode {
	kTouchToggleModeNormal = 0,
	kTouchToggleModeToggleOn = 1,
	kTouchToggleModeToggleOff = 2,
};

enum PickupMode;

enum ButtonType {
	kButtonTypeImage = 0,
	kButtonTypeString = 1
};

enum LikeItemType {
	kLikeItemTypeLevel = 1,
	kLikeItemTypeComment = 2,
	kLikeItemTypeAccComment = 3
};

enum CommentKeyType {
	kCommentKeyTypeUserType = 0,
	kCommentKeyTypeLevelType = 1,
};

enum UserListType {
	kUserListTypeGetFriends = 0,
	kUserListTypeGetBlocked = 1
};

