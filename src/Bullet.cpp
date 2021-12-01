#include"Bullet.h"

void Bullet::InitBullet(const Vector& pos, SDL_Texture* tex)
{
	Init(pos, tex);
	velocity.SetLength(0.f);
	thrust.SetLength(0.0f);
}

Bullet::Bullet()
{
	thrust.SetLength(0.0f);
}

void Bullet::Update()
{
	SetPos(GetPos() + velocity);
	thrust.SetAngle(GetPos().GetAngle());
	velocity = thrust;
}