#include "HelloWorldScene.h"
#include "NewScene.h"
#include "ControlScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    _mySprite = Sprite::create("FondoMenu1.png");
    _mySprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(_mySprite, 0);


    menu_item_1 = MenuItemFont::create("Play", CC_CALLBACK_1(HelloWorld::Play, this));
    menu_item_2 = MenuItemFont::create("Controls", CC_CALLBACK_1(HelloWorld::Controls, this));


    menu_item_1->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 3) * 2));
    menu_item_2->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 2) * 1));


    auto menu = Menu::create(menu_item_1, menu_item_2, nullptr);
    menu->setPosition(Point(0, 0));
    this->addChild(menu, 1);

    this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::PasaCarro), 5);




    return true;
}

void HelloWorld::PasaCarro(float delta)
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

void HelloWorld::Play(cocos2d::Ref* pSender)
{
    CCLOG("Play");
    auto scene = NewScene::createScene();
    Director::getInstance()->pushScene(scene);

}

void HelloWorld::Controls(cocos2d::Ref* pSender)
{
    CCLOG("Controls");
    auto scene = ControlScene::createScene();
    Director::getInstance()->pushScene(scene);

}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
