#pragma once
#include "Map.h"
#include "BinaryTree.h"

#define MAX_SPAWN_ENEMY 3
#define SPAWN_SEPARATION 3000

class Scene
{
private:

	LPMAP background;
	LPBINARYTREE objectTree;
	vector<LPGAMEOBJECT> objectOnScreen;
	vector<LPGAMEOBJECT> randomSpawnEnemy;

	DWORD lastSpawnTime = -1;

	//float bossAreaX, bossAreaY;

public:

	Scene(LPWSTR path);

	void Update(DWORD dt);
	void Render();

	vector<LPGAMEOBJECT> GetCollidableObject(LPGAMEOBJECT obj);
	vector<LPGAMEOBJECT> GetOnScreenObject() { return objectOnScreen; }

	LPMAP GetMap() { return background; }
	LPBINARYTREE GetObjectTree() { return objectTree; }
};
typedef Scene* LPSCENE;