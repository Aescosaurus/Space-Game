#include "Asteroid.h"

Asteroid::Asteroid( const Vec2& pos,float speed )
	:
	pos( pos ),
	speed( speed )
{}

void Asteroid::Update( float dt )
{
	pos.x -= speed * dt;
}

void Asteroid::Draw( Graphics& gfx ) const
{
	gfx.DrawCircle( Vei2( pos ),int( size ),Colors::Red );
}

bool Asteroid::IsDead() const
{
	return( pos.x < -size );
}
