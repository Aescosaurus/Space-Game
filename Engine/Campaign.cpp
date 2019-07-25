#include "Campaign.h"
#include "FrameTimer.h"

Campaign::Campaign( const Keyboard& kbd,const Mouse& mouse,
	Graphics& gfx )
	:
	kbd( kbd ),
	mouse( mouse ),
	gfx( gfx )
{}

void Campaign::Update()
{
	float dt = FrameTimer::Mark();
	if( dt > 1.0f ) dt = 0.0f;

	for( auto* coll : objHand.GetColliders() )
	{
		for( auto& laser : player.GetLasers() )
		{
			if( coll->IsCollidingWith( laser.GetColl() ) )
			{
				coll->IsHit() = true;
				laser.GetColl().IsHit() = true;
				// Spawn particles here.
			}
		}
	}

	player.Update( mouse,dt );
	sf.Update( dt );
	objHand.Update( player.GetPos(),dt );
}

void Campaign::Draw()
{
	sf.Draw( gfx );
	objHand.Draw( gfx );
	player.Draw( gfx );
}
