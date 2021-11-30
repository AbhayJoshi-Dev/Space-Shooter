#include"Player.h"

#include<iostream>

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

	thrust.SetAngle((angle - 90.f) * 3.14f / 180);
}

void Player::Move(int dir)
{
	if (velocity.GetLength() <= .9f)
	{
		if (dir == 1)
			velocity.AddTo(thrust);
		else if(dir == -1)
			velocity.SubTo(thrust);
	}

	if (velocity.GetLength() > 1.f)
		//velocity.SetLength(1.f);

	std::cout << velocity.GetLength() << std::endl;
}

void Player::Turn(int dir)
{
	if (dir == 1)
	{
		angle += 5.0f;
	}
	else
	{
		angle -= 5.0f;
	}
}

float Player::GetAngle()
{
	return angle;
}