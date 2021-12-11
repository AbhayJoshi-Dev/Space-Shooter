#pragma once

#include"Entity.h"
#include"Bullet.h"

class Player : public Entity
{
private:
	Vector velocity;
	Vector thrust;
	float angle;
	
public:
	Player() = default;
	Player(const Vector& pos);
	void Update();
	void Move(int dir);
	void Turn(int x, int y);
	void Shoot(Bullet& e);
	float GetAngle();
};