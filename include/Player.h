#pragma once

#include<vector>

#include"Entity.h"
#include"ParticleSystem.h"
#include"Projectile.h"
#include"RenderWindow.h"
#include"Utils.h"


class Player : public Entity
{
private:
	Vector velocity;
	Vector thrust;
	float angle;

	ParticleProps particle;
	ParticleSystem particleSystem;

	std::vector<Projectile> projectiles;

	SDL_Texture* projectileTexture;
	bool shootingCooldown;
	float cooldownTime;
	float previousTime;
	
public:
	Player() = default;
	Player(const Vector& pos);
	void Update(RenderWindow& window);
	void Move(int dir);
	void Turn(int x, int y);
	float GetAngle();
	void Shoot();
	void SetProjectileTexture(SDL_Texture* tex);
	std::vector<Projectile>& GetProjectiles();
};