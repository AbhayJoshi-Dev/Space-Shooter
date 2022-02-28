#include<cmath>
#include<time.h>

#include"Game.h"


Game::Game()
	:gameRunning(true), player(Vector(400.f, 300.f)), circle(Vector(0.f, 0.f))
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

	window.CreateWindow("Space Shooter", 1280, 720);

	circle.SetTexture(window.LoadTexture("res/gfx/Circle.png"));

	player.SetTexture(window.LoadTexture("res/gfx/test5.png"));
	//SDL_ShowCursor(0);
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
						break;
					}

					case SDL_MOUSEBUTTONDOWN:
					{
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							shooting = true;
						}
						break;
					}

					case SDL_MOUSEBUTTONUP:
					{
						if (event.button.button == SDL_BUTTON_LEFT)
							shooting = false;
						break;
					}

				}
			}
			accumulator -= timeStep;
		}

		alpha = accumulator / timeStep;

		srand(static_cast <unsigned> (time(0)));

		SDL_GetMouseState(&mouseX, &mouseY);
		player.Turn(mouseX, mouseY);

		window.Clear();

		if (shooting)
			player.Shoot();

		player.Update(window);
		window.RenderRotate(player, utils::RadsToDegrees(player.GetAngle()) + 90.f);


		float tempX = player.GetPos().GetX() + player.GetCurrentFrame().w / 2 + std::cos(player.GetAngle()) * player.GetCurrentFrame().h / 2;
		float tempY = player.GetPos().GetY() + player.GetCurrentFrame().h / 2 + std::sin(player.GetAngle()) * player.GetCurrentFrame().h / 2;

		dx -= 0.001f;
		float cx = utils::Lerp(0.f, (float)circle.GetCurrentFrame().w, dx);
		float cy = utils::Lerp(0.f, (float)circle.GetCurrentFrame().h, dx);
		circle.SetPos(Vector(tempX - cx / 2, tempY - cy / 2));
		window.RenderScale(circle, utils::Lerp(0.f, 1.f, dx), utils::Lerp(0.f, 1.f, dx));

		window.Display();

		frameTicks = SDL_GetTicks() - startTicks;
		if (frameTicks < 1000 / window.GetRefreshRate())
			SDL_Delay(1000 / window.GetRefreshRate() - frameTicks);
	}

	window.CleanUp();
}
