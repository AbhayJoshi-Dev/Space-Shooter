#include<iostream>

#include"Projectile.h"

Projectile::Projectile(Vector pos, Vector velocity, SDL_Texture* tex)
	:Entity(pos), bulletSpeed(1.f)
{
	this->velocity = velocity;
	SetTexture(tex);
}

void Projectile::Update()
{
	Vector tempPos = GetPos();
	tempPos.AddTo(velocity);
	SetPos(tempPos);
}