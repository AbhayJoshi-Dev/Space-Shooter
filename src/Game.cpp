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

	player.InitPlayer(Vector(400.f, 300.f), window.LoadTexture("res/gfx/Player.png"));
	bullet.Init(Vector(400.f, 300.f), window.LoadTexture("res/gfx/Player_Bullet.png"));

	SDL_ShowCursor(0);
}

void Game::GameLoop()
{
	while (gameRunning)
	{
		
		utils::FPS();

		startTicks = SDL_GetTicks();

		newTime = utils::HireTimeInSeconds();
		frameTime = newTime - currentTime;
		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= timeStep)
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
						if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w)
						{
							player.Move(1);
						}

						if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s)
						{
							player.Move(-1);
						}
					}

					case SDL_MOUSEBUTTONDOWN:
					{
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							
							if (once)
							{
								once = false;
								player.Shoot(bullet);
							}
						}
					}
				}
			}
			accumulator -= timeStep;
		}

		alpha = accumulator / timeStep;

		SDL_GetMouseState(&mouseX, &mouseY);
		player.Turn(mouseX, mouseY);
		
		window.Clear();

		window.RenderRotate(player, (player.GetAngle() * 180 / 3.14f) + 90);

		if(!once)
			window.RenderRotate(bullet, bullet.angle * 180 / 3.14f);

		bullet.Update();

		player.Update();

		window.Display();

		frameTicks = SDL_GetTicks() - startTicks;
		if (frameTicks < 1000 / window.GetRefreshRate())
			SDL_Delay(1000 / window.GetRefreshRate() - frameTicks);
	}

	window.CleanUp();
}
