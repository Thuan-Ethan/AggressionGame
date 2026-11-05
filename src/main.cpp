#include "raylib.h"
#include <iostream>

#pragma region imgui
#include "imgui.h"
#include "rlImGui.h"
#include "imguiThemes.h"
#pragma endregion

#include "World/worldConfig.h"

// Update: A function that updates the game state based on the elapsed time since the last frame.
void Update(float dt) {
	// Update your game logic here
}

// Draw: A function that handles the rendering of game objects and UI elements.
void Draw() {
	BeginDrawing();
	ClearBackground(RAYWHITE);
	// Draw your game objects here
	EndDrawing();
}

int main() {
	InitWindow(800, 600, "basic window");

	// Use GetMonitorWidth and GetMonitorHeight to get the current monitor's width and height
	int screenWidth = GetMonitorWidth(0);
	int screenHeight = GetMonitorHeight(0);

	SetWindowSize(screenWidth, screenHeight);
	//SetWindowPosition(0, 0);

	MaximizeWindow();

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		float dt = GetFrameTime();

		Update(dt);

		Draw();
	}
	
	CloseWindow();

	return 0;
}
