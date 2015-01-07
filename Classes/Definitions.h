#ifndef __Definitions_H__
#define __Definitions_H__

#define TRANSITION_TIME 0.5

#define OBSTACLE_COLLISION_BITMASK 0x000002

#define PADDLE_COLLISION_BITMASK 0x000001

#define CC_SPRITE_RECT(sprite) CCRectMake(CC_SPRITE_LEFT(sprite), \
CC_SPRITE_BOTTOM(sprite), \
CC_SPRITE_ACTUAL_WIDTH(sprite), \
CC_SPRITE_ACTUAL_HEIGHT(sprite))


#endif // __Definitions_H__
