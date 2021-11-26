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