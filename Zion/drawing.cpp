#include "Zion.h"
#include "hooks.h"
#include <iostream>

bool ScreenTransform( const Vector &point, Vector &screen, const VMatrix &worldToScreen )
{
	float w;
	//const VMatrix &worldToScreen = Zion::m_pEngine->WorldToScreenMatrix();
	screen.x = worldToScreen[0][0] * point[0] + worldToScreen[0][1] * point[1] + worldToScreen[0][2] * point[2] + worldToScreen[0][3];
	screen.y = worldToScreen[1][0] * point[0] + worldToScreen[1][1] * point[1] + worldToScreen[1][2] * point[2] + worldToScreen[1][3];
	w = worldToScreen[3][0] * point[0] + worldToScreen[3][1] * point[1] + worldToScreen[3][2] * point[2] + worldToScreen[3][3];
	screen.z = 0.0f;

	bool behind = false;

	if( w < 0.001f )
	{
		behind = true;
		screen.x *= 100000;
		screen.y *= 100000;
	}
	else
	{
		behind = false;
		float invw = 1.0f / w;
		screen.x *= invw;
		screen.y *= invw;
	}
	return behind;
}

bool WorldToScreen( const Vector &origin, Vector &screen, const VMatrix &worldToScreen )
{

	if( !ScreenTransform( origin, screen, worldToScreen ) )
	{
		int ScreenWidth, ScreenHeight;
		ScreenWidth = 1280;
		ScreenHeight = 768;
		//std::cout<<"2";
		Zion::m_pEngine->GetScreenSize( ScreenWidth, ScreenHeight );
		//std::cout<<"3";
		float x = ScreenWidth / 2;
		float y = ScreenHeight / 2;
		x += 0.5 * screen.x * ScreenWidth + 0.5;
		y -= 0.5 * screen.y * ScreenHeight + 0.5;
		screen.x = x;
		screen.y = y;
		return true;
	}

	return false;
}