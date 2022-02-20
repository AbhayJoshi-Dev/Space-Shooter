#include<iostream>

#include"RenderWindow.h"

RenderWindow::RenderWindow()
	:window(NULL), renderer(NULL)
{

}

void RenderWindow::CreateWindow(const char* windowTitle, int w, int h)
{
	window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);

	if (window == NULL)
		std::cout << "ERROR! Failed to create window" << SDL_GetError() << std::endl;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if(renderer == NULL)
		std::cout << "ERROR! Failed to create renderer" << SDL_GetError() << std::endl;
}

SDL_Texture* RenderWindow::LoadTexture(const char* filePath)
{
	SDL_Texture* tex = NULL;

	tex = IMG_LoadTexture(renderer, filePath);

	if (tex == NULL)
		std::cout << "ERROR! Failed to load texture." << IMG_GetError() << std::endl;

	return tex;
}

void RenderWindow::Render(Entity& entity)
{
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = entity.GetCurrentFrame().w;
	src.h = entity.GetCurrentFrame().h;

	SDL_Rect dst;
	dst.x = (int)entity.GetPos().GetX();
	dst.y = (int)entity.GetPos().GetY();
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, entity.GetTexture(), &src, &dst);
}

void RenderWindow::Render(SDL_Texture* tex, float x, float y)
{
	SDL_Rect src;
	src.x = 0;
	src.y = 0;

	SDL_QueryTexture(tex, NULL, NULL, &src.w, &src.h);

	SDL_Rect dst;
	dst.x = (int)x;
	dst.y = (int)y;
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, tex, &src, &dst);
}

void RenderWindow::RenderRotate(Entity& entity, float angle)
{
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = entity.GetCurrentFrame().w;
	src.h = entity.GetCurrentFrame().h;

	SDL_Rect dst;
	dst.x = (int)entity.GetPos().GetX();
	dst.y = (int)entity.GetPos().GetY();
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopyEx(renderer, entity.GetTexture(), &src, &dst, angle, NULL, SDL_FLIP_NONE);
}

void RenderWindow::RenderScale(Entity& entity, float xScale, float yScale)
{
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = entity.GetCurrentFrame().w;
	src.h = entity.GetCurrentFrame().h;

	SDL_Rect dst;
	dst.x = (int)entity.GetPos().GetX();
	dst.y = (int)entity.GetPos().GetY();
	dst.w = src.w * xScale;
	dst.h = src.h * yScale;

	SDL_RenderCopy(renderer, entity.GetTexture(), &src, &dst);
}

int RenderWindow::GetRefreshRate()
{
	int displayIndex = SDL_GetWindowDisplayIndex(window);
	SDL_DisplayMode mode;
	SDL_GetDisplayMode(displayIndex, 0, &mode);
	return mode.refresh_rate;
}

void RenderWindow::Clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::Display()
{
	SDL_RenderPresent(renderer);
}

void RenderWindow::CleanUp()
{
	SDL_DestroyWindow(window);
}

SDL_Renderer* RenderWindow::GetRenderer()
{
	return renderer;
}