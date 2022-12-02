#ifndef __WIN_SCENE_H__
#define __WIN_SCENE_H__

#include "cocos2d.h"

class WinScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(WinScene);

    cocos2d::Sprite* _fondoWinner;
    cocos2d::Sprite* _level;

    void Level2(Ref* pSender);

    cocos2d::Sprite* _formula;
    void WinScene::PasaCarro(float delta);

};

#endif // __WIN_SCENE_H__
