#pragma once

#include"Entity.h"

class Bullet : public Entity
{
public:
	Vector velocity;
	Vector thrust;

	Bullet();
	void InitBullet(const Vector& pos, SDL_Texture* tex);
	void Update();
};