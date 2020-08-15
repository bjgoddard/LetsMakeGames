#pragma once
#include "ECS.h"
#include "Components.h"
#include "../Vec2.h"

class ProjectileComponent : public Component
{
public:
	ProjectileComponent(int rng, int sp, Vec2 vel) 
		: range(rng), speed(sp), velocity(vel)
	{}
	~ProjectileComponent()
	{}

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		transform->velocity = velocity;
		std::cout << transform->position << std::endl;
	}

	void update() override
	{
		distance += speed;

		if (distance > range)
		{
			std::cout << "Out of Range" << std::endl;
			entity->destroy();
		}
		else if (transform->position.x > Game::camera.x + Game::camera.w ||
				transform->position.x < Game::camera.x ||
				transform->position.y > Game::camera.y + Game::camera.h ||
				transform->position.y < Game::camera.y)
		{
			std::cout << "Out of Bounds" << std::endl;
			entity->destroy();
		}
	}

private:
	TransformComponent* transform;

	int range = 0;
	int speed = 0;
	int distance = 0;
	Vec2 velocity;
};