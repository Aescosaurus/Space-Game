#pragma once

#include "Vec2.h"
#include "Graphics.h"

class Asteroid
{
public:
	Asteroid( const Vec2& pos,float speed );
	
	void Update( float dt );
	void Draw( Graphics& gfx ) const;

	Vec2& GetPos();

	bool IsDead() const;
	bool HasEnteredScreen() const;
private:
	static constexpr float size = 32.0f;
	Vec2 pos;
	float speed;
	static constexpr float fuelChance = 10.0f;
	bool containsFuel;
};