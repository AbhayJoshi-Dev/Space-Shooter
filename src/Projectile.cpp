#include"Projectile.h"

Projectile::Projectile()
{
	active.reserve(50);
	inActive.reserve(50);

	for (int i = 0; i < poolIndex; i++)
	{
		inActive.emplace_back(Vector(0.f, 0.f));
	}
}

void Projectile::Init(RenderWindow& window)
{
	for (int i = 0; i < poolIndex; i++)
	{
		inActive[i].SetTexture(window.LoadTexture("res/gfx/Projectile.png"));
	}
}

Entity Projectile::Active()
{


	return Entity(Vector(0.f, 0.f));
}

void Projectile::InActive()
{

}