#pragma once
#include<vector>

#include"Entity.h"
#include"RenderWindow.h"

class Projectile
{
private:
	std::vector<Entity> active;
	std::vector<Entity> inActive;
	uint32_t poolIndex = 50;

public:
	Projectile();
	void Init(RenderWindow& window);
	Entity Active();
	void InActive();
};