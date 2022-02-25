#include"ParticleSystem.h"
#include"Utils.h"

ParticleSystem::ParticleSystem()
{
	particlePool.resize(1000);
}

void ParticleSystem::OnUpdate() //sdl time
{

}

void ParticleSystem::Emit(const ParticleProps& particleProps)
{
	Particle& particle = particlePool[poolIndex];
	particle.Active = true;
	particle.position = particleProps.position;
	particle.Rotation = utils::Random(2, 0) * 3.14f;

	particle.velocity = particleProps.velocity;
}