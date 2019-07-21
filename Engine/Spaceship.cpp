#include "Spaceship.h"
#include "ChiliUtils.h"

void Spaceship::Update( const Mouse& mouse,float dt )
{
	auto delta = Vec2( mouse.GetPos() ) - pos;

	delta = delta * speed;
	if( delta.GetLengthSq() > maxSpeed * maxSpeed )
	{
		delta = delta.GetNormalized() * maxSpeed;
	}

	pos += delta * dt;

	{
		if( delta.GetAngle() < Vec2::Up().GetAngle() )
		{
			delta = Vec2::Up();
		}
		if( delta.GetAngle() > Vec2::Down().GetAngle() )
		{
			delta = Vec2::Down();
		}

		const float desiredAngle = ( delta.GetAngle() +
			Vec2::Right().GetAngle() ) / 2.0f;

		if( angle < desiredAngle ) angle += rotSpeed * dt;
		if( angle > desiredAngle ) angle -= rotSpeed * dt;
	}
}

void Spaceship::Draw( Graphics& gfx ) const
{
	// const auto drawPos = Vei2( pos ) - size / 2;
	// 
	// gfx.DrawRect( int( pos.x ),int( pos.y ),
	// 	size.x,size.y,Colors::Cyan );

	gfx.DrawSprite( Vei2( pos ),spr,angle + chili::pi / 2.0f );
}

const Vec2& Spaceship::GetPos() const
{
	return( pos );
}
