#pragma once

#include "Graphics.h"
#include "Colors.h"

namespace SpriteEffect
{
	class Chroma
	{
	public:
		Chroma( Color chroma )
			:
			chroma( chroma )
		{}
		void operator()( int x,int y,Color src,Graphics& gfx )
		{
			if( src != chroma )
			{
				gfx.PutPixel( x,y,src );
			}
		}
	private:
		Color chroma;
	};
	class Substitution
	{
	public:
		Substitution( Color substitution,Color chroma )
			:
			sub( substitution ),
			chroma( chroma )
		{}
		void operator()( int x,int y,Color src,Graphics& gfx )
		{
			if( src != chroma )
			{
				gfx.PutPixel( x,y,sub );
			}
		}
	private:
		Color sub;
		Color chroma;
	};
}