#pragma once
#include<SDL.h>

#include"Entity.h"
#include"RenderWindow.h"

namespace paticles
{
	static float dx = 0.f;
	static Entity circle;

	inline void Particles::ShootSplash(float tempX, float tempY)
	{
		dx -= 0.001f;
		float cx = utils::Lerp(0.f, circle.GetCurrentFrame().w, dx);
		float cy = utils::Lerp(0.f, circle.GetCurrentFrame().h, dx);
		circle.SetPos(Vector(tempX - cx / 2, tempY - cy / 2));
	}
}