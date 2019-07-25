#pragma once

#include "Vec2.h"

class Collider
{
public:
	Collider( const Vec2& pos,float size );

	Vec2& GetPos();

	bool IsCollidingWith( const Collider& other );
private:
	Vec2 pos;
	float size;
};