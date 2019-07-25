#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include "Codex.h"
#include "ChiliUtils.h"
#include "Collider.h"

class Asteroid
{
public:
	Asteroid( const Vec2& pos,float speed );
	
	void Update( float dt );
	void Draw( Graphics& gfx ) const;

	Vec2& GetPos();

	bool IsDead() const;
	bool HasEnteredScreen() const;
	Collider& GetColl();
private:
	static constexpr float size = 32.0f;
	// Vec2 pos;
	Collider coll;
	float speed;
	static constexpr float fuelChance = 10.0f;
	bool containsFuel;
	CSurfPtr sprSheet = SurfCodex::Fetch( "Images/Asteroids.bmp" );
	RectI sprClipArea;
	float angle = 0.0f;
	static constexpr float rotSpeed = chili::pi * 2.0f;
	float angleDelta;
};