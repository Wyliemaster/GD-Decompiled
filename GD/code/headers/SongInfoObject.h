#include "includes.h"

class SongInfoObject : public cocos2d::CCNode
{
	int m_nSongID;
	std::string m_sSongName;
	std::string m_sArtistName;
	std::string m_sVideoID;
	std::string m_sYouTubeChannelURL;
	std::string m_sSongLink;
	int m_nArtistID;
	float m_fSongSize;
	bool m_bIsUnloaded;
	bool m_bIsVerified; // scouted on newgrounds
	bool m_bIsBlocked;
	int m_nSongPriority;
	LevelSettingsObject* m_pLevelSettings;
};
