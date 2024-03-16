#pragma once
#include "GameObject.h"

#define TEXTURE_PATH_TURRET_CLOSE L"image\\Enemy\\Turret\\Turret_Close.png"
#define TEXTURE_PATH_TURRET_OPENING L"image\\Enemy\\Turret\\Turret_Opening.png"
#define TEXTURE_PATH_TURRET_0 L"image\\Enemy\\Turret\\Turret_0.png"
#define TEXTURE_PATH_TURRET_30 L"image\\Enemy\\Turret\\Turret_30.png"
#define TEXTURE_PATH_TURRET_n30 L"image\\Enemy\\Turret\\Turret_-30.png"
#define TEXTURE_PATH_TURRET_60 L"image\\Enemy\\Turret\\Turret_60.png"
#define TEXTURE_PATH_TURRET_n60 L"image\\Enemy\\Turret\\Turret_-60.png"
#define TEXTURE_PATH_TURRET_90 L"image\\Enemy\\Turret\\Turret_90.png"
#define TEXTURE_PATH_TURRET_n90 L"image\\Enemy\\Turret\\Turret_-90.png"
#define TEXTURE_PATH_TURRET_120 L"image\\Enemy\\Turret\\Turret_120.png"
#define TEXTURE_PATH_TURRET_n120 L"image\\Enemy\\Turret\\Turret_-120.png"
#define TEXTURE_PATH_TURRET_150 L"image\\Enemy\\Turret\\Turret_150.png"
#define TEXTURE_PATH_TURRET_n150 L"image\\Enemy\\Turret\\Turret_-150.png"
#define TEXTURE_PATH_TURRET_180 L"image\\Enemy\\Turret\\Turret_-180.png"

#define TURRET_SPRITE_HEIGHT 32
#define TURRET_SPRITE_WIDTH 32

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

#define T_CLOSE -1
#define T_INIT 0
#define T_OPEN 1

class Turret : public GameObject
{
public:
	int preState=0, delay = 0;
	Turret(float x, float y, float vx = 0, float vy = 0) : GameObject(x, y, vx, vy) {};
	void Render() override;
	void Update(DWORD dt) override;
	int Angle(int x1, int y1, int x2, int y2);
};