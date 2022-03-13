#pragma once

#include"Entity.h"
#include"RenderWindow.h"

class Projectile : public Entity
{
private:
	Vector velocity;
	float bulletSpeed;
	
public:
	Projectile(Vector pos, Vector velocity, SDL_Texture* tex);
	void Update();
};