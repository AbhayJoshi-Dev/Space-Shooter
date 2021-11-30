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

	/*inline void FPS()
	{
		float currentTime = (float)SDL_GetTicks();
		float lastTime = 0.f;

		while ((currentTime - lastTime) >= 1000.f)
		{

		}
		
	}*/
}