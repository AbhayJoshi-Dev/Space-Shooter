#include"Bullet.h"

Bullet::Bullet(const Vector& pos)
	:Entity(pos)
{
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