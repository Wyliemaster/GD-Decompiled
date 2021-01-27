/*
Info
Windows address: 0x20A690


todo later

*/
void __thiscall enterMirrorPortal(struct_a1 *this, bool a2)
{
    // bool v2;                                          // al
    // struct_a1 *v3;                                    // edi
    // int v4;                                           // esi
    // float Float;                                      // ST0C_4
    // cocos2d::CCSprite *playerSprite;                            // ecx
    // void(__thiscall * FlipX)(cocos2d::CCSprite *, bool); // edx

    v2 = a2;
    v3 = this;
    if (this->byte239 != a2)
    {
        v4 = this->dword0;
        this->byte239 = a2;

        Float = (*(float(__thiscall **)(void *))(v4 + 64))(this);

        (*(void(__thiscall **)(void *, int))(v4 + 60))(v3, LODWORD(Float) ^ xmmword_2F6AF0); // xmmword_2F6AF0 = 0x80000000800000008000000080000000

        v2 = a2;
    }
    playerSprite = *(cocos2d::CCSprite **)&v3[2].gap4[148];
    FlipX = cocos2d::CCSprite::setFlipX;
    if (playerSprite != 0)
    {
        cocos2d::CCSprite::setFlipX(playerSprite, v2);
        FlipX = cocos2d::CCSprite::setFlipX;
    }
    FlipX(*(cocos2d::CCSprite **)&v3[2].gap4[112], a2);
    cocos2d::CCSprite::setFlipX(*(cocos2d::CCSprite **)&v3[2].gap4[116], a2);
    cocos2d::CCSprite::setFlipX(*(cocos2d::CCSprite **)&v3[2].gap4[128], a2);
    cocos2d::CCSprite::setFlipX(*(cocos2d::CCSprite **)&v3[2].gap4[132], a2);
    cocos2d::CCSprite::setFlipX(*(cocos2d::CCSprite **)&v3[2].gap4[136], a2);
    cocos2d::CCSprite::setFlipX(*(cocos2d::CCSprite **)&v3[2].gap4[144], a2);
}
