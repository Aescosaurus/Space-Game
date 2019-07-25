#include "Asteroid.h"
#include "Random.h"
#include <cassert>

Asteroid::Asteroid( const Vec2& pos,float speed )
	:
	// pos( Vei2( pos ) ),
	coll( pos,size ),
	speed( speed ),
	containsFuel( float( Random{ 0.0f,100.0f } ) < fuelChance ),
	angleDelta( float( Random{ -rotSpeed,rotSpeed } ) )
{
	const int randX = int( Random{ 0,1 } ) * int( size ) * 2;
	const int randY = int( Random{ 0,1 } ) * int( size ) * 2;
	sprClipArea = RectI{ Vei2{ randX,randY },
		int( size ) * 2,int( size ) * 2 };
}

void Asteroid::Update( float dt )
{
	coll.GetPos().x -= speed * dt;

	angle += angleDelta * dt;
}

void Asteroid::Draw( Graphics& gfx ) const
{
	// gfx.DrawCircle( Vei2( pos ),int( size ),Colors::Red );

	// coll.Draw( gfx );

	gfx.DrawSprite( Vei2( coll.GetPos() ),
		sprClipArea,*sprSheet,angle );
}

Vec2& Asteroid::GetPos()
{
	return( coll.GetPos() );
}

bool Asteroid::IsDead() const
{
	return( coll.GetPos().x < -size );
}

bool Asteroid::HasEnteredScreen() const
{
	return( coll.GetPos().x <
		float( Graphics::ScreenWidth ) - size );
}

Collider& Asteroid::GetColl()
{
	return( coll );
}
