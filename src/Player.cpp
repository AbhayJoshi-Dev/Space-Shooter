#include<cmath>
#include<iostream>

#include"Player.h"

Player::Player(const Vector& pos)
	:Entity(pos)
{
	angle = 0.f;
	velocity.SetLength(0.f);
	thrust.SetLength(0.05f);
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
	int tempX = x - (int)GetPos().GetX() - GetCurrentFrame().w / 2;
	int tempY = y - (int)GetPos().GetY() - GetCurrentFrame().h / 2;
	angle = (float)std::atan2(tempY, tempX);
}

float Player::GetAngle()
{
	return angle;
}

void Player::Shoot()
{
	
}