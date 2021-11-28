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
		std::cout << "ERROR! Failed to initialize SDL" << SDL_GetError() << std::endl;

	if (!IMG_Init(IMG_INIT_PNG))
		std::cout << "ERROR! Failed to initialize SDL_image" << IMG_GetError() << std::endl;

	window.CreateWindow("Space Shooter", 800, 600);

	playerTexture = window.LoadTexture("res/gfx/Player.png");

	player.InitPlayer(Vector(400.f, 300.f), playerTexture);
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
				{
					gameRunning = false;
					break;
				}
				case SDL_KEYDOWN:
				{
					if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d)
					{
						player.Turn(1);
					}
					else if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a)
					{
						player.Turn(-1);
					}
				}
			}
		}

		window.Clear();

		window.RenderRotate(player, player.GetAngle());

		std::cout << player.GetAngle() << std::endl;

		player.Update();

		window.Display();
	}

	window.CleanUp();
}
