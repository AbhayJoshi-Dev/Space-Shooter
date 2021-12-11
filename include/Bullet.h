#pragma once

#include"Entity.h"

class Bullet : public Entity
{
public:
	Bullet() = default;
	Bullet(const Vector& pos);
	Vector velocity;
	Vector thrust;

	float angle;
	void Update();
};