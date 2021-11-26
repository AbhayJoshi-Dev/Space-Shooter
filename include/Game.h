#pragma once

#include<iostream>
#include<SDL.h>

#include"RenderWindow.h"

class Game
{
private:
	bool gameRunning;
	SDL_Event event;
	RenderWindow window;

public:
	Game();
	void Init();
	void GameLoop();
};