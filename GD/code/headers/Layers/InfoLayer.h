#include "includes.h"

class InfoLayer : public FLAlertLayer, LevelCommentDelegate, CommentUploadDelegate, FLAlertLayerProtocol
{
	GJGameLevel* m_pLevel;
	GJUserScore* m_pScore;
	std::string m_sCommentKey;
	LoadingCircle* m_pLoadingCircle;
	cocos2d::CCLabelBMFont* m_pPageLabel;
	cocos2d::CCLabelBMFont* m_pCommentsGoldLabel;
	GJCommentListLayer* m_pCommentList;
	CCMenuItemSpriteExtra* m_pNextPageBtn;
	CCMenuItemSpriteExtra* m_pPrevPageBtn;
	CCMenuItemSpriteExtra* m_pLikeIcon;
	CCMenuItemSpriteExtra* m_pTimeIcon;
	CCMenuItemSpriteExtra* m_pReportBtn;
	CCMenuItemSpriteExtra* m_pCommentsBtn;
	CCMenuItemSpriteExtra* m_pRefreshCommentsBtn;
	int m_nPageStartIdx;
	int m_nPageEndIdx;
	int m_nTotalItems;
	int m_nPageNumber;
	bool m_bCanUpdateUserScore;
	bool m_bCommentHistory;
};
