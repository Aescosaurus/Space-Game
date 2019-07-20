#pragma once

#include "Graphics.h"
#include "Vec2.h"
#include "Mouse.h"
#include "Surface.h"

class Spaceship
{
public:
	void Update( const Mouse& mouse,float dt );
	// TODO: For image, draw in between angle and center
	//  and cuz we're moving to the right it'll look good.
	void Draw( Graphics& gfx ) const;
private:
	static constexpr Vei2 size = { 48,48 };
	Vec2 pos = Graphics::GetScreenRect().GetCenter();
	float angle = 0.0f;
	static constexpr float speed = 3.0f;
	static constexpr float maxSpeed = 700.0f;
	static constexpr float rotSpeed = 6.0f;
	const Surface spr = "Images/Spaceship.bmp";
};