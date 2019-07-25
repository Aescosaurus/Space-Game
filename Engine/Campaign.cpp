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
