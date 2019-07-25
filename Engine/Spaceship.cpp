#include "Spaceship.h"
#include "ChiliUtils.h"

Spaceship::Spaceship()
	:
	coll( Vei2( Graphics::GetScreenRect().GetCenter() ),size )
{}

void Spaceship::Update( const Mouse& mouse,float dt )
{
	auto& pos = coll.GetPos();

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

	chili::remove_erase_if( lasers,[]( Laser& laser )
	{
		return( laser.GetColl().IsHit() );
	} );

	// Shoot lasers.
	shotTimer.Update( dt );
	if( mouse.LeftIsPressed() && shotTimer.IsDone() )
	{
		shotTimer.Reset();
		lasers.emplace_back( Laser{ pos,angle } );
	}

	for( auto& laser : lasers ) laser.Update( dt );
}

void Spaceship::Draw( Graphics& gfx ) const
{
	// const auto drawPos = Vei2( pos ) - size / 2;
	// 
	// gfx.DrawRect( int( pos.x ),int( pos.y ),
	// 	size.x,size.y,Colors::Cyan );

	gfx.DrawSprite( Vei2( coll.GetPos() ),
		spr,angle + chili::pi / 2.0f );

	for( const auto& laser : lasers ) laser.Draw( gfx );
}

const Vec2& Spaceship::GetPos() const
{
	return( coll.GetPos() );
}

Collider& Spaceship::GetColl()
{
	return( coll );
}

std::vector<Laser>& Spaceship::GetLasers()
{
	return( lasers );
}
