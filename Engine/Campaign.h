#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Spaceship.h"
#include "Starfield.h"
#include "ObstacleHandler.h"

class Campaign
{
public:
	Campaign( const Keyboard& kbd,const Mouse& mouse,
		Graphics& gfx );

	void Update();
	void Draw();
private:
	const Keyboard& kbd;
	const Mouse& mouse;
	Graphics& gfx;

	Spaceship player;
	Starfield sf;
	ObstacleHandler objHand;
};