#include<SDL2_gfxPrimitives.h>
#include<iostream>

#include"Ship.h"
#include"Utils.h"


Ship::Ship(const Vector& pos)
	:Entity(pos), maxSpeed(1.f)
{
	velocity.SetLength(0.f);
	velocity.SetAngle(0.f);
	thrust.SetLength(0.001f);
	thrust.SetAngle(0.f);
}

void Ship::Update(SDL_Renderer* renderer)
{
	circleRGBA(renderer, GetPos().GetX(), GetPos().GetY(), 15, 255, 255, 255, 255);

	Vector v = GetPos();
	v.AddTo(velocity);
	SetPos(v);
	
	//if (velocity.GetLength() > maxSpeed)
	//{
		//velocity.SetLength(maxSpeed);
	//}
	//else
	//{
		velocity.AddTo(thrust);
	//}
	
}

void Ship::Turn(int dir)
{
	float ang = utils::RadsToDegrees(thrust.GetLength());

	ang += 100.f;

	thrust.SetAngle(utils::DegreesToRads(ang));

}