#pragma once

#include<SDL.h>

#include"Entity.h"

class Ship : public Entity
{
private:
	Vector velocity;
	Vector thrust;
	float maxSpeed;
	float ang;
public:
	Ship(const Vector& pos);
	void Update(SDL_Renderer* renderer);
	void Turn(int dir);
};