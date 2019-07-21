#include "Starfield.h"
#include "Random.h"
#include "ChiliUtils.h"

Starfield::Starfield()
{
	const float dt = 1.0f / 60.0f;
	for( int i = 0; i < Graphics::ScreenWidth /
		int( Star::moveSpeed * dt ); ++i )
	{
		Update( dt );
	}
}

void Starfield::Update( float dt )
{
	for( int i = 0; i < int( stars.size() ); ++i )
	{
		auto& star = stars[i];
		star.pos.x -= Star::moveSpeed * star.size * dt;

		if( star.pos.x < -star.size )
		{
			chili::remove_element( stars,i );
		}
	}

	if( float( Random{ 0.0f,100.0f } ) < spawnRate )
	{
		const float randSize = float( Random{ 1.0f,
			float( Random{ 2.0f,4.0f } ) } );
		const Vec2 randPos = Vec2{ float( Graphics::ScreenWidth +
			randSize ),float( Random{ 0.0f,
			float( Graphics::ScreenHeight - 1 ) } ) };
		const Color randColor = Colors::MakeRGB(
			int( Random( 170,240 ) ),
			int( Random( 170,240 ) ),
			int( Random( 0,150 ) ) );

		stars.emplace_back( Star{ randPos,randSize,
			randColor } );
	}
}

void Starfield::Draw( Graphics& gfx )
{
	for( const auto& star : stars )
	{
		gfx.DrawCircle( Vei2( star.pos ),int( star.size ),
			star.col );
	}
}
