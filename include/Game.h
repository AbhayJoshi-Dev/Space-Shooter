#pragma once

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

#include"RenderWindow.h"
#include"Player.h"
#include"Utils.h"

class Game
{
private:
	bool gameRunning;
	SDL_Event event;
	RenderWindow window;

	Player player;

	const float timeStep = 0.01f;
	float accumulator = 0.0f;
	float currentTime = utils::HireTimeInSeconds();
	float newTime = 0.0f;
	float frameTime = 0.0f;
	float alpha = 0.0f;
	int startTicks;
	int frameTicks;

	int mouseX, mouseY;

	bool shooting = false;
	Entity circle;
	float dx = 1.f;
	
public:
	Game();
	void Init();
	void GameLoop();
};