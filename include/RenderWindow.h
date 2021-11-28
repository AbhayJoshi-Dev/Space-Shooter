#pragma once

#include<SDL.h>
#include<SDL_image.h>

#include"Entity.h"

class RenderWindow
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	RenderWindow();
	void CreateWindow(const char* windowTitle, int w, int h);
	SDL_Texture* LoadTexture(const char* filePath);
	void Render(Entity& entity);
	void RenderRotate(Entity& entity, float angle);
	void Clear();
	void Display();
	void CleanUp();
};