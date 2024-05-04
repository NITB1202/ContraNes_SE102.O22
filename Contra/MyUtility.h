#pragma once
#include "GameObject.h"
#include "Runman.h"
#include "Turret.h"
#include "Ground.h"
#include "Cannon.h"
#include "Sniper.h"
#include "FlyRock.h"
#include "AutoDestroyBridge.h"
#include "Fire.h"
#include "BossStage1.h"
#include "FallRock.h"
#include "BossStage3.h"
#include "Buff.h"

#include <string>
#include <Windows.h>

#define SNIPER_OBJECT 1002
#define TURRET_OBJECT 1003
#define SNIPER_OBJECT 1004
#define CANNON_OBJECT 1005
#define FALLROCK_OBJECT 1006
#define FLYROCK_OBJECT 1007
#define FIRE_OBJECT 1008
#define BUFF_OBJECT 1009

#define GROUND_OBJECT 0
#define WATER_OBJECT 1
#define AUTO_DESTROY_BRIDGE_OBJECT 2

#define BOSS_STAGE1_OBJECT 10
#define BOSS_STAGE3_OBJECT 11

class MyUtility
{

public:

	static LPGAMEOBJECT InitObj(int type)
	{
		LPGAMEOBJECT obj = NULL;

		switch (type)
		{
		case TURRET_OBJECT:
			obj = new Turret();
			break;
		case WATER_OBJECT:
			obj = new Water();
			break;
		case SNIPER_OBJECT:
			obj = new Sniper();
			break;
		case AUTO_DESTROY_BRIDGE_OBJECT:
			obj = new AutoDestroyBridge();
			break;
		case CANNON_OBJECT:
			obj = new Cannon();
			break;
		case FALLROCK_OBJECT:
			obj = new FallRock();
			break;
		case FLYROCK_OBJECT:
			obj = new FlyRock();
			break;
		case FIRE_OBJECT:
			obj = new Fire();
			break;
		case BUFF_OBJECT:
			obj = new Buff();
			break;
		case BOSS_STAGE1_OBJECT:
			obj = new BossStage1();
			break;
		case BOSS_STAGE3_OBJECT:
			obj = new BossStage3();
			break;
		default:
			obj = new Ground();
		}

		return obj;
	}


	static int CalculateArea(RECT rect)
	{
		int width = rect.right - rect.left;
		int height = rect.top - rect.bottom;
		return width * height;
	}

	static bool IsInterger(double num) {
		return num - static_cast<int>(num) == 0;
	}

	static bool CheckIntersect(RECT rect1, RECT rect2)
	{
		bool overlapX = (rect1.left <= rect2.right) && (rect1.right >= rect2.left);
		bool overlapY = (rect1.top >= rect2.bottom) && (rect1.bottom <= rect2.top);

		return overlapX && overlapY;
	}

	static LPWSTR ConvertStringToLPWSTR(const string& str)
	{
		int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
		LPWSTR lpwstr = new WCHAR[size_needed];
		MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, lpwstr, size_needed);
		return lpwstr;
	}
};

