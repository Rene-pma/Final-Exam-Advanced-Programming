#include "NewScene.h"
#include "HelloWorldScene.h"
#include "ControlScene.h"
#include "LoseScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    _fondoLoser = Sprite::create("Winner.PNG");
    _fondoLoser->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(_fondoLoser, 0);


    _Game = Sprite::create("Game.png");
    _Game->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(_Game, 1);

    auto menu_item_5 = MenuItemFont::create("GoMenu", CC_CALLBACK_1(GameScene::GoMenu, this));

    menu_item_5->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 3) * 3));

    auto* menu2 = Menu::create(menu_item_5, nullptr);
    menu2->setPosition(Point(0, 0));
    this->addChild(menu2);

    this->schedule(CC_SCHEDULE_SELECTOR(GameScene::PasaCarro), 5);

    return true;
}

void GameScene::PasaCarro(float delta)
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

void GameScene::GoMenu(cocos2d::Ref* pSender)
{
    CCLOG("GoMenu");
    auto scene = HelloWorld::createScene();
    Director::getInstance()->pushScene(scene);
}

void GameScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
