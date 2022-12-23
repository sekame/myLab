//
//  Meteor.cpp
//  test
//
//  Created by 박선준 on 2022/12/07.
//

#include "Meteor.hpp"
#include "GameScene.hpp"

USING_NS_CC;

Meteor::Meteor()
{
    init();
}

Meteor::~Meteor()
{
    
}

/*Meteor * Meteor::create(Layer * layer)
{
    Meteor* meteor = new Meteor;
    meteor->init();
    return (meteor);
}*/

bool Meteor::init()
{
       Mobject = Sprite::create("meteor.png");
       if (Mobject == nullptr)
       {
           return false;
       }
       else
       {
           // position the sprite on the center of the screen
           Mobject->setScale(0.2f);
           int randomX = cocos2d::RandomHelper::random_int(0, 900);
           int randomY = cocos2d::RandomHelper::random_int(700, 800);
           Mobject->setPosition(Vec2(randomX,randomY));
           Mobject->setVisible(true);
       }
    
    this->addChild(Mobject,4);
    Speed = cocos2d::RandomHelper::random_int(1, 4);
    scheduleUpdate();
    
    return true;
}

void Meteor::update(float delta)
{
    Mobject->setPosition(Vec2(Mobject->getPositionX(),Mobject->getPositionY() - (1.0f * Speed)));
    
    if(Mobject->getPositionY() < -100)
    {
        this->removeFromParent();
    }
    
    Rect PlayerRect = PC->getBoundingBox();
    Rect MeteorRect = Mobject->getBoundingBox();
    
    if(PlayerRect.intersectsRect(MeteorRect))
    {
        Director::getInstance()->replaceScene(GameScene::createScene());
    }
}



