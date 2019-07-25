#pragma once

#include "Graphics.h"

class FuelBar
{
public:
	void Update( float dt );
	void Draw( Graphics& gfx ) const;

	float& GetFuel();
private:
	static constexpr Vei2 size = { 300,12 };
	static constexpr Vei2 topLeft = { Graphics::ScreenWidth / 2 - size.x / 2,5 };

	static constexpr float maxFuel = 100.0f;
	float curFuel = maxFuel;
	static constexpr float fuelDecayRate = 3.0f;
};