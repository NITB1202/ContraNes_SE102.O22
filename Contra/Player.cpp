#include "Player.h"

Player* Player::instance = NULL;

#define GROUND 300

void Player::SetState(int ID)
{
	state = ID;

	switch (ID)
	{
	case PLAYER_RUN_RIGHT:
		vx = PLAYER_START_VX;
		vy = 0;
		face = 1;
		break;
	case PLAYER_RUN_LEFT:
		vx = -PLAYER_START_VX;
		vy = 0;
		face = -1;
		break;
	case PLAYER_TOP_RIGHT:
		vx = PLAYER_START_VX;
		vy = 0;
		face = 1;
		break;
	case PLAYER_TOP_LEFT:
		vx = -PLAYER_START_VX;
		vy = 0;
		face = -1;
		break;
	case PLAYER_DOWN_RIGHT:
		vx = PLAYER_START_VX;
		vy = 0;
		face = 1;
		break;
	case PLAYER_DOWN_LEFT:
		vx = -PLAYER_START_VX;
		vy = 0;
		face = -1;
		break;
	case PLAYER_IDLE_RIGHT:
		vx = 0;
		vy = 0;
		face = 1;
		break;
	case PLAYER_IDLE_LEFT:
		vx = 0;
		vy = 0;
		face = -1;
		break;
	case PLAYER_GUN_UP:
		vx = 0;
		vy = 0;
		face = 1;
		break;
	case PLAYER_LAY_DOWN:
		vx = 0;
		vy = 0;
		break;
	case PLAYER_JUMP_UP:
		vy = PLAYER_START_VY;
		break;
	}

}

void Player::Update(DWORD dt)
{

	x += vx * dt; // chuyen dong thang deu khong gia toc
	y += vy * dt - 1/2*PLAYER_GRAVITY*dt*dt;
	

	//basic collision
	float camx = Camera::GetInstance()->getX();
	if (x < camx)
		x = camx ;
	
	int maxRightside = Game::GetInstance()->GetBackBufferWidth() - PLAYER_SPRITE_WIDTH;
	
	//if (x > maxRightside)
		//x = maxRightside;

	if (y > GROUND + maxJumpHeight)
	{
		vy = -PLAYER_START_VY;
	}

	if (y < GROUND)
	{
		y = GROUND;
		vy = 0;
	}
}

void Player::Render()
{

	if (face == 1)
		AniHandler.FlipSpriteHorizontal(0);
	else
		AniHandler.FlipSpriteHorizontal(1);

	switch (state)
	{
	case PLAYER_RUN_RIGHT:
		AnimationID = PLAYER_RUN_RIGHT_ANIMATION;
		break;
	case PLAYER_RUN_LEFT:
		AnimationID = PLAYER_RUN_RIGHT_ANIMATION;
		break;
	case PLAYER_TOP_RIGHT:
		AnimationID = PLAYER_TOP_RIGHT_ANIMATION;
		break;
	case PLAYER_TOP_LEFT:
		AnimationID = PLAYER_TOP_RIGHT_ANIMATION;
		break;
	case PLAYER_DOWN_RIGHT:
		AnimationID = PLAYER_DOWN_RIGHT_ANIMATION;
		break;
	case PLAYER_DOWN_LEFT:
		AnimationID = PLAYER_DOWN_RIGHT_ANIMATION;
		break;
	case PLAYER_IDLE_RIGHT:
		AnimationID = PLAYER_IDLE_RIGHT_ANIMATION;
		break;
	case PLAYER_IDLE_LEFT:
		AnimationID = PLAYER_IDLE_RIGHT_ANIMATION;
		break;
	case PLAYER_GUN_UP:
		AnimationID = PLAYER_GUN_UP;
		break;
	case PLAYER_LAY_DOWN:
		AnimationID = PLAYER_LAY_DOWN_ANIMATION;
		break;
	case PLAYER_JUMP_UP:
		if (vy == 0)
		{
			if (face == 1)
				SetState(PLAYER_IDLE_RIGHT);
			else
				SetState(PLAYER_IDLE_LEFT);
		}
		else
			AnimationID = PLAYER_JUMP_UP;
		break;
	}
	if (AnimationID == PLAYER_IDLE_RIGHT_ANIMATION || AnimationID == PLAYER_GUN_UP || AnimationID == PLAYER_LAY_DOWN_ANIMATION)
		AniHandler.setIDLE(AnimationID, x, y);
	else
		AniHandler.Render(AnimationID, x, y);
	
}

void Player::Press(int keyCode)
{
	switch (keyCode)
	{
	case DIK_UP:
		upPressed = true;
		break;
	case DIK_RIGHT:
		rightPressed = true;
		break;
	case DIK_DOWN:
		downPressed = true;
		break;
	case DIK_LEFT:
		leftPressed = true;
		break;
	}
}
void Player::Release(int keyCode)
{
	switch (keyCode)
	{
	case DIK_UP:
		upPressed = false;
		break;
	case DIK_RIGHT:
		rightPressed = false;
		break;
	case DIK_DOWN:
		downPressed = false;
		break;
	case DIK_LEFT:
		leftPressed = false;
		break;
	}
}

bool Player::IsPressed(int key)
{
	switch (key)
	{
	case DIK_UP:
		return upPressed;
	case DIK_RIGHT:
		return rightPressed;
	case DIK_DOWN:
		return downPressed;
	case DIK_LEFT:
		return leftPressed;
	}
}

Player* Player::GetInstance() 
{
	if (instance == NULL) instance = new Player();
	return instance;
}
