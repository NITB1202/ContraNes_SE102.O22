#include "Gulcan.h"

// set movement x y foreach Shooter state
void Gulcan::SetState(int ID)
{
	state = ID;

	switch (ID)
	{

	}
}

void Gulcan::Update(DWORD dt)
{
	x += vx * dt;

	int BackBufferWidth = Game::GetInstance()->GetBackBufferWidth();

	if (x <= GULCAN_SPRITE_WIDTH || x >= BackBufferWidth - GULCAN_SPRITE_WIDTH) {

		vx = -vx;

		if (x <= 0)
		{
			x = 0;
		}
		else if (x >= BackBufferWidth - GULCAN_SPRITE_WIDTH)
		{
			x = (float)(BackBufferWidth - GULCAN_SPRITE_WIDTH);
		}
	}
}

void Gulcan::Render()
{
	if (face == 1)
	{
		AniHandler.FlipSpriteHorizontal(0);
	}
	else
	{
		AniHandler.FlipSpriteHorizontal(1);
	}

	switch (state)
	{

	}

	AniHandler.Render(AnimationID, x, y);
}