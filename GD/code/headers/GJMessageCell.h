#include "includes.h"

class GJMessageCell : public TableViewCell, public FLAlertLayerProtocol, public UploadPopupDelegate, public UploadActionDelegate
{
	GJUserMessage* m_pMessage;
	UploadActionPopup* m_pUploadPopup;
	CCMenuItemSpriteExtra* m_pToggleBtn;
};
