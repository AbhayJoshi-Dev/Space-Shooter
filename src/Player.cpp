#include<cmath>
#include<iostream>
#include<SDL.h>

#include"Player.h"
#include"Random.h"

Player::Player(const Vector& pos)
	:Entity(pos), projectileTexture(NULL), shootingCooldown(false), cooldownTime(0.5f), previousTime(0.f)
{
	angle = 0.f;
	velocity.SetLength(0.f);
	thrust.SetLength(0.05f);
}

void Player::Update(RenderWindow& window)
{
	SetPos(GetPos() + velocity);

	thrust.SetAngle(angle);

	for (int i = 0; i < projectiles.size(); i++)
	{
		projectiles[i].Update();
	}
	if (shootingCooldown && (utils::HireTimeInSeconds() - previousTime) > cooldownTime)
	{
		previousTime = utils::HireTimeInSeconds();
		shootingCooldown = false;
	}

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
	if (shootingCooldown)
		return;

	shootingCooldown = true;

	float tempX = GetPos().GetX() + GetCurrentFrame().w / 2 + std::cos(GetAngle()) * GetCurrentFrame().h / 2;
	float tempY = GetPos().GetY() + GetCurrentFrame().h / 2 + std::sin(GetAngle()) * GetCurrentFrame().h / 2;

	int w, h;
	SDL_QueryTexture(projectileTexture, NULL, NULL, &w, &h);
	tempX -= w / 2;
	tempY -= h / 2;

	Vector projectileVelocity;
	projectileVelocity.SetLength(5.f);
	projectileVelocity.SetAngle(thrust.GetAngle());

	Projectile newProjectile(Vector(tempX, tempY), projectileVelocity, projectileTexture);
	projectiles.emplace_back(newProjectile);
	//return newProjectile;
}

void Player::SetProjectileTexture(SDL_Texture* tex)
{
	projectileTexture = tex;
}

std::vector<Projectile>& Player::GetProjectiles()
{
	return projectiles;
}