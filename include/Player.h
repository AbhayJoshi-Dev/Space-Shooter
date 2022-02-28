#pragma once

#include"Entity.h"
#include"ParticleSystem.h"

class Player : public Entity
{
private:
	Vector velocity;
	Vector thrust;
	float angle;

	ParticleProps particle;
	ParticleSystem particleSystem;
	
public:
	Player() = default;
	Player(const Vector& pos);
	void Update(RenderWindow& window);
	void Move(int dir);
	void Turn(int x, int y);
	float GetAngle();
	void Shoot();
};