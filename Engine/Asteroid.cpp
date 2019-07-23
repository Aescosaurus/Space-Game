#include "Asteroid.h"
#include "Random.h"
#include <cassert>

Asteroid::Asteroid( const Vec2& pos,float speed )
	:
	pos( Vei2( pos ) ),
	speed( speed ),
	containsFuel( float( Random{ 0.0f,100.0f } ) < fuelChance )
{
	const int randX = int( Random{ 0,1 } ) * int( size ) * 2;
	const int randY = int( Random{ 0,1 } ) * int( size ) * 2;
	sprClipArea = RectI{ Vei2{ randX,randY },
		int( size ) * 2,int( size ) * 2 };
}

void Asteroid::Update( float dt )
{
	pos.x -= speed * dt;

	angle += dt * 3.0f;
}

void Asteroid::Draw( Graphics& gfx ) const
{
	// gfx.DrawCircle( Vei2( pos ),int( size ),Colors::Red );

	gfx.DrawSprite( Vei2( pos ),sprClipArea,*sprSheet,angle );
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
