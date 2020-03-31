#pragma once
#ifndef __GAME_OBJECT_TYPE__
#define __GAME_OBJECT_TYPE__
enum GameObjectType {
	NONE = -1,
	SHIP,
	TARGET,
	PLANET,
	MINE,
	TILE,
	GROUND,
	PLAYER,
	START_BUTTON1,
	QUIT_BUTTON,
	BASE,
	VIRUS,
	PLAY_AGAIN,
	DOOR,
	START,
	QUIT,
	NUM_OF_TYPES
};
#endif /* defined (__GAME_OBJECT_TYPE__) */