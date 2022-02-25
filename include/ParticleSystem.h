#pragma once
#include<vector>

#include"Vector.h"

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
		int colorBegin[4], colorEnd[4];
		float Rotation = 0.0f;
		float SizeBegin, SizeEnd;

		float LifeTime = 1.0f;
		float LifeRemaining = 0.0f;

		bool Active = false;
	};
	std::vector<Particle> particlePool;
	uint32_t poolIndex = 999;

public:
	ParticleSystem();

	void OnUpdate();
	void Emit(const ParticleProps& particleProps);
};