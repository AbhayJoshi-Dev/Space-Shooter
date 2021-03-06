#include"ParticleSystem.h"
#include"Utils.h"

ParticleSystem::ParticleSystem()
{
	particlePool.resize(1000);
}

void ParticleSystem::OnUpdate() //sdl time
{
	for (Particle& particle : particlePool)
	{
		if (!particle.active)
			continue;

		if (particle.lifeRemaining <= 0.0f)
		{
			particle.active = false;
			continue;
		}

		particle.lifeRemaining -= 0.1f; //sdl time
		Vector tempPos = particle.position;
		particle.position = tempPos + particle.velocity;
		particle.rotation += 0.01f;
	}
}

void ParticleSystem::OnRender(RenderWindow& window)
{
	for (Particle& particle : particlePool)
	{
		float life = particle.lifeRemaining / particle.lifeTime;
		for (int i = 0; i < 4; i++)
		{
			utils::Lerp(particle.colorEnd[i], particle.colorBegin[i], life);
		}

		float size = utils::Lerp(particle.sizeEnd, particle.sizeBegin, life);

		SDL_Rect rect;
		rect.x = (int)particle.position.GetX();
		rect.y = (int)particle.position.GetY();
		rect.w = 12;
		rect.h = 12;

		SDL_SetRenderDrawColor(window.GetRenderer(), 255, 255, 255, 255);

		SDL_RenderFillRect(window.GetRenderer(), &rect);

		SDL_SetRenderDrawColor(window.GetRenderer(), 0, 0, 0, 255);

	}
}

void ParticleSystem::Emit(const ParticleProps& particleProps)
{
	Particle& particle = particlePool[poolIndex];
	particle.active = true;
	particle.position = particleProps.position;
	particle.rotation = Random::Float() * 2.0f * 3.14f;

	particle.velocity = particleProps.velocity;
	particle.velocity.SetAngle(90);
	particle.velocity = particle.velocity + Vector(particleProps.velocityVariation.GetX() * (Random::Float()), particleProps.velocityVariation.GetY() * (Random::Float()));
	
	for (int i = 0; i < 4; i++)
	{
		particle.colorBegin[i] = particleProps.colorBegin[i];
		particle.colorEnd[i] = particleProps.colorEnd[i];
	}

	particle.lifeTime = particleProps.lifeTime;
	particle.lifeRemaining = particleProps.lifeTime;
	particle.sizeBegin = particleProps.sizeBegin + particleProps.sizeVariation * Random::Float();
	particle.sizeEnd = particleProps.sizeEnd;

	poolIndex = --poolIndex % particlePool.size();
}