#pragma once

#include"Entity.h"

class Player : public Entity
{
private:
	Vector velocity;
	Vector thrust;
	float angle;
	Particles particles;
	
public:
	Player() = default;
	Player(const Vector& pos);
	void Update();
	void Move(int dir);
	void Turn(int x, int y);
	float GetAngle();
	void Shoot();
};