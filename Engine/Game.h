/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "GamePad.h"

#define PLAYER_STARTING_RADIUS 50.0
#define FOOD_STARTING_RADIUS 10.0
#define MAXIMUM_RADIUS 500.0
#define GRID_SIZE 100.0

#define PLAYER_COLOR Colors::Green
#define GRID_COLOR Colors::Gray

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
	void DrawGrid();
	void DrawFood();
	void DrawPlayer();
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/

	// The controller variables
	std::unique_ptr<DirectX::GamePad> gamepad;

	// Screen coordinates for center of window
	const int center_x = Graphics::ScreenWidth / 2;
	const int center_y = Graphics::ScreenHeight / 2;

	// Game coordinates for player
	double player_x = 0.0;
	double player_y = 0.0;

	// Player variables
	double player_radius = PLAYER_STARTING_RADIUS;

	// How far out the camera should draw (1.0 = regular scale, 2.0 = half scale, etc)
	double zoom_out_factor = 1.0;

};