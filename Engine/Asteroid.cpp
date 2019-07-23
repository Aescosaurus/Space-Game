#include "Asteroid.h"
#include "Random.h"

Asteroid::Asteroid( const Vec2& pos,float speed )
	:
	pos( Vei2( pos ) ),
	speed( speed ),
	containsFuel( float( Random{ 0.0f,100.0f } ) < fuelChance )
{}

void Asteroid::Update( float dt )
{
	pos.x -= speed * dt;
}

void Asteroid::Draw( Graphics& gfx ) const
{
	gfx.DrawCircle( Vei2( pos ),int( size ),Colors::Red );
}

Vec2& Asteroid::GetPos()
{
	return( pos );
}

bool Asteroid::IsDead() const
{
	return( pos.x < -size );
}

bool Asteroid::HasEnteredScreen() const
{
	return( pos.x < float( Graphics::ScreenWidth ) - size );
}
