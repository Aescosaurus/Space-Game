#include "ObstacleHandler.h"
#include "Random.h"
#include "ChiliUtils.h"
#include <string>
#include <fstream>
#include <cassert>

ObstacleHandler::ObstacleHandler()
{
	for( int i = 0; i < 99; ++i )
	{
		std::ifstream test{ "Chunks/Chunk" +
			std::to_string( i ) + ".chu" };

		if( !test.good() )
		{
			nChunks = i;
			break;
		}
	}
	LoadChunk();
}

void ObstacleHandler::Update( const Vec2& playerPos,float dt )
{
	bool loadNextChunk = true;
	for( int i = 0; i < int( asteroids.size() ); ++i )
	{
		asteroids[i].Update( dt );
		
		if( !asteroids[i].HasEnteredScreen() )
		{
			loadNextChunk = false;
		}
		else if( asteroids[i].IsDead() )
		{
			chili::remove_element( asteroids,i );
			--i;
		}
	}

	if( loadNextChunk )
	{
		LoadChunk();
	}

	for( auto& missile : missiles )
	{
		missile.Update( playerPos,dt );
	}

	// if( float( Random{ 0.0f,100.0f } ) < asteroidSpawnChance )
	// {
	// 	const float padding = 64.0f;
	// 	const auto randPos = Vec2{ float(
	// 		Graphics::ScreenWidth ) + padding,
	// 		float( Random{ padding,float(
	// 		Graphics::ScreenHeight ) - padding } ) };
	// 	asteroids.emplace_back( Asteroid{ randPos,
	// 		asteroidMoveSpeed } );
	// }

	if( float( Random{ 0.0f,100.0f } ) < missileSpawnChance )
	{
		missiles.emplace_back( Missile{ Vec2{ 50.0f,50.0f } } );
	}
}

void ObstacleHandler::Draw( Graphics& gfx ) const
{
	for( const auto& ast : asteroids ) ast.Draw( gfx );
	for( const auto& msl : missiles ) msl.Draw( gfx );
}

void ObstacleHandler::LoadChunk()
{
	const std::string fileName = "Chunks/Chunk" +
		std::to_string( int( Random{ 0,nChunks - 1 } ) ) +
		".chu";

	std::ifstream in{ fileName };
	assert( in.good() );

	const int nPrevAsteroids = int( asteroids.size() );

	int x = 0;
	int y = 0;
	int maxX = -1;
	for( char c = in.get(); in.good(); c = in.get() )
	{
		++x;
		if( c == 'a' )
		{
			asteroids.emplace_back( Asteroid{ Vec2{
				float( x ),float( y ) },
				asteroidMoveSpeed } );
		}
		else if( c == '\n' )
		{
			if( x > maxX ) maxX = x;
			x = 0;
			++y;
		}
	}
	const float scale = float( Graphics::ScreenHeight ) /
		float( y );

	for( int i = nPrevAsteroids;
		i < int( asteroids.size() ); ++i )
	{
		auto& pos = asteroids[i].GetPos();
		// pos *= scale;
		pos = Vei2( Vec2( pos ) * scale );
		pos.x += Graphics::ScreenWidth;
	}
}
