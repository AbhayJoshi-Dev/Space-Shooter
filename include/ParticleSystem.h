#pragma once
#include<vector>

#include"Vector.h"
#include"RenderWindow.h"

struct ParticleProps
{
	Vector position;
	Vector velocity, velocityVariation;
	int colorBegin[4], colorEnd[4];
	float sizeBegin, sizeEnd, sizeVariation;
	float lifeTime = 1.0f;
};

class ParticleSystem
{
private:
	struct Particle
	{
		Vector position;
		Vector velocity;
		float colorBegin[4], colorEnd[4];
		float rotation = 0.0f;
		float sizeBegin, sizeEnd;

		float lifeTime = 1.0f;
		float lifeRemaining = 0.0f;

		bool active = false;
	};
	std::vector<Particle> particlePool;
	uint32_t poolIndex = 999;

public:
	ParticleSystem();

	void OnUpdate();
	void OnRender(RenderWindow& window);
	void Emit(const ParticleProps& particleProps);
};