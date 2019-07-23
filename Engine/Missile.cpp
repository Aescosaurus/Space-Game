#include "Missile.h"
#include "ChiliUtils.h"

Missile::Missile( const Vec2& pos )
	:
	pos( pos )// ,
	// vel( 1.0f,0.0f )
{}

void Missile::Update( const Vec2& playerPos,float dt )
{
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
	gfx.DrawSprite( Vei2( pos ),*spr,angle + chili::pi / 2.0f );
}
