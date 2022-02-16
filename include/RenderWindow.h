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
	void Render(SDL_Texture* tex, float x, float y);
	void RenderRotate(Entity& entity, float angle);
	int GetRefreshRate();
	void Clear();
	void Display();
	void CleanUp();
	SDL_Renderer* GetRenderer();
};