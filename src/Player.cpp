#include<cmath>
#include<iostream>
#include<SDL.h>

#include"Player.h"
#include"Random.h"

Player::Player(const Vector& pos)
	:Entity(pos)
{
	angle = 0.f;
	velocity.SetLength(0.f);
	thrust.SetLength(0.05f);

	particle.colorBegin[0] = 254.f / 255.0f;
	particle.colorBegin[1] = 212.f / 255.f;
	particle.colorBegin[2] = 123.f / 255.f;
	particle.colorBegin[3] = 1.f;

	particle.colorEnd[0] = 254.f / 255.0f;
	particle.colorEnd[1] = 109.f / 255.f;
	particle.colorEnd[2] = 41.f / 255.f;
	particle.colorEnd[3] = 1.f;

	particle.sizeBegin = 0.5f;
	particle.sizeVariation = 0.3f;
	particle.sizeEnd = 0.0f;

	particle.lifeTime = 10.f;
	particle.velocity.SetLength(2.f);

	particle.velocityVariation = Vector(5.f, 1.f);

	particle.position = Vector(0.f, 0.f);

	particle.velocity.SetAngle(Random::Float() + 360.f);


}


void Player::Update(RenderWindow& window)
{
	(GetPos() + velocity);

	thrust.SetAngle(angle);

	for (int i = 0; i < 1; i++)
		particleSystem.Emit(particle);

	int x, y;
	SDL_GetMouseState(&x, &y);


	particle.position = Vector(x, y);

	particleSystem.OnRender(window);
	particleSystem.OnUpdate();

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
	//float tempX = GetPos().GetX() + (float)GetCurrentFrame().w / 2 + std::cos(GetAngle()) * GetCurrentFrame().h / 2;
	//float tempY = GetPos().GetY() + (float)GetCurrentFrame().h / 2 + std::sin(GetAngle()) * GetCurrentFrame().h / 2;
	
}