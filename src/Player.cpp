#include"Player.h"

void Player::InitPlayer(const Vector& pos, SDL_Texture* tex)
{
	Init(pos, tex);
	angle = 0.f;
}

void Player::Update()
{
	
}

void Player::Move()
{

}

void Player::Turn(int dir)
{
	if (dir == 1)
	{
		angle += 2.f;
	}
	else
	{
		angle -= 2.f;
	}
}

float Player::GetAngle()
{
	return angle;
}