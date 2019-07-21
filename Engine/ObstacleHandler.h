#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include <vector>
#include "Asteroid.h"

class ObstacleHandler
{
public:
	void Update( const Vec2& playerPos,float dt );
	void Draw( Graphics& gfx ) const;
private:
private:
	static constexpr float asteroidSpawnChance = 2.0f;
	static constexpr float asteroidMoveSpeed = 500.0f;
	std::vector<Asteroid> asteroids;
};