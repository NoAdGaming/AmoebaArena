/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

#include <cmath>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	gamepad = std::make_unique<DirectX::GamePad>();
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	auto state = gamepad->GetState(0);

	player_x -= state.thumbSticks.leftX * zoom_out_factor;
	player_y += state.thumbSticks.leftY * zoom_out_factor;

	if (state.IsRightTriggerPressed() && player_radius < 500.0f) {
		player_radius *= 1.01;
		zoom_out_factor *= 1.01;
	}

	if (state.IsLeftTriggerPressed() && player_radius > 10.0f) {
		player_radius *= 0.99;
		zoom_out_factor *= 0.99;
	}

}

void Game::DrawGrid()
{
	int grid_scale = int(GRID_SIZE / zoom_out_factor);

	// Draw vertical lines
	for (int x = fmod(player_x, GRID_SIZE) * zoom_out_factor; x < Graphics::ScreenWidth; x += grid_scale) {
		gfx.DrawVLine(x, 0, Graphics::ScreenHeight - 1, GRID_COLOR);
	}

	// Draw horizontal lines
	for (int y = fmod(player_y, GRID_SIZE) * zoom_out_factor; y < Graphics::ScreenHeight; y += grid_scale) {
		gfx.DrawHLine(0, Graphics::ScreenWidth - 1, y, GRID_COLOR);
	}
}

void Game::DrawFood()
{

}

void Game::DrawPlayer()
{
	gfx.DrawCircle(center_x, center_y, int(player_radius / zoom_out_factor), PLAYER_COLOR, true);
}

void Game::ComposeFrame()
{
	DrawGrid();
	DrawFood();
	DrawPlayer();
}
