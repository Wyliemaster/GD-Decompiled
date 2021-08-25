#include "includes.h"

enum GJChallengeType
{
    kGJChallengeTypeUnknown = 0x0,
    kGJChallengeTypeOrb = 0x1,
    kGJChallengeTypeUserCoin = 0x2,
    kGJChallengeTypeStars = 0x3
};

class GJChallengeItem : public cocos2d::CCObject
{
public:
    GJChallengeType m_eChallengeType;
    int m_nCountSeed;
    int m_nCountRand;
    int m_nCount;
    int m_nRewardSeed;
    int m_nRewardRand;
    int m_nReward;
    int m_nGoalSeed;
    int m_nGoalRand;
    int m_nGoal;
    int m_nTimeLeft;
    bool m_bCanClaim;
    int m_nQuestPosition;
    std::string m_sQuestName;

    GJChallengeItem();
    virtual bool canEncode();
    virtual void encodeWithCoder(DS_Dictionary *_dict);
    void setCount(int _count);
    inline void setGoal(int _goal);
    inline void setReward(int _reward);
    bool GJChallengeItem::init(GJChallengeType _challengeType, int _goal, int _reward, int _timeLeft, std::string _questName);
    static GJChallengeItem *create(GJChallengeType _challengeType, int _goal, int _reward, int _timeLeft, std::string _questName);
    static GJChallengeItem *create();
    static GJChallengeItem *createFromString(std::string _string);
    void incrementCount(int _add);
    void dataLoaded(DS_Dictionary *_dict);
    GJChallengeItem *createWithCoder(DS_Dictionary *_dict);
};
