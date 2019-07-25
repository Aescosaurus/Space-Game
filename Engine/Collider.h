#pragma once

#include "Vec2.h"
#include "Graphics.h"

class Collider
{
public:
	Collider( const Vec2& pos,float radius )
		:
		pos( pos ),
		radius( radius ),
		radiusSq( radius * radius )
	{}

	void Draw( Graphics& gfx ) const
	{
		gfx.DrawCircle( Vei2( pos ),int( radius ),Colors::Red );
	}

	Vec2& GetPos()
	{
		return( pos );
	}
	bool& IsHit()
	{
		return( hit );
	}

	bool IsCollidingWith( const Collider& other )
	{
		const auto diff = pos - other.pos;
		return( diff.GetLengthSq() < radiusSq );
	}
	const Vec2& GetPos() const
	{
		return( pos );
	}
	bool IsHit() const
	{
		return( hit );
	}
private:
	Vec2 pos;
	float radius;
	float radiusSq;
	bool hit = false;
};