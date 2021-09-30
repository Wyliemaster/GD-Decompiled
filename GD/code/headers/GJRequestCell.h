#include "includes.h"

class GJRequestCell : public TableViewCell, public FLAlertLayerProtocol, public UploadPopupDelegate, public UploadActionDelegate
{
	GJUserScore* m_pScore;
	UploadActionPopup* m_pUploadPopup;
	CCMenuItemSpriteExtra* m_pToggleBtn;
};
