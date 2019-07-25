#pragma once

#include "Graphics.h"
#include "Vec2.h"
#include "Mouse.h"
#include "Surface.h"
#include "Collider.h"
#include "Laser.h"
#include "Timer.h"

class Spaceship
{
public:
	Spaceship();

	void Update( const Mouse& mouse,float dt );
	void Draw( Graphics& gfx ) const;

	const Vec2& GetPos() const;
	Collider& GetColl();
	std::vector<Laser>& GetLasers();
private:
	static constexpr float size = 48.0f;
	// Vec2 pos = Graphics::GetScreenRect().GetCenter();
	Collider coll;
	float angle = 0.0f;
	static constexpr float speed = 3.0f;
	static constexpr float maxSpeed = 700.0f;
	static constexpr float rotSpeed = 6.0f;
	const Surface spr = "Images/Spaceship.bmp";
	std::vector<Laser> lasers;
	Timer shotTimer = 1.0f;
};