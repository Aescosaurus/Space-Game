#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include <vector>
#include "Asteroid.h"
#include "Missile.h"

class ObstacleHandler
{
public:
	ObstacleHandler();

	void Update( const Vec2& playerPos,float dt );
	void Draw( Graphics& gfx ) const;
private:
	void LoadChunk();
private:
	static constexpr float asteroidSpawnChance = 2.0f;
	static constexpr float asteroidMoveSpeed = 500.0f;
	static constexpr float missileSpawnChance = 5.0f;
	std::vector<Asteroid> asteroids;
	std::vector<Missile> missiles;
	int nChunks;
};