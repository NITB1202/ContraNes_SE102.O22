#pragma once

//Define player state animation ID

#define PLAYER_IDLE_RIGHT_ANIMATION 300
#define PLAYER_IDLE_LEFT_ANIMATION 301
#define PLAYER_RUN_RIGHT_ANIMATION 302
#define PLAYER_RUN_LEFT_ANIMATION 303
#define PLAYER_GUN_UP_RIGHT_ANIMATION 304
#define PLAYER_GUN_UP_LEFT_ANIMATION 305
#define PLAYER_LAY_DOWN_RIGHT_ANIMATION 306
#define PLAYER_LAY_DOWN_LEFT_ANIMATION 307
#define PLAYER_GUN_TOP_RIGHT_ANIMATION 308
#define PLAYER_GUN_TOP_LEFT_ANIMATION 309
#define PLAYER_GUN_DOWN_RIGHT_ANIMATION 310
#define PLAYER_GUN_DOWN_LEFT_ANIMATION 311
#define PLAYER_JUMP_UP_RIGHT_ANIMATION 312
#define PLAYER_JUMP_UP_LEFT_ANIMATION 313
#define PLAYER_DIE_RIGHT_ANIMATION 314
#define PLAYER_DIE_LEFT_ANIMATION 315
#define PLAYER_LAY_DIE_RIGHT_ANIMATION 316
#define PLAYER_LAY_DIE_LEFT_ANIMATION 317
#define PLAYER_SHOOT_RUN_RIGHT_ANIMATION 318
#define PLAYER_SHOOT_RUN_LEFT_ANIMATION 319
#define PLAYER_STAND_RIGHT_SHOOT_ANIMATION 320
#define PLAYER_STAND_LEFT_SHOOT_ANIMATION 321
#define PLAYER_GUN_UP_RIGHT_SHOOT_ANIMATION 322
#define PLAYER_GUN_UP_LEFT_SHOOT_ANIMATION 323
#define PLAYER_LAY_DOWN_RIGHT_SHOOT_ANIMATION 324
#define PLAYER_LAY_DOWN_LEFT_SHOOT_ANIMATION 325
#define PLAYER_LAY_DOWN_IN_WATER_ANIMATION 326
#define PLAYER_STAND_RIGHT_IN_WATER_ANIMATION 327
#define PLAYER_STAND_LEFT_IN_WATER_ANIMATION 328
#define PLAYER_RUN_RIGHT_IN_WATER_ANIMTION 329
#define PLAYER_RUN_LEFT_IN_WATER_ANIMTION 330
#define PLAYER_SHOOT_RIGHT_IN_WATER_ANIMATION 331
#define PLAYER_SHOOT_LEFT_IN_WATER_ANIMATION 332
#define PLAYER_TOP_RIGHT_IN_WATER_ANIMATION 333
#define PLAYER_TOP_LEFT_IN_WATER_ANIMATION 334
#define PLAYER_GUN_UP_RIGHT_IN_WATER_ANIMATION 335
#define PLAYER_GUN_UP_LEFT_IN_WATER_ANIMATION 336
#define PLAYER_GUN_UP_SHOOT_RIGHT_IN_WATER_ANIMATION 337
#define PLAYER_GUN_UP_SHOOT_LEFT_IN_WATER_ANIMATION 338

//runman define
#define RUNMAN_RUN_RIGHT_ANIMATION 100
#define RUNMAN_RUN_LEFT_ANIMATION 101
#define RUNMAN_JUMP_RIGHT_ANIMATION 102
#define RUNMAN_JUMP_LEFT_ANIMATION 103
#define RUNMAN_IN_WATER_ANIMATION 104

//turret define
#define TURRET_CLOSE_ANIMATION 3000
#define TURRET_OPENING_ANIMATION 3001
#define TURRET_0_ANIMATION 3002
#define TURRET_30_ANIMATION 3003
#define TURRET_n30_ANIMATION 3004
#define TURRET_60_ANIMATION 3005
#define TURRET_n60_ANIMATION 3006
#define TURRET_90_ANIMATION 3007
#define TURRET_n90_ANIMATION 3008
#define TURRET_120_ANIMATION 3009
#define TURRET_n120_ANIMATION 3010
#define TURRET_150_ANIMATION 3011
#define TURRET_n150_ANIMATION 3012
#define TURRET_180_ANIMATION 3013

//cannon define
#define CANNON_CLOSE_ANIMATION 3300
#define CANNON_OPENING_ANIMATION 3301
#define CANNON_120_ANIMATION 3302
#define CANNON_150_ANIMATION 3303
#define CANNON_180_ANIMATION 3304

//sniper define
#define SNIPER_AMBUSH_ANIMATION 4000
#define SNIPER_HIDDEN_START_ANIMATION 4001
#define SNIPER_HIDDEN_END_ANIMATION 4002
#define SNIPER_LEFT_BASE_ANIMATION 4003
#define SNIPER_LEFT_HIGH_ANIMATION 4004
#define SNIPER_LEFT_LOW_ANIMATION 4005
#define SNIPER_RIGHT_BASE_ANIMATION 4006
#define SNIPER_RIGHT_HIGH_ANIMATION 4007
#define SNIPER_RIGHT_LOW_ANIMATION 4008
#define SNIPER_WATER_OFF 4009
#define SNIPER_WATER_ON 4010

//auto-destroy bridge define
#define BRIDGE_NORMAL_ANIMATION 200
#define BRIDGE_DESTROY1_ANIMATION 201
#define BRIDGE_DESTROY2_ANIMATION 202
#define BRIDGE_DESTROY3_ANIMATION 203
#define BRIDGE_DESTROY4_ANIMATION 204

//bullet define
#define TEXTURE_PATH_NORMAL_BULLET L"image\\Bullet\\bullet_b.png"
#define TEXTURE_PATH_TURRET_BULLET L"image\\Bullet\\TBullet.png"

#define NORMAL_BULLET 400
#define TURRET_BULLET 401
#define BOSS_BULLET 402
#define BIG_BULLET 403

//buff define
#define BUFF_BIG 0
#define BUFF_REGEN 1

#define BUFF_CLOSE_ANIMATION 5000
#define BUFF_INIT_ANIMATION 5001
#define BUFF_OPEN_ANIMATION 5002
#define BUFF_BIG_ANIMATION 5003
#define BUFF_REGEN_ANIMATION 5004
#define BUFF_SUPER_ANIMATION 5005

//asset define
#define TEXTURE_PATH_LIFE L"image\\Asset\\life.png"
#define TEXTURE_PATH_GAMEOVER_BACKGROUND L"image\\Asset\\GameOver.png"
#define TEXTURE_PATH_CURSOR L"image\\Asset\\cursor.png"
#define TEXTURE_PATH_INTRO_BACKGROUND L"image\\Asset\\intro.png"

#define LIFE_ASSET_WIDTH 28

#define PLAYER_LIFE 450
#define GAMEOVER_BACKGROUND 451
#define CURSOR 452
#define INTRO_BACKGROUND 453


//effect define
#define DIE_EFFECT_ANIMATION 500
#define EXPLODE_EFFECT_ANIMATION 501

#define EXPLODE_EFFECT_WIDTH 55
#define DIE_EFFECT_DURATION 300
#define EXPLODE_EFFECT_DURATION 300

//boss define
#define BOSS_GUN_LEFT_NORMAL_ANIMATION 601
#define BOSS_GUN_RIGHT_NORMAL_ANIMATION 602
#define BOSS_GUN_LEFT_DESTROY_ANIMATION 603
#define BOSS_GUN_RIGHT_DESTROY_ANIMATION 604
#define BOSS_DOOR_NORMAL_ANIMATION 605
#define BOSS_DOOR_DESTROY_ANIMATION 606

// List of path scene
#define MENU_PATH L"SceneInfo\\Menu.txt"
#define SCENE_PATH L"SceneInfo\\Scene.txt"

#define GAMEOVER_MENU 0
#define INTRO_MENU 1

#define GRAVITY 0.001f

#define TEXTURE_PATH_TEST L"image\\Asset\\test.png"

#define TEST 1111

enum Direction {
	LEFT = -1,
	RIGHT = 1
};

enum shootingDirection
{
	SHOOT_LEFT,
	SHOOT_RIGHT,
	SHOOT_TOP,
	SHOOT_DOWN,
	SHOOT_TOPLEFT,
	SHOOT_TOPLEFT2,
	SHOOT_TOPRIGHT,
	SHOOT_TOPRIGHT2,
	SHOOT_DOWNLEFT,
	SHOOT_DOWNLEFT2,
	SHOOT_DOWNRIGHT,
	SHOOT_DOWNRIGHT2,
	SHOOT_SNIPER_UP_LEFT,
	SHOOT_SNIPER_DOWN_LEFT,
	SHOOT_SNIPER_UP_RIGHT,
	SHOOT_SNIPER_DOWN_RIGHT,
};