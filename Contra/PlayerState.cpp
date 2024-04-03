#include "PlayerState.h"
#include "Player.h"
#include "Game.h"
#include "ObjectConfig.h"
#include <dinput.h>

//Player standing func
PlayerState* PlayerStandingState::OnKeyDown(int keyCode)
{

	switch (keyCode)
	{
	case DIK_UP:
		return new PlayerGunOverHeadState(this->direction);
	case DIK_DOWN:
		return new PlayerLayingState(this->direction);
	case DIK_LEFT:
		return new PlayerRunningState(LEFT);
	case DIK_RIGHT:
		return new PlayerRunningState(RIGHT);
	case DIK_A:
		return new PlayerJumpingState(this->direction, Player::GetInstance()->GetY());
	}

	return NULL;
}

PlayerState* PlayerStandingState::OnKeyUp(int keyCode)
{
	return NULL;
}

int PlayerStandingState::GetStateAnimation()
{
	if(direction == RIGHT)
		return PLAYER_IDLE_RIGHT_ANIMATION;

	return PLAYER_IDLE_LEFT_ANIMATION;
}

void PlayerStandingState::UpdateStatus()
{
	Player* player = Player::GetInstance();
	player->SetSpeed(0, 0);
	player->SetWidthHeight(PLAYER_WIDTH, PLAYER_HEIGHT);
}

//Player running func
PlayerState* PlayerRunningState::OnKeyDown(int keyCode)
{
	switch (keyCode)
	{
	case DIK_A:
		return new PlayerJumpingState(this->direction, Player::GetInstance()->GetY());
	case DIK_LEFT:
		direction = LEFT;
		break;
	case DIK_RIGHT:
		direction = RIGHT;
		break;
	case DIK_UP:
		return new PlayerPointGunUpState(this->direction);
	case DIK_DOWN:
		return new PlayerPointGunDownState(this->direction);
	}

	return NULL;
}

PlayerState* PlayerRunningState::OnKeyUp(int keyCode)
{
	return  new PlayerStandingState(this->direction);
}

int PlayerRunningState::GetStateAnimation()
{	
	if(direction == RIGHT)
		return PLAYER_RUN_RIGHT_ANIMATION;

	return PLAYER_RUN_LEFT_ANIMATION;
}

void PlayerRunningState::UpdateStatus()
{
	Player* player = Player::GetInstance();

	if(direction == RIGHT)
		player->SetSpeed(PLAYER_START_VX, 0);

	if(direction == LEFT)
		player->SetSpeed(-PLAYER_START_VX, 0);

	player->SetWidthHeight(PLAYER_WIDTH, PLAYER_HEIGHT);
}

//Player jumping func
PlayerState* PlayerJumpingState::OnKeyDown(int keyCode)
{
	return NULL;
}

PlayerState* PlayerJumpingState::OnKeyUp(int keyCode)
{
	return NULL;
}

int PlayerJumpingState::GetStateAnimation()
{
	return PLAYER_JUMP_UP_ANIMATION;
}

void PlayerJumpingState::UpdateStatus()
{
	Player* player = Player::GetInstance();

	player->SetSpeed(player->GetVx(), PLAYER_START_VY);
	player->SetWidthHeight(PLAYER_JUMP_WIDTH, PLAYER_JUMP_HEIGHT);

	if (player->GetY() > maxJumpHeight)
		player->SetCurrentState(new PlayerFallState(this->direction));
}

//Player fall func
PlayerState* PlayerFallState::OnKeyDown(int keyCode)
{
	return NULL;
}

PlayerState* PlayerFallState::OnKeyUp(int keyCode)
{
	return NULL;
}

int PlayerFallState::GetStateAnimation()
{
	return PLAYER_JUMP_UP_ANIMATION;
}

void PlayerFallState::UpdateStatus()
{
	Player* player = Player::GetInstance();

	player->SetSpeed(player->GetVx(), -PLAYER_START_VY);
	player->SetWidthHeight(PLAYER_WIDTH, PLAYER_HEIGHT);

	if (player->IsOnGround())
	{
		player->SetCurrentState(ChangeStateAfterLanding());
		//player->SetWidthHeight(PLAYER_WIDTH, PLAYER_HEIGHT);
	}

}

PlayerState* PlayerFallState::ChangeStateAfterLanding()
{
	Game* game = Game::GetInstance();

	if (game->IsKeyDown(DIK_LEFT))
		return new PlayerRunningState(LEFT);

	if (game->IsKeyDown(DIK_RIGHT))
		return new PlayerRunningState(RIGHT);

	if (game->IsKeyDown(DIK_A))
		return new PlayerJumpingState(this->direction, Player::GetInstance()->GetY());

	return new PlayerStandingState(this->direction);
}


//Player laying func
PlayerState* PlayerLayingState::OnKeyDown(int keyCode)
{
	return NULL;
}

PlayerState* PlayerLayingState::OnKeyUp(int keyCode)
{
	if (keyCode == DIK_DOWN)
		return new PlayerStandingState(this->direction);

	return NULL;
}

int PlayerLayingState::GetStateAnimation()
{
	if(direction == RIGHT)
		return PLAYER_LAY_DOWN_RIGHT_ANIMATION;

	return PLAYER_LAY_DOWN_LEFT_ANIMATION;
}

void PlayerLayingState::UpdateStatus()
{
	Player::GetInstance()->SetSpeed(0, 0);
}

//Player gun over head func
PlayerState* PlayerGunOverHeadState::OnKeyDown(int keyCode)
{
	return NULL;
}

PlayerState* PlayerGunOverHeadState::OnKeyUp(int keyCode)
{
	if(keyCode == DIK_UP)
		return new PlayerStandingState(this->direction);

	return NULL;
}

int PlayerGunOverHeadState::GetStateAnimation()
{
	if (direction == RIGHT)
		return PLAYER_GUN_UP_RIGHT_ANIMATION;

	return PLAYER_GUN_UP_LEFT_ANIMATION;
}

void PlayerGunOverHeadState::UpdateStatus()
{
	Player::GetInstance()->SetSpeed(0, 0);
}

//Player point gun up func
PlayerState* PlayerPointGunUpState::OnKeyDown(int keyCode)
{
	return NULL;
}

PlayerState* PlayerPointGunUpState::OnKeyUp(int keyCode)
{
	switch (keyCode)
	{
	case DIK_UP:
		return new PlayerRunningState(this->direction);
	case DIK_LEFT:
		return new PlayerStandingState(LEFT);
	case DIK_RIGHT:
		return new PlayerStandingState(RIGHT);
	}

	return NULL;
}

int PlayerPointGunUpState::GetStateAnimation()
{
	if (direction == RIGHT)
		return PLAYER_GUN_TOP_RIGHT_ANIMATION;

	return PLAYER_GUN_TOP_LEFT_ANIMATION;
}

void PlayerPointGunUpState::UpdateStatus()
{
	Player* player = Player::GetInstance();

	if (direction == RIGHT)
		player->SetSpeed(PLAYER_START_VX, 0);

	if (direction == LEFT)
		player->SetSpeed(-PLAYER_START_VX, 0);
}

//Player point gun down func
PlayerState* PlayerPointGunDownState::OnKeyDown(int keyCode)
{
	return NULL;
}

PlayerState* PlayerPointGunDownState::OnKeyUp(int keyCode)
{
	switch (keyCode)
	{
	case DIK_DOWN:
		return new PlayerRunningState(this->direction);
	case DIK_LEFT:
		return new PlayerStandingState(LEFT);
	case DIK_RIGHT:
		return new PlayerStandingState(RIGHT);
	}
	return NULL;
}

int PlayerPointGunDownState::GetStateAnimation()
{
	if(direction == RIGHT)
		return PLAYER_GUN_DOWN_RIGHT_ANIMATION;
	
	return PLAYER_GUN_DOWN_LEFT_ANIMATION;
}

void PlayerPointGunDownState::UpdateStatus()
{
	Player* player = Player::GetInstance();

	if (direction == RIGHT)
		player->SetSpeed(PLAYER_START_VX, 0);

	if (direction == LEFT)
		player->SetSpeed(-PLAYER_START_VX, 0);
}


