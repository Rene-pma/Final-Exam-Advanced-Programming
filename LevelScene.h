#ifndef __LEVEL_SCENE_H__
#define __LEVEL_SCENE_H__

#include "cocos2d.h"

class LevelScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(LevelScene);

    void Back(Ref* pSender);

    cocos2d::MenuItemFont* menu_item_1;

    cocos2d::Sprite* _car;
    cocos2d::Sprite* _fondo;
    cocos2d::Sprite* _monster;
    cocos2d::Sprite* _coin;
    cocos2d::Sprite* _coin2;
    cocos2d::Sprite* _coin3;
    cocos2d::Sprite* _taxi;
    cocos2d::Sprite* _llanta;
    cocos2d::Sprite* _globo;


    int vidas = 3;
    int monedas = 0;

    bool onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);
    bool onKeyReleased(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);

    void LevelScene::MoveMonster(float delta);
    void LevelScene::MoveCoin(float delta);
    void LevelScene::MoveCoin2(float delta);
    void LevelScene::MoveCoin3(float delta);
    void LevelScene::MoveTaxi(float delta);
    void LevelScene::MoveLlanta(float delta);
    void LevelScene::MoveLine(float delta);
    void LevelScene::MoveGlobo(float delta);

private:

    cocos2d::PhysicsWorld* sceneWorld;

    void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };

    bool onContactBegin(cocos2d::PhysicsContact& contact);
};

#endif // __LEVEL_SCENE_H__
