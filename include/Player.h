#pragma once

#include"Entity.h"

class Player : public Entity
{
private:
	Vector velocity;
	Vector thrust;
	float angle;
	
public:
	//Player() = default;
	void InitPlayer(const Vector& pos, SDL_Texture* tex);
	void Update();
	void Move();
	void Turn(int dir);
	float GetAngle();
};