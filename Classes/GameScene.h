#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
    
    void SpawnPaddle( cocos2d::Layer *layer );
    void SpawnCpuPaddle( cocos2d::Layer *layer );
    
    private:
    void SetPhysicsWorld( cocos2d::PhysicsWorld *world ) { sceneWorld = world; }
    
    cocos2d::PhysicsWorld *sceneWorld;
    
    void update( float dt );
    
//    void moveLeft (  );
//    void moveRight (  );
    cocos2d::Sprite *playerPaddle;
    cocos2d::Sprite *cpuPaddle;
    
    bool onTouchBegan( cocos2d::Touch *touch, cocos2d::Event *event );
    

   
    
    
    

    
    
};

#endif // __GAME_SCENE_H__
