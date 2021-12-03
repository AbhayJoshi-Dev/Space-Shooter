#include"Bullet.h"

void Bullet::InitBullet(const Vector& pos, SDL_Texture* tex)
{
	Init(pos, tex);
	velocity.SetLength(0.f);
	thrust.SetLength(0.0f);
	angle = 0.f;
}

void Bullet::Update()
{
	SetPos(GetPos() + velocity);
	thrust.SetAngle(angle);
	velocity = thrust;
}