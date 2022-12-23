//
//  GameScene.cpp
//  test
//
//  Created by 박선준 on 2022/12/06.
//

#include "GameScene.hpp"

USING_NS_CC;

GameScene::GameScene()
{
    CCLOG("GameScene Constructor Call\n");
}
GameScene::~GameScene()
{
    CCLOG("GameScene Destructor  Call\n");
}

GameScene* GameScene::createScene()
{
    return (create());
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

GameScene* GameScene::create()
{
    GameScene* gameScene = new GameScene;

    if (gameScene != nullptr && gameScene->init())
    {
        gameScene->autorelease();
    }
    else
    {
        //CC_SAFE_DELETE(gameScene);
        if (gameScene != nullptr)
        {
            delete gameScene;
            gameScene = nullptr;
        }
    }

    return (gameScene);
}

bool GameScene::init()
{
    if (!Scene::init())
    {
        return (false);
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto BGsprite = Sprite::create("Background.png");
    if (BGsprite == nullptr)
    {
        problemLoading("'Background.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        BGsprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        BGsprite->setScale(visibleSize.width / BGsprite->getContentSize().width, visibleSize.height / BGsprite->getContentSize().height);
        // add the sprite as a child to this layer
        this->addChild(BGsprite, 0);
    }
    
    Arrow = 0;
    PlayerSpeed = 3.0f;
    
    auto landsprite = Sprite::create("land.png");
    if (landsprite == nullptr)
    {
        problemLoading("'land.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        landsprite->setPosition(Vec2(visibleSize.width/2 + origin.x, -10 + origin.y));
        landsprite->setScale(visibleSize.width / landsprite->getContentSize().width, 0.15);
        // add the sprite as a child to this layer
        this->addChild(landsprite, 0);
    }
    
    Player = Sprite::create("Player.png");
    if (Player == nullptr)
    {
        problemLoading("'Player.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        Player->setPosition(Vec2(landsprite->getPositionX(),landsprite->getPositionY() + 130));
        Player->setScale(0.2f);
        Player->setTag(0);
        this->addChild(Player, 2);
    }
    
    this->schedule(schedule_selector(GameScene::createMeteor),1.0f);
    
    scheduleUpdate();
    
    return (true);
}

void GameScene::update(float delta)
{
    auto k_listner = EventListenerKeyboard::create();
    k_listner->onKeyReleased = CC_CALLBACK_2(GameScene::Released, this);
    k_listner->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(k_listner, this);
    
    if(Arrow == 0)
    {
        Player->setPositionX(Player->getPositionX());
    }
    else if(Arrow == 1)
    {
        if(Player->getPositionX() > 30)
        Player->setPositionX(Player->getPositionX() - PlayerSpeed);
    }
    else if(Arrow == 2)
    {
        if(Player->getPositionX() < 930)
        Player->setPositionX(Player->getPositionX() + PlayerSpeed);
    }
    
    
   // collision2DRect();
    
}

void GameScene::onKeyPressed(EventKeyboard::KeyCode keycode, Event * event){
    
    if(keycode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
    {
        Arrow = 1;
        Player->setFlippedX(true);
    }
    else if(keycode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
    {
        Arrow = 2;
        Player->setFlippedX(false);
    }
    else
        Arrow = 0;
}

void GameScene::Released(EventKeyboard::KeyCode keycode, Event * event){
   
}

void GameScene::createMeteor(float dt)
{
    M = new Meteor();
    M->PC = Player;
    this->addChild(M,3);
}
