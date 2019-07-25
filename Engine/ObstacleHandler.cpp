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
	// Collision detection.
	for( int i = 0; i < int( colliders.size() ); ++i )
	{
		auto* const coll1 = colliders[i];
		for( int j = 0; j < int( colliders.size() ); ++j )
		{
			auto* const coll2 = colliders[j];
			if( coll1 != coll2 &&
				coll1->IsCollidingWith( *coll2 ) )
			{
				coll1->IsHit() = true;
				coll2->IsHit() = true;
				// Explosion animation here.
			}
		}
	}

	// Remove objects that have collided.
	chili::remove_erase_if( asteroids,[]( Asteroid& ast )
	{
		return( ast.GetColl().IsHit() );
	} );
	chili::remove_erase_if( missiles,[]( Missile& mis )
	{
		return( mis.GetColl().IsHit() );
	} );

	// Asteroids and chunk loading.
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

	// Spawn missiles.
	if( float( Random{ 0.0f,100.0f } ) < missileSpawnChance )
	{
		missiles.emplace_back( Missile{ Vec2{ -64.0f,
			float( Random{ 0.0f,
			float( Graphics::ScreenHeight ) } ) } } );
	}

	// Reload collider references if necessary.
	ReloadCollRefs();
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

void ObstacleHandler::ReloadCollRefs()
{
	colliders.clear();
	colliders.reserve( asteroids.size() + missiles.size() );

	for( auto& ast : asteroids )
	{
		colliders.emplace_back( &ast.GetColl() );
	}

	for( auto& mis : missiles )
	{
		colliders.emplace_back( &mis.GetColl() );
	}
}
