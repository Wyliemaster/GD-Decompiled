#include <string>

struct scoreKeeper
{
    std::string id;
    int value;
};

struct valueKeeper
{
    std::string id;
    std::string value;
};

struct reportedAchievements
{
    std::string achievementID;
    int percentage;
};

struct gameManager
{
    scoreKeeper **scoreKeeper;
    valueKeeper **valueKeeper;
    reportedAchievements **reportedAchievements;
    bool gameCenterEnabled;
    bool firstSetup;
    bool showedFirstTutorial;
    bool musicEnabled;
    bool fxEnabled;
    std::string playerUDID;
    std::string playerName;
    int playerFrame;
    int playerColour;
    int playerColour2;
    /*
    Dict info to be added
    */
    bool autoCheckpoints;
    bool showSongMarkers;
    bool showBPMMarkers;
    bool clickedGarage;
    bool clickedEditor;
    bool clickedName;
    bool showedEditorGuide;
};