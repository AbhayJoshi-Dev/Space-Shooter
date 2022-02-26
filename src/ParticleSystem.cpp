#include"ParticleSystem.h"
#include"Utils.h"

ParticleSystem::ParticleSystem()
{
	particlePool.resize(1000);
}

void ParticleSystem::OnUpdate(RenderWindow& window) //sdl time
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
		particle.position = particle.position + particle.velocity;
		particle.rotation += 0.01f;


		float life = particle.lifeRemaining / particle.lifeTime;
		for (int i = 0; i < 4; i++)
		{
			utils::Lerp(particle.colorEnd[i], particle.colorBegin[i], life);
		}

		float size = utils::Lerp(particle.sizeEnd, particle.sizeBegin, life);

	}





}

void ParticleSystem::Emit(const ParticleProps& particleProps)
{
	Particle& particle = particlePool[poolIndex];
	particle.active = true;
	particle.position = particleProps.position;
	particle.rotation = utils::Random(2, 0) * 3.14f;

	particle.velocity = particleProps.velocity;
	particle.velocity = particle.velocity + Vector(particleProps.velocityVariation.GetX() * utils::Random(1, 0), particleProps.velocityVariation.GetY() * utils::Random(1, 0));
	
	for (int i = 0; i < 4; i++)
	{
		particle.colorBegin[i] = particleProps.colorBegin[i];
		particle.colorEnd[i] = particleProps.colorEnd[i];
	}

	particle.lifeTime = particleProps.lifeTime;
	particle.lifeRemaining = particleProps.lifeTime;
	particle.sizeBegin = particleProps.sizeBegin + particleProps.sizeVariation * utils::Random(1, 0);
	particle.sizeEnd = particleProps.sizeEnd;

	poolIndex = --poolIndex % particlePool.size();
}