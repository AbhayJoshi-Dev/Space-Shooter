#include"Game.h"

Game::Game()
	:gameRunning(true)
{
	Init();
	GameLoop();
}

void Game::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		std::cout << "ERROR! Failed to initialize SDL" << SDL_GetError() << std::endl;
	}

	window.CreateWindow("Space Shooter", 800, 600);
}

void Game::GameLoop()
{
	while (gameRunning)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					gameRunning = false;
					break;
			}
		}

		window.Clear();


		window.Display();
	}
}
