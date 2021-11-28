#include"Entity.h"

void Entity::Init(const Vector& pos, SDL_Texture* tex)
{
	position = pos;
	texture = tex;

	currentFrame.x = 0;
	currentFrame.y = 0;
	SDL_QueryTexture(tex, NULL, NULL, &currentFrame.w, &currentFrame.h);
}

Vector Entity::GetPos()
{
	return position;
}

void Entity::SetPos(const Vector& pos)
{
	position = pos;
}

SDL_Texture* Entity::GetTexture()
{
	return texture;
}

SDL_Rect Entity::GetCurrentFrame()
{
	return currentFrame;
}