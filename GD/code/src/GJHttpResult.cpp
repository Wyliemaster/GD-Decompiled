#include "../headers/includes.h"

static GJHttpResult * GJHttpResult::create(bool success, std::string response, std::string tag, GJHttpType httptype){
    GJHttpResult* result = new GJHttpResult();
    if (result && result->init(success, response, tag, httptype)){
        result->autorelease();
        return result;
    }
    CC_SAFE_DELETE(result);
	return nullptr;
};

bool GJHttpResult::init(bool success, std::string response, std::string tag, GJHttpType httptype){
    bool created = cocos2d::CCNode::init();
    if (created){
        this->success = success;
        this->response = response;
        this->tag = tag;
        this->httptype = httptype;
    }
    return created;
};
