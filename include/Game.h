#pragma once

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

#include"RenderWindow.h"

class Game
{
private:
	bool gameRunning;
	SDL_Event event;
	RenderWindow window;

	SDL_Texture* playerTexture;

public:
	Game();
	void Init();
	void GameLoop();
};