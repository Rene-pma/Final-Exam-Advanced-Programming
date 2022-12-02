#include "NewScene.h"
#include "HelloWorldScene.h"
#include "ControlScene.h"

USING_NS_CC;

Scene* ControlScene::createScene()
{
    return ControlScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool ControlScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    menu_item_2 = MenuItemFont::create("Exit", CC_CALLBACK_1(ControlScene::Exit, this));
    menu_item_2->setFontSizeObj(10);
    menu_item_2->setPosition(Point(visibleSize.width / 8, (visibleSize.height / 4) * 4));

    auto* menu = Menu::create(menu_item_2, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu, 1);

    _fondoControles = Sprite::create("FondoMenu1.PNG");
    _fondoControles->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(_fondoControles, 0);

    this->schedule(CC_SCHEDULE_SELECTOR(ControlScene::PasaCarro), 5);

    _flechaArriba = Sprite::create("Arriba.png");
    _flechaArriba->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height * 0.8));
    this->addChild(_flechaArriba, 1);

    _flechaIzquierda = Sprite::create("Izquierda.png");
    _flechaIzquierda->setPosition(Point(visibleSize.width / 3 + origin.x, visibleSize.height * 0.7));
    this->addChild(_flechaIzquierda, 1);

    _flechaDerecha = Sprite::create("Derecha.png");
    _flechaDerecha->setPosition(Point(visibleSize.width / 1.5 + origin.x, visibleSize.height * 0.7));
    this->addChild(_flechaDerecha, 1);

    return true;
}

void ControlScene::PasaCarro(float delta)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto pasarCarro = MoveBy::create(8, Vec2(2000, 0));
    Sprite* _formula = nullptr;
    _formula = Sprite::create("formula.png");
    _formula->setPosition(Vec2(-200, visibleSize.height * 0.4));
    _formula->runAction(pasarCarro);
    this->addChild(_formula);
}



void ControlScene::Exit(cocos2d::Ref* pSender)
{
    Director::getInstance()->popScene();
}




void ControlScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
