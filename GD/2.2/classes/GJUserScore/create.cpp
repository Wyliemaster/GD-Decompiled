/*
Notes
newKeys

27: integer
{
is found inside the ban check. 
could be related to icons or socials
no noticable change when applied in-game
}

41: Bool
{
    bundled up with accountID and MessageState
    no noticeable change when appleid in-game
}

42: String
{
    parsed after stats and right before the ban check
    nothing really comes to mind when thinking of its
    use. no noticable change when applied in-game
}

*/
#include <cocos2d>

GJUserScore *__fastcall GJUserScore::create(GJUserScore *this, cocos2d::CCDictionary *a2)
{

    v2 = this;
    if (this != 0)
    {
        sub_5D0F1C((int)v134, '1', (int)v132); // 1
        NameValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, v134);
        userName = (char *)cocos2d::CCString::getCString(NameValue);
        sub_5D0F1C((int)v87, userName, (int)v133);
        sub_5CFDD0(v134);

        sub_5D0F1C((int)oldAccountIDKey, '7', (int)v133); // 2
        oldAccountIDValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, oldAccountIDKey);
        oldAccountID = (char *)cocos2d::CCString::getCString(oldAccountIDValue);
        sub_5D0F1C((int)v88, oldAccountID, (int)v134);
        sub_5CFDD0(oldAccountIDKey);

        sub_5D0F1C((int)userIDKey, '2', (int)v134);
        userIDValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, userIDKey);
        userID = cocos2d::CCString::intValue(userIDValue);
        sub_5CFDD0(userIDKey);

        sub_5D0F1C((int)starsKey, '3', (int)v134);
        starsValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, starsKey);
        stars = cocos2d::CCString::intValue(starsValue);
        sub_5CFDD0(starsKey);

        sub_5D0F1C((int)demonsKey, '4', (int)v134);
        demonsValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, demonsKey);
        demons = cocos2d::CCString::intValue(demonsValue);
        sub_5CFDD0(demonsKey);

        sub_5D0F1C((int)leaderboardPosKey, "6", (int)v134);
        leaderboardPosValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, leaderboardPosKey);
        globalLeaderboardpos = cocos2d::CCString::intValue(leaderboardPosValue);
        sub_5CFDD0(leaderboardPosKey);

        sub_5D0F1C((int)cpKey, '8', (int)v134);
        cpValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, cpKey);
        creatorPoints = cocos2d::CCString::intValue(cpValue);
        sub_5CFDD0(cpKey);

        sub_5D0F1C((int)sCoinsKey, "13", (int)v134);
        sCoinsValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, sCoinsKey);
        secretCoins = cocos2d::CCString::intValue(sCoinsValue);
        sub_5CFDD0(sCoinsKey);

        sub_5D0F1C((int)uCoinsKey, "17", (int)v134);
        uCoinsValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, uCoinsKey);
        userCoins = cocos2d::CCString::intValue(uCoinsValue);
        sub_5CFDD0(uCoinsKey);

        sub_5D0F1C((int)v97, "46", (int)v134);
        v14 = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, v97);
        diamonds = cocos2d::CCString::intValue(v14);
        sub_5CFDD0(v97);

        sub_5D0F1C((int)iconIDKey, '9', (int)v134);
        iconIDValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, iconIDKey);
        iconID = cocos2d::CCString::intValue(iconIDValue);
        sub_5CFDD0(iconIDKey);

        sub_5D0F1C((int)colour1Key, "10", (int)v134);
        colour1Value = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, colour1Key);
        colour1 = cocos2d::CCString::intValue(colour1Value);
        sub_5CFDD0(colour1Key);

        sub_5D0F1C((int)colour2Key, "11", (int)v134);
        colour2Value = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, colour2Key);
        colour2 = cocos2d::CCString::intValue(colour2Value);
        sub_5CFDD0(colour2Key);

        sub_5D0F1C((int)iconTypeKey, "14", (int)v134);
        iconTypeValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, iconTypeKey);
        iconType = cocos2d::CCString::intValue(iconTypeValue);
        sub_5CFDD0(iconTypeKey);

        sub_5D0F1C((int)specialKey, "15", (int)v134);
        specialValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, specialKey);
        special = cocos2d::CCString::intValue(specialValue);
        sub_5CFDD0(specialKey);

        sub_5D0F1C((int)accountIDKey, "16", (int)v134);
        accountIDValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, accountIDKey);
        accountID = cocos2d::CCString::intValue(accountIDValue);
        sub_5CFDD0(accountIDKey);

        sub_5D0F1C((int)index41Key, "41", (int)v134);
        index41Value = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, index41Key);
        index41 = cocos2d::CCString::boolValue(index41Value);
        sub_5CFDD0(index41Key);

        sub_5D0F1C((int)messageStateKey, "18", (int)v134);
        messageStateValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, messageStateKey);
        messageState = cocos2d::CCString::intValue(messageStateValue);
        v28 = (GJUserScore *)sub_5CFDD0(messageStateKey);
        response = (GJUserScore *)GJUserScore::create(v28);
        sub_5D09A4(v106, v87);
        sub_5D0A70((int)&response->gap0[248], (int)v106);
        sub_5CFDD0(v106);
        sub_5D09A4(v107, v88);
        sub_5D0A70((int)&response->gap0[252], (int)v107);
        sub_5CFDD0(v107);

        response->index41 = index41;
        response->messageState = messageState;
        response->userID = userID;
        response->iconType = iconType;
        response->stars = stars;
        response->special = special;
        response->accountID = accountID;
        response->demons = demons;
        response->globalLeaderboardRank = globalLeaderboardpos;
        response->creaotrPoints = creatorPoints;
        response->secretCoins = secretCoins;
        response->userCoins = userCoins;
        response->diamonds = diamonds;
        response->iconID = iconID;
        response->colour1 = colour1;
        response->colour2 = colour2;

        sub_5D0F1C((int)v108, "42", (int)v133);
        v30 = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, v108);
        index42 = (char *)cocos2d::CCString::getCString(v30);
        sub_5D0F1C((int)v109, index42, (int)v134);

        sub_5D0A70((int)&response[1].gap0[3], (int)v109);
        sub_5CFDD0(v109);
        sub_5CFDD0(v108);

        sub_5D0F1C((int)v110, "29", (int)v134);
        v32 = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, v110);
        index29 = cocos2d::CCString::boolValue(v32);
        sub_5CFDD0(v110);

        if (index29 != 0)
        {
            /*
                if index29 (likely ban check) is equal to 1, 
                these values will be parsed. if the value is 0, 
                they will not parse and then they wont display on 
                the the users profile 
            */
            sub_5D0F1C((int)friendsStateKey, "19", (int)v134);
            friendStateValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, friendsStateKey);
            friendState = cocos2d::CCString::intValue(friendStateValue);
            sub_5CFDD0(friendsStateKey);

            sub_5D0F1C((int)commentHistoryStateKey, "50", (int)v134);
            commentHistoryStateValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, commentHistoryStateKey);
            commentHistoryState = cocos2d::CCString::intValue(commentHistoryStateValue);
            sub_5CFDD0(commentHistoryStateKey);

            sub_5D0F1C((int)YouTubeKey, "20", (int)v133);
            YouTubeValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, YouTubeKey);
            Youtube = (char *)cocos2d::CCString::getCString(YouTubeValue);
            sub_5D0F1C((int)friendsStateKey, Youtube, (int)v134);
            sub_5CFDD0(YouTubeKey);

            sub_5D0F1C((int)twitterKey, "44", (int)v133);
            twitterValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, twitterKey);
            twitter = (char *)cocos2d::CCString::getCString(twitterValue);
            sub_5D0F1C((int)commentHistoryStateKey, twitter, (int)v134);
            sub_5CFDD0(twitterKey);

            sub_5D0F1C((int)twitchKey, "45", (int)v133);
            twitchValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, twitchKey);
            twitch = (char *)cocos2d::CCString::getCString(twitchValue);
            sub_5D0F1C((int)YouTubeKey, twitch, (int)v134);
            sub_5CFDD0(twitchKey);

            sub_5D0F1C((int)cubeKey, "21", (int)v134);
            cubeValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, cubeKey);
            cube = cocos2d::CCString::intValue(cubeValue);
            sub_5CFDD0(cubeKey);

            sub_5D0F1C((int)shipKey, "22", (int)v134);
            shipValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, shipKey);
            ship = cocos2d::CCString::intValue(shipValue);
            sub_5CFDD0(shipKey);

            sub_5D0F1C((int)ballKey, "23", (int)v134);
            ballValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, ballKey);
            ball = cocos2d::CCString::intValue(ballValue);
            sub_5CFDD0(ballKey);

            sub_5D0F1C((int)birdKey, "24", (int)v134);
            birdValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, birdKey);
            bird = cocos2d::CCString::intValue(birdValue);
            sub_5CFDD0(birdKey);

            sub_5D0F1C((int)dartKey, "25", (int)v134);
            dartValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, dartKey);
            dart = cocos2d::CCString::intValue(dartValue);
            sub_5CFDD0(dartKey);

            sub_5D0F1C((int)robotKey, "26", (int)v134);
            robotValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, robotKey);
            robot = cocos2d::CCString::intValue(robotValue);
            sub_5CFDD0(robotKey);

            sub_5D0F1C((int)spiderKey, "43", (int)v134);
            spiderValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, spiderKey);
            spider = cocos2d::CCString::intValue(spiderValue);
            sub_5CFDD0(spiderKey);

            sub_5D0F1C((int)explosionKey, "48", (int)v134);
            explotionValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, explosionKey);
            explosion = cocos2d::CCString::intValue(explotionValue);
            sub_5CFDD0(explosionKey);

            sub_5D0F1C((int)index27Key, "27", (int)v134);
            index27Value = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, index27Key);
            index27 = cocos2d::CCString::intValue(index27Value);
            sub_5CFDD0(index27Key);

            sub_5D0F1C((int)glowKey, "28", (int)v134);
            glowValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, glowKey);
            glow = cocos2d::CCString::boolValue(glowValue);
            sub_5CFDD0(glowKey);

            sub_5D0F1C((int)globalRankKey, "30", (int)v134);
            globalRankValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, globalRankKey);
            globalRank = cocos2d::CCString::intValue(globalRankValue);
            sub_5CFDD0(globalRankKey);

            sub_5D0F1C((int)friendStateKey, "31", (int)v134);
            friendsStateValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, friendStateKey);
            friendsState = cocos2d::CCString::intValue(friendsStateValue);
            sub_5CFDD0(friendStateKey);

            sub_5D0F1C((int)messagesKey, "38", (int)v134);
            messagesValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, messagesKey);
            messagesState = cocos2d::CCString::intValue(messagesValue);
            sub_5CFDD0(messagesKey);

            sub_5D0F1C((int)friendRequestsKey, "39", (int)v134);
            friendRequestsValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, friendRequestsKey);
            friendRequests = cocos2d::CCString::intValue(friendRequestsValue);
            sub_5CFDD0(friendRequestsKey);

            sub_5D0F1C((int)newFriendsKey, "40", (int)v134);
            newFriendsValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, newFriendsKey);
            newFriends = cocos2d::CCString::intValue(newFriendsValue);
            sub_5CFDD0(newFriendsKey);

            sub_5D0F1C((int)modRankKey, "49", (int)v134);
            modRankValue = (cocos2d::CCString *)cocos2d::CCDictionary::valueForKey(v2, modRankKey);
            modRank = cocos2d::CCString::intValue(modRankValue);
            sub_5CFDD0(modRankKey);

            response->friendsState = friendState;
            response->commentHistoryState = commentHistoryState;
            sub_5D09A4(v132, friendsStateKey);
            sub_5D0A70((int)response->gap148, (int)v132);
            sub_5CFDD0(v132);
            sub_5D09A4(v133, commentHistoryStateKey);
            sub_5D0A70((int)&response->gap148[4], (int)v133);
            sub_5CFDD0(v133);
            sub_5D09A4(v134, YouTubeKey);
            sub_5D0A70((int)&response->gap148[8], (int)v134);
            sub_5CFDD0(v134);

            response->playerFrame = cube;
            response->playerShip = ship;
            response->playerBall = ball;
            response->playerBird = bird;
            response->playerDart = dart;
            response->playerRobot = robot;
            response->dword170 = index27;
            response->playerGlow = glow;
            response->playerSpider = spider;
            response->playerExplosion = explosion;
            response->playerModRank = modRank;
            response->GlobalRank = globalRank;
            response->friendState = friendsState;
            response->messages = messagesState;
            response->friendRequests = friendRequests;
            response->newFriends = newFriends;
            sub_5CFDD0(YouTubeKey);
            sub_5CFDD0(commentHistoryStateKey);
            sub_5CFDD0(friendsStateKey);
        }
        sub_5CFDD0(v88);
        sub_5CFDD0(v87);
        this = response;
    }
    return this;
}