#include "SplashScene.h"
#include "Definitions.h"
#include "GameScene.h"

#define __PADDLE_H__



USING_NS_CC;

Scene* GameScene::createScene()
{
    
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld( )->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL );
    scene->getPhysicsWorld( )->setGravity( Vect( 0, 0 ) );
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    layer->SetPhysicsWorld( scene->getPhysicsWorld( ) );
    
    // add layer as a child to scene
    scene->addChild(layer);
    

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    
    auto backgroundSprite = Sprite::create( "background.png" );
    backgroundSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height /2 + origin.y ) );
    
    
    this->addChild( backgroundSprite );
    
    playerPaddle = Sprite::create( "PONG paddle.png");

    this->addChild( playerPaddle, 100 );
    playerPaddle->setPosition( Point ( visibleSize.width * .1, visibleSize.height * 0.5 ) );

    auto touchListener = EventListenerTouchOneByOne::create( );
    touchListener->setSwallowTouches( true );
    touchListener->onTouchBegan = CC_CALLBACK_2( GameScene::onTouchBegan, this );
    Director::getInstance( )->getEventDispatcher( )->addEventListenerWithSceneGraphPriority( touchListener, this );
    
  
    
//    SpawnPaddle(this);
    SpawnCpuPaddle(this);
    
    this->scheduleUpdate( );
    

    return true;
}


//void GameScene::SpawnPaddle( cocos2d::Layer *layer )
//{
//    
//       Size visibleSize = Director::getInstance( )->getVisibleSize( );
//       Vec2 origin = Director::getInstance( )->getVisibleOrigin( );
//       playerPaddle = Sprite::create( "PONG paddle.png");
//    
//    
//  
//
//    playerPaddle->setPosition( Point ( visibleSize.width * .1, visibleSize.height * 0.5 ) );
//    
//    auto paddleBody = PhysicsBody::createBox(Size(28.0f, 115.0f),
//                                             PhysicsMaterial(0.1f, 1.0f, 0.0f));
//        paddleBody->setCollisionBitmask( PADDLE_COLLISION_BITMASK );
//        paddleBody->setContactTestBitmask( true );
//    
//        playerPaddle->setPhysicsBody( paddleBody );
//    
//        layer->addChild( playerPaddle, 100 );
//    }

//void GameScene::moveLeft( )
//{
//    auto moveLeftAction = MoveBy::create(2, Point(  playerPaddle->getPosition( ).x , playerPaddle->getPosition( ).y + 1 ) );
//        playerPaddle->runAction( moveLeftAction );
//}

void GameScene::SpawnCpuPaddle( cocos2d::Layer *layer )
{
    
    Size visibleSize = Director::getInstance( )->getVisibleSize( );
    Vec2 origin = Director::getInstance( )->getVisibleOrigin( );
    auto cpuPaddle = Sprite::create( "PONG paddle.png");
    
    
    
    
    cpuPaddle->setPosition( Point ( visibleSize.width * .9 + origin.x, visibleSize.height * .5 + origin.y ) );
    
    auto cpuBody = PhysicsBody::createBox(Size(28.0f, 115.0f),
                                             PhysicsMaterial(0.1f, 1.0f, 0.0f));
    cpuBody->setCollisionBitmask( PADDLE_COLLISION_BITMASK );
    cpuBody->setContactTestBitmask( true );
    
    cpuPaddle->setPhysicsBody( cpuBody );
    
    layer->addChild( cpuPaddle, 100 );
}

bool GameScene::onTouchBegan( cocos2d::Touch *touch, cocos2d::Event *event )
{
    // Gets touch location
    Point touchLocation = touch->getLocationInView();
    CCLOG("touch");
    auto moveLeftAction = MoveTo::create(2, Point(0, touchLocation.y));
    playerPaddle->runAction( moveLeftAction );
    return true;
}




void GameScene::update( float dt )
{
    
}
