#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include <vector>

class Starfield
{
private:
	class Star
	{
	public:
		Star( Vec2 pos,float size,Color c )
			:
			pos( pos ),
			size( size ),
			col( c )
		{}
	public:
		static constexpr float moveSpeed = 372.5f;
		Vec2 pos;
		float size;
		Color col;
	};
public:
	Starfield();
	void Update( float dt );
	void Draw( Graphics& gfx );
private:
	static constexpr float spawnRate = 17.0f;
	std::vector<Star> stars;
};