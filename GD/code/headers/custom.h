#include "includes.h"

class RobertFuncs
{
public:
    static cocos2d::CCArray *splitToCCArray(std::string _string, char *_splitter);
};

namespace Globals
{
    const std::string XORMessage = "14251";
    const std::string XORLevelPass = "26364";
    const std::string XORAccountPassword = "37526";
    int ShardTypes[5] = {1, 2, 3, 4, 5};
}