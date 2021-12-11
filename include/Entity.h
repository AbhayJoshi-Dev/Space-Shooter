#pragma once

#include<SDL.h>

#include"Vector.h"

class Entity
{
private:
	Vector position;
	SDL_Texture* texture;
	SDL_Rect currentFrame;
public:
	Entity(const Vector& pos);
	Vector GetPos();
	void SetPos(const Vector& pos);
	SDL_Texture* GetTexture();
	SDL_Rect GetCurrentFrame();
	void SetTexture(SDL_Texture* tex);
};