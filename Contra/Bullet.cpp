#include "Bullet.h"
#include "ObjectConfig.h"
#include "MyUtility.h"
#include "Game.h"

bool Bullet::OutOfScreen()
{
	return !MyUtility::CheckIntersect(Camera::GetInstance()->GetBound(), this->GetCollisionBound());
}

void Bullet::SetUp()
{
	switch (shootingDirection)
	{
	case SHOOT_RIGHT:
	{
		vx = spd;
		vy = 0;
		break;
	}
	case SHOOT_LEFT:
	{
		vx = -spd;
		vy = 0;
		break;
	}
	case SHOOT_TOP:
	{
		vx = 0;
		vy = spd;
		break;
	}
	case SHOOT_TOPRIGHT:
	{
		vx = spd;
		vy = 0.5 * spd;
		break;
	}
	case SHOOT_TOPLEFT:
	{
		vx = -spd;
		vy = 0.5 * spd;
		break;
	}
	case SHOOT_DOWNRIGHT:
	{
		vx = spd;
		vy = -0.5 * spd;
		break;
	}
	case SHOOT_DOWNLEFT:
	{
		vx = -spd;
		vy = -0.5 * spd;
		break;
	}
	case SHOOT_DOWN:
	{
		vx = 0;
		vy = -spd;
		break;
	}
	}
}

void TurretBullet::SetUp()
{
	switch (shootingDirection)
	{
	case SHOOT_RIGHT:
	{
		vx = spd;
		vy = 0;
		break;
	}
	case SHOOT_LEFT:
	{
		vx = -spd;
		vy = 0;
		break;
	}
	case SHOOT_TOP:
	{
		vx = 0;
		vy = spd;
		break;
	}
	case SHOOT_DOWN:
	{
		vx = 0;
		vy = -spd;
		break;
	}
	case SHOOT_TOPLEFT:
	{
		vx = -spd;
		vy = (float)4 / 9 * -vx;
		break;
	}
	case SHOOT_TOPLEFT2:
	{
		vx = -spd;
		vy = -9 / 4 * vx;
		break;
	}
	case SHOOT_TOPRIGHT:
	{
		vx = spd;
		vy = 9 / 4 * vx;
		break;
	}
	case SHOOT_TOPRIGHT2:
	{
		vx = spd;
		vy = (float)4 / 9 * vx;
		break;
	}
	case SHOOT_DOWNRIGHT:
	{
		vx = spd;
		vy = -(float)4 / 9 * vx;
		break;
	}
	case SHOOT_DOWNRIGHT2:
	{
		vx = spd;
		vy = -9 / 4 * vx;
		break;
	}
	case SHOOT_DOWNLEFT:
	{
		vx = -spd;
		vy = 9 / 4 * vx;
		break;
	}
	case SHOOT_DOWNLEFT2:
	{
		vx = -spd;
		vy = (float)4 / 9 * vx;
		break;
	}
	case SHOOT_SNIPER_UP_LEFT:
	{
		vx = -spd;
		vy = sqrt(4 / 3 * vx * vx);
		break;
	}
	case SHOOT_SNIPER_DOWN_LEFT:
	{
		vx = -spd;
		vy = -sqrt(4 / 3 * vx * vx);
		break;
	}
	case SHOOT_SNIPER_UP_RIGHT:
	{
		vx = spd;
		vy = sqrt(4 / 3 * vx * vx);
		break;
	}
	case SHOOT_SNIPER_DOWN_RIGHT:
	{
		vx = spd;
		vy = -sqrt(4 / 3 * vx * vx);
		break;
	}

	}
}

void NormalBullet::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void NormalBullet::Render()
{
	AniHandler->Render(NORMAL_BULLET, x, y);
}

void TurretBullet::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void TurretBullet::Render()
{
	AniHandler->Render(NORMAL_BULLET, x, y);
}

void BossStage1Bullet::Update(DWORD dt)
{
	if (inExplodeAnimation && GetTickCount64() - explodeStart > EXPLODE_EFFECT_DURATION)
	{
		Delete();
		return;
	}

	if (inExplodeAnimation) return;

	vy += -0.5 * GRAVITY * dt;

	x += vx * dt;
	y += vy * dt;

	if (!inExplodeAnimation && y < 80)
	{
		inExplodeAnimation = true;
		explodeStart = GetTickCount64();
	}
}

void BossStage1Bullet::Render()
{
	if (inExplodeAnimation)
		AniHandler->Render(EXPLODE_EFFECT_ANIMATION, x, y);
	else
		AniHandler->Render(BOSS_BULLET, x, y);
}

void BigBullet::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void BigBullet::Render()
{
	AniHandler->Render(BIG_BULLET, x, y);
}

void MoonBullet::SetUp()
{
	switch (shootingDirection)
	{
	case SHOOT_DOWN:
		vx = 0;
		vy = -spd;
		break;
	case SHOOT_DOWNLEFT:
		vx = -spd/2;
		vy = -spd;
		break;
	case SHOOT_DOWNRIGHT:
		vx = spd/2;
		vy = -spd;
		break;
	}
}

void MoonBullet::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void MoonBullet::Render()
{
	AniHandler->Render(MOON_BULLET, x, y);
}