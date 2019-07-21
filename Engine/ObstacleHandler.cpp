#include "ObstacleHandler.h"
#include "Random.h"
#include "ChiliUtils.h"

void ObstacleHandler::Update( const Vec2& playerPos,float dt )
{
	for( int i = 0; i < int( asteroids.size() ); ++i )
	{
		asteroids[i].Update( dt );

		if( asteroids[i].IsDead() )
		{
			chili::remove_element( asteroids,i );
		}
	}

	if( float( Random{ 0.0f,100.0f } ) < asteroidSpawnChance )
	{
		const float padding = 64.0f;
		const auto randPos = Vec2{ float(
			Graphics::ScreenWidth ) + padding,
			float( Random{ padding,float(
			Graphics::ScreenHeight ) - padding } ) };
		asteroids.emplace_back( Asteroid{ randPos,
			asteroidMoveSpeed } );
	}
}

void ObstacleHandler::Draw( Graphics& gfx ) const
{
	for( const auto& ast : asteroids ) ast.Draw( gfx );
}
