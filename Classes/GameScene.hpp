//
//  GameScene.hpp
//  test
//
//  Created by 박선준 on 2022/12/06.
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "Meteor.hpp"


class GameScene : public cocos2d::Scene
{
public:
    GameScene();
    virtual ~GameScene();

    static GameScene* createScene();
    
    cocos2d::Sprite * Player;
    Meteor * M;
    int Arrow;
    int meteor_Num;
    
    float PlayerSpeed;
    
    //CREATE_FUNC(GameScene);
    static GameScene* create();
    virtual bool init();
    virtual void update(float delta);
    virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
    virtual void Released(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
    void createMeteor(float dt);
    
    
};

#endif /* GameScene_hpp */
