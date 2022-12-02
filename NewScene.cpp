#include "NewScene.h"
#include "HelloWorldScene.h"
#include "LoseScene.h"
#include "WinScene.h"

USING_NS_CC;

Scene* NewScene::createScene()
{
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    auto layer = NewScene::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());

    scene->addChild(layer);

    return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool NewScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    menu_item_1 = MenuItemFont::create("GoBack", CC_CALLBACK_1(NewScene::GoBack, this));
    menu_item_1->setFontSizeObj(10);
    menu_item_1->setPosition(Point(visibleSize.width / 8, (visibleSize.height / 4) * 4));

    auto* menu = Menu::create(menu_item_1, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu, 1);

    auto listener = EventListenerKeyboard().create();
    listener->onKeyPressed = CC_CALLBACK_2(NewScene::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(NewScene::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(NewScene::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);


    _fondo = Sprite::create("FondoPista.png");
    _fondo->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(_fondo, 0);



    _car = Sprite::create("f.png");
    _car->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height * 0.22));
    auto carBody = PhysicsBody::createBox(_car->getContentSize(), PhysicsMaterial(0, 1, 0));
    carBody->setCollisionBitmask(1);
    carBody->setContactTestBitmask(true);
    carBody->setDynamic(false);
    _car->setPhysicsBody(carBody);
    this->addChild(_car, 2);


    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    edgeNode->setPhysicsBody(edgeBody);
    this->addChild(edgeNode);



    this->schedule(CC_SCHEDULE_SELECTOR(NewScene::MoveMonster), 4);
    this->schedule(CC_SCHEDULE_SELECTOR(NewScene::MoveCoin), 5);
    this->schedule(CC_SCHEDULE_SELECTOR(NewScene::MoveCoin2), 8);
    this->schedule(CC_SCHEDULE_SELECTOR(NewScene::MoveTaxi), 7);
    this->schedule(CC_SCHEDULE_SELECTOR(NewScene::MoveLine), 0.4);
    this->schedule(CC_SCHEDULE_SELECTOR(NewScene::MoveGlobo), 20);
    this->schedule(CC_SCHEDULE_SELECTOR(NewScene::MoveLlanta), 22);
    this->schedule(CC_SCHEDULE_SELECTOR(NewScene::MoveCoin3), 6);


    return true;
}

void NewScene::MoveMonster(float delta)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto movMonster = MoveBy::create(3, Vec2(320, -300));
    Sprite* _monster = nullptr;

    _monster = Sprite::create("Sr.png");
    _monster->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    auto monsterBody = PhysicsBody::createBox(_monster->getContentSize(), PhysicsMaterial(0, 1, 0));
    monsterBody->setCollisionBitmask(2);
    monsterBody->setContactTestBitmask(true);
    monsterBody->setDynamic(false);
    _monster->setPhysicsBody(monsterBody);

    _monster->runAction(movMonster);
    this->addChild(_monster);
}

void NewScene::MoveCoin(float delta)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto movCoin = JumpTo::create(10, Point(-150, -100), 20, 20);
    Sprite* _coin = nullptr;

    _coin = Sprite::create("Coin.png");
    _coin->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    auto coinBody = PhysicsBody::createBox(_coin->getContentSize(), PhysicsMaterial(0, 1, 0));
    coinBody->setCollisionBitmask(3);
    coinBody->setContactTestBitmask(true);
    coinBody->setDynamic(false);
    _coin->setPhysicsBody(coinBody);

    _coin->runAction(movCoin);
    this->addChild(_coin);
}

void NewScene::MoveCoin2(float delta)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto movCoin2 = JumpTo::create(10, Point(500, -100), 20, 20);
    Sprite* _coin2 = nullptr;

    _coin2 = Sprite::create("Coin2.png");
    _coin2->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    auto coinBody2 = PhysicsBody::createBox(_coin2->getContentSize(), PhysicsMaterial(0, 1, 0));
    coinBody2->setCollisionBitmask(4);
    coinBody2->setContactTestBitmask(true);
    coinBody2->setDynamic(false);
    _coin2->setPhysicsBody(coinBody2);

    _coin2->runAction(movCoin2);
    this->addChild(_coin2);
}

void NewScene::MoveCoin3(float delta)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto movCoin3 = JumpTo::create(10, Point(-5, -100), 20, 20);
    Sprite* _coin3 = nullptr;

    _coin3 = Sprite::create("Coin.png");
    _coin3->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    auto coin3Body = PhysicsBody::createBox(_coin3->getContentSize(), PhysicsMaterial(0, 1, 0));
    coin3Body->setCollisionBitmask(3);
    coin3Body->setContactTestBitmask(true);
    coin3Body->setDynamic(false);
    _coin3->setPhysicsBody(coin3Body);

    _coin3->runAction(movCoin3);
    this->addChild(_coin3);
}

void NewScene::MoveLine(float delta)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto movLine = MoveBy::create(80, Vec2(320, -18000));
    Sprite* linea = nullptr;
    linea = Sprite::create("Lineas.png");
    linea->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    linea->runAction(movLine);
    this->addChild(linea);
}


void NewScene::MoveTaxi(float delta)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto movTaxi = MoveBy::create(3, Vec2(-400, -300));
    Sprite* _taxi = nullptr;

    _taxi = Sprite::create("Taxi.png");
    _taxi->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    auto TaxiBody = PhysicsBody::createBox(_taxi->getContentSize(), PhysicsMaterial(0, 1, 0));
    TaxiBody->setCollisionBitmask(5);
    TaxiBody->setContactTestBitmask(true);
    TaxiBody->setDynamic(false);
    _taxi->setPhysicsBody(TaxiBody);

    _taxi->runAction(movTaxi);
    this->addChild(_taxi);
}

void NewScene::MoveLlanta(float delta)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto movLlanta = MoveBy::create(3, Vec2(-50, -300));
    Sprite* _llanta = nullptr;

    _llanta = Sprite::create("Llanta.png");
    _llanta->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    auto LlantaBody = PhysicsBody::createBox(_llanta->getContentSize(), PhysicsMaterial(0, 1, 0));
    LlantaBody->setCollisionBitmask(5);
    LlantaBody->setContactTestBitmask(true);
    LlantaBody->setDynamic(false);
    _llanta->setPhysicsBody(LlantaBody);

    _llanta->runAction(movLlanta);
    this->addChild(_llanta);
}



void NewScene::MoveGlobo(float delta)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto movGlobo = MoveBy::create(50, Point(2000, 0));
    Sprite* _globo = nullptr;
    _globo = Sprite::create("Globo.png");
    _globo->setPosition(Vec2(-200, visibleSize.height * 0.9));
    _globo->runAction(movGlobo);
    this->addChild(_globo, 1);
}

bool NewScene::onContactBegin(cocos2d::PhysicsContact& contact)
{
    PhysicsBody* a = contact.getShapeA()->getBody();
    PhysicsBody* b = contact.getShapeB()->getBody();


    //checar si los sprites colisionan

    if (2 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
    {
        vidas--;
        CCLOG("COLLISION HAS OCCURRED");
        a->getNode()->removeFromParent();

        if (vidas == 0)
        {
            auto scene = LoseScene::createScene();
            Director::getInstance()->replaceScene(scene);
        }
    }

    if (3 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
    {
        monedas++;
        CCLOG("COLLISION HAS OCCURRED");
        a->getNode()->removeFromParent();

        if (monedas == 10)
        {
            auto scene = WinScene::createScene();
            Director::getInstance()->replaceScene(scene);
        }
    }

    if (4 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
    {
        monedas++;
        CCLOG("COLLISION HAS OCCURRED");
        a->getNode()->removeFromParent();

        if (monedas == 10)
        {
            auto scene = WinScene::createScene();
            Director::getInstance()->replaceScene(scene);
        }
    }

    if (5 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
    {
        vidas--;
        CCLOG("COLLISION HAS OCCURRED");
        a->getNode()->removeFromParent();

        if (vidas == 0)
        {
            auto scene = LoseScene::createScene();
            Director::getInstance()->replaceScene(scene);
        }
    }

    return true;
}


void NewScene::GoBack(cocos2d::Ref* pSender)
{
    Director::getInstance()->popScene();
}


bool NewScene::onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto pos = _car->getPosition();


    if (key == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
    {
        //CCLOG("Key flecha derecha pressed");
        if (pos.x <= visibleSize.width)
        {
            auto action = RepeatForever::create(MoveBy::create(.05, Vec2(20, 0)));
            _car->runAction(action);
        }
    }

    if (key == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
    {
        //CCLOG("Key flecha izquierda pressed
        if (pos.x >= 0)
        {
            auto action = RepeatForever::create(MoveBy::create(.05, Vec2(-20, 0)));
            _car->runAction(action);
        }

    }

    if (key == EventKeyboard::KeyCode::KEY_UP_ARROW) //saltar con flecha arriba
    {
        //CCLOG("Key flecha arriba pressed
        Vec2 pos = _car->getPosition();
        auto rebote = JumpTo::create(1, Point(pos.x, pos.y), 80, 1);
        _car->runAction(rebote);

    }

    return true;
}


bool NewScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event)
{
    if (key == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
    {
        CCLOG("Key derecha pressed");
        _car->stopAllActions();

    }

    if (key == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
    {
        CCLOG("Key izauierda pressed");
        _car->stopAllActions();
    }

    return true;

}




void NewScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
