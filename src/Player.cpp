#include"Player.h"

void Player::InitPlayer(const Vector& pos, SDL_Texture* tex)
{
	Init(pos, tex);
	angle = 0.f;
	velocity.SetLength(0.f);
	thrust.SetLength(0.001f);
}

void Player::Update()
{
	SetPos(GetPos() + velocity);

	thrust.SetAngle((angle - 90.f) * 3.14f / 180);
}

void Player::Move()
{
	velocity.AddTo(thrust);
}

void Player::Turn(int dir)
{
	if (dir == 1)
	{
		angle += 2.0f;
	}
	else
	{
		angle -= 2.0f;
	}
}

float Player::GetAngle()
{
	return angle;
}