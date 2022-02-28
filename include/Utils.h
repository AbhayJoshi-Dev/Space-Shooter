#pragma once

#include<SDL.h>
#include<iostream>

namespace utils
{

	static float currentTime = 0.f;
	static float lastTime = 0.f;
	static int fps;

	inline float HireTimeInSeconds()
	{
		float t = (float)SDL_GetTicks();
		t *= 0.001f;
		return t;
	}

	inline void FPS()
	{
		currentTime = (float)SDL_GetTicks();
		if ((currentTime - lastTime) >= 1000.f)
		{
			lastTime = currentTime;
			std::cout << fps << std::endl;
			fps = 0;
		}
		fps++;
	}

	inline float DegreesToRads(float degrees)
	{
		return degrees * 3.14f / 180.f;
	}

	inline float RadsToDegrees(float Rads)
	{
		return Rads * 180.f / 3.14f;
	}

	inline float Lerp(float min, float max, float norm)
	{
		return (max - min) * norm + min;
	}

	inline int Random(int p_max, int p_min)
	{
		return (rand() % (p_max - p_min + 1)) + p_min;
	}

	inline float RandomFloat(float min, float max)
	{
		return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
	}
}