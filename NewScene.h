#ifndef __NEW_SCENE_H__
#define __NEW_SCENE_H__

#include "cocos2d.h"

class NewScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(NewScene);

    void GoBack(Ref* pSender);

    cocos2d::MenuItemFont* menu_item_1;

    cocos2d::Sprite* _car;
    cocos2d::Sprite* _fondo;
    cocos2d::Sprite* _monster;
    cocos2d::Sprite* _coin;
    cocos2d::Sprite* _coin2;
    cocos2d::Sprite* _coin3;
    cocos2d::Sprite* _globo;
    cocos2d::Sprite* _taxi;
    cocos2d::Sprite* _llanta;

    int vidas = 5;
    int monedas = 0;

    bool onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);
    bool onKeyReleased(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);

    void NewScene::MoveMonster(float delta);
    void NewScene::MoveCoin(float delta);
    void NewScene::MoveCoin2(float delta);
    void NewScene::MoveCoin3(float delta);
    void NewScene::MoveTaxi(float delta);
    void NewScene::MoveLine(float delta);
    void NewScene::MoveGlobo(float delta);
    void NewScene::MoveLlanta(float delta);

private:

    cocos2d::PhysicsWorld* sceneWorld;

    void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };

    bool onContactBegin(cocos2d::PhysicsContact& contact);
};

#endif // __NEW_SCENE_H__
