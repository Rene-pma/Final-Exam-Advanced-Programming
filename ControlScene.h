#ifndef __CONTROL_SCENE_H__
#define __CONTROL_SCENE_H__

#include "cocos2d.h"

class ControlScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(ControlScene);

    void Exit(Ref* pSender);

    cocos2d::MenuItemFont* menu_item_2;

    cocos2d::Sprite* _fondoControles;

    cocos2d::Sprite* _formula;
    void ControlScene::PasaCarro(float delta);

    cocos2d::Sprite* _flechaArriba;
    cocos2d::Sprite* _flechaIzquierda;
    cocos2d::Sprite* _flechaDerecha;


};

#endif // __CONTROL_SCENE_H__

