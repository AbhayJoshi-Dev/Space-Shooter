#include"Entity.h"

Entity::Entity(const Vector& pos)
	:position(pos), texture(NULL)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	SDL_QueryTexture(texture, NULL, NULL, &currentFrame.w, &currentFrame.h);
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

void Entity::SetTexture(SDL_Texture* tex)
{
	texture = tex;
	SDL_QueryTexture(texture, NULL, NULL, &currentFrame.w, &currentFrame.h);
}