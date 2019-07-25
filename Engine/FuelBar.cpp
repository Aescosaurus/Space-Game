#include "FuelBar.h"

void FuelBar::Update( float dt )
{
	curFuel -= fuelDecayRate * dt;
}

void FuelBar::Draw( Graphics& gfx ) const
{
	gfx.DrawRect( topLeft.x,topLeft.y,
		int( ( curFuel / maxFuel ) * float( size.x ) ),
		size.y,
		Colors::White );
}

float& FuelBar::GetFuel()
{
	return( curFuel );
}
