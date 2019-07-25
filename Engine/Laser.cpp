#include "Laser.h"
#include "ChiliUtils.h"

Laser::Laser( const Vec2& pos,float angle )
	:
	coll( pos,size ),
	vel( Vec2::FromAngle( angle ) * speed ),
	angle( angle )
{}

void Laser::Update( float dt )
{
	coll.GetPos() += vel * dt;
}

void Laser::Draw( Graphics& gfx ) const
{
	// coll.Draw( gfx );

	gfx.DrawSprite( Vei2( coll.GetPos() ),*spr,
		angle + chili::pi / 2.0f );
}

Collider& Laser::GetColl()
{
	return( coll );
}
