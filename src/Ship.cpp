#include<SDL2_gfxPrimitives.h>
#include<iostream>

#include"Ship.h"
#include"Utils.h"


Ship::Ship(const Vector& pos)
	:Entity(pos), maxSpeed(1.f), ang(0.f)
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
	thrust.SetAngle(utils::DegreesToRads(ang));
	velocity.AddTo(thrust);
	//}


	std::cout << utils::RadsToDegrees(thrust.GetAngle()) << std::endl;
}

void Ship::Turn(int dir)
{
	ang = utils::RadsToDegrees(thrust.GetAngle());

	ang += 25.f;
}