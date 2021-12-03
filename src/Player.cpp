#include<cmath>
#include<iostream>

#include"Player.h"

void Player::InitPlayer(const Vector& pos, SDL_Texture* tex)
{
	Init(pos, tex);
	angle = 0.f;
	velocity.SetLength(0.f);
	thrust.SetLength(0.01f);
}

void Player::Update()
{
	SetPos(GetPos() + velocity);

	thrust.SetAngle(angle);
}

void Player::Move(int dir)
{
	if (dir == 1)
	{
		velocity.AddTo(thrust);
	}
	else
	{
		velocity.SubTo(thrust);
	}
	//if (velocity.GetLength() > 1.f)
	//	velocity.SetLength(1.f);
}

void Player::Turn(int x, int y)
{
	int tempX = x - (int)GetPos().GetX();
	int tempY = y - (int)GetPos().GetY();
	angle = (float)std::atan2(tempY, tempX);
}

void Player::Shoot(Bullet& bullet)
{
	bullet.SetPos(GetPos());
	bullet.thrust.SetLength(1.f);
	bullet.angle = GetAngle();
}

float Player::GetAngle()
{
	return angle;
}