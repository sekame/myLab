//
//  Meteor.hpp
//  test
//
//  Created by 박선준 on 2022/12/07.
//

#ifndef Meteor_hpp
#define Meteor_hpp

#include <stdio.h>
#include <cocos2d.h>

class Meteor : public cocos2d::Layer
{
public:
    Meteor();
    virtual ~Meteor();

    static float MeteorSpeed;
    cocos2d::Sprite * Mobject;
    float Speed;
    static Meteor* create();
    virtual bool init();
    virtual void update(float delta);
    cocos2d::Sprite * PC;
    //virtual void CheckMeteor();
    //virtual void DropMeteor();
    
};
#endif /* Meteor_hpp */
