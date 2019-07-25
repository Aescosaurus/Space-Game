#include "Missile.h"
#include "ChiliUtils.h"

Missile::Missile( const Vec2& pos )
	:
	// pos( pos )// ,
	coll( pos,size )
	// vel( 1.0f,0.0f )
{}

void Missile::Update( const Vec2& playerPos,float dt )
{
	auto& pos = coll.GetPos();

	const auto desiredAngle = ( playerPos - pos ).GetAngle();

	if( desiredAngle < angle ) angle -= rotSpeed * dt;
	if( desiredAngle > angle ) angle += rotSpeed * dt;

	pos += Vec2::FromAngle( angle ) * flightSpeed * dt;

	// vel = ( vel + diff ).GetNormalized();
	// pos += vel * flightSpeed * dt;
}

void Missile::Draw( Graphics& gfx ) const
{
	// gfx.DrawCircle( Vei2( pos ),int( size ),Colors::Red );

	// coll.Draw( gfx );

	gfx.DrawSprite( Vei2( coll.GetPos() ),
		*spr,angle + chili::pi / 2.0f );
}

Collider& Missile::GetColl()
{
	return( coll );
}
