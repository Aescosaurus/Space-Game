#pragma once

#include "Vec2.h"
#include "Graphics.h"

class Missile
{
public:
	Missile( const Vec2& pos );

	void Update( const Vec2& playerPos,float dt );
	void Draw( Graphics& gfx ) const;
private:
	Vec2 pos;
	// Vec2 vel;
	float angle = 0.0f;
	static constexpr float flightSpeed = 100.0f;
	static constexpr float rotSpeed = 1.0f;
};