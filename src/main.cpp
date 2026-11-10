#include "raylib.h"
#include <iostream>

#pragma region imgui
#include "imgui.h"
#include "rlImGui.h"
#include "imguiThemes.h"
#pragma endregion

#include "World/WorldConfig.h"
#include "Building/CastleConfig.h"

Camera2D StaticCamera() {
	Camera2D camera = {};

	// The point in the world that the camera looks at
	camera.target = {
		WORLD_WIDTH / 2.0f,
		WORLD_HEIGHT / 2.0f
	};

	// The center position of the screen
	camera.offset = {
		GetScreenWidth() / 2.0f,
		GetScreenHeight() / 2.0f
	};

	camera.rotation = 0.0f;

	// Fit the entire world into the screen
	float zoomX = (float)GetScreenWidth() / WORLD_WIDTH;
	float zoomY = (float)GetScreenHeight() / WORLD_HEIGHT;

	camera.zoom = fminf(zoomX, zoomY);

	return camera;
}



// Update: A function that updates the game state based on the elapsed time since the last frame.
void Update(float dt) {
	// Update your game logic here
    // Player main castle
    Castle playerCastle(
        { 100, 100, 200, 150 },
        Faction::Player,
        1000.0f,
        true
    );

    // Enemy main castle
    Castle enemyCastle(
        { 980, 100, 200, 150 },
        Faction::Enemy,
        1000.0f,
        true
    );

    // Neutral secondary castle
    Castle neutralCastle(
        { 500, 450, 150, 120 },
        Faction::Neutral,
        500.0f,
        false
    );

}

// Draw: A function that handles the rendering of game objects and UI elements.
void Draw(const Camera2D& camera)
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    // Everything inside this block uses world coordinates
    BeginMode2D(camera);

    // Draw world background
    DrawRectangle(
        0, 0,
        WORLD_WIDTH, WORLD_HEIGHT,
        DARKBLUE
    );

    // Draw world boundaries
    DrawRectangleLines(
        0, 0,
        WORLD_WIDTH, WORLD_HEIGHT,
        BLACK
    );

	// Vertical center line
    DrawLine(
        WORLD_WIDTH / 2, 0,
        WORLD_WIDTH / 2, WORLD_HEIGHT,
        WHITE
    );

	// Horizontal center line
    DrawLine(
        0, WORLD_HEIGHT / 2,
        WORLD_WIDTH, WORLD_HEIGHT / 2,
        WHITE
    );

    EndMode2D();

    // UI should be drawn outside BeginMode2D()
    DrawFPS(10, 10);

    EndDrawing();
}

int main()
{
    InitWindow(800, 600, "Aggression Game");

    SetWindowState(FLAG_WINDOW_RESIZABLE);

    int screenWidth = GetMonitorWidth(0);
    int screenHeight = GetMonitorHeight(0);

    SetWindowSize(screenWidth, screenHeight);
    MaximizeWindow();

    SetTargetFPS(60);

    // Create camera after setting the window size
    Camera2D camera = StaticCamera();

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        Update(dt);

        Draw(camera);
    }

    CloseWindow();

    return 0;
}
