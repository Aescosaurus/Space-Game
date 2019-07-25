#pragma once

#include "Collider.h"
#include "Graphics.h"
#include "Codex.h"

class Laser
{
public:
	Laser( const Vec2& pos,float angle );

	void Update( float dt );
	void Draw( Graphics& gfx ) const;

	Collider& GetColl();
private:
	static constexpr float size = 16.0f;
	static constexpr float speed = 700.0f;
	Collider coll;
	Vec2 vel;
	float angle;
	CSurfPtr spr = SurfCodex::Fetch( "Images/Laser.bmp" );
};