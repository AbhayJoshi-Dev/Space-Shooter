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

void RenderWindow::Render(SDL_Texture* tex)
{
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = 16;
	src.h = 15;

	SDL_Rect dst;
	dst.x = 0;
	dst.y = 0;
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, tex, &src, &dst);
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