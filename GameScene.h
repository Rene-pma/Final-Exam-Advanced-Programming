#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

    cocos2d::Sprite* _fondoLoser;
    cocos2d::Sprite* _Game;

    void GoMenu(Ref* pSender);

    cocos2d::Sprite* _formula;
    void GameScene::PasaCarro(float delta);
};

#endif // __GAME_SCENE_H__
