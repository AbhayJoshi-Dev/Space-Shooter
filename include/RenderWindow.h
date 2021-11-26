#pragma once

#include<SDL.h>

class RenderWindow
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	RenderWindow();
	void CreateWindow(const char* windowTitle, int w, int h);
	void Clear();
	void Display();
	void CleanUp();
};