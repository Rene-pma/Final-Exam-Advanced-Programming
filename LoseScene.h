#ifndef __LOSE_SCENE_H__
#define __LOSE_SCENE_H__

#include "cocos2d.h"

class LoseScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(LoseScene);

    cocos2d::Sprite* _fondoLoser;
    cocos2d::Sprite* _Lost;

    void GoMenu(Ref* pSender);

    cocos2d::Sprite* _formula;
    void LoseScene::PasaCarro(float delta);
};

#endif // __LOSE_SCENE_H__
