/*******************************************************************************************
*
*   raylib game template
*
*   <Game title>
*   <Game description>
*
*   This game has been created using raylib (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2021 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "screens.h"    // NOTE: Declares global (extern) variables and screens functions

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Shared Variables Definition (global)
// NOTE: Those variables are shared between modules through screens.h
//----------------------------------------------------------------------------------
GameScreen currentScreen = 0;
Font font = { 0 };
Music music = { 0 };
Sound fxCoin = { 0 };

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static const int screenWidth = 800;
static const int screenHeight = 450;

// Required variables to manage screen transitions (fade-in, fade-out)
static float transAlpha = 0.0f;
static bool onTransition = false;
static bool transFadeOut = false;
static int transFromScreen = -1;
static int transToScreen = -1;

//----------------------------------------------------------------------------------
// Local Functions Declaration
//----------------------------------------------------------------------------------
static void ChangeToScreen(int screen);     // Change to screen, no transition effect

static void TransitionToScreen(int screen); // Request transition to next screen
static void UpdateTransition(void);         // Update transition effect
static void DrawTransition(void);           // Draw transition effect (full-screen rectangle)

static void UpdateDrawFrame(void);          // Update and draw one frame

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main(void)
{
   InitWindow(500, 500, "WINDOW");
   while(!WindowShouldClose())
   {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawCircle(50, 50, 20, RED);
    DrawCircle(150, 50, 20, YELLOW);
    DrawCircle(250, 50, 20, RED);
    DrawCircle(350, 50, 20, ORANGE);
    DrawCircle(450, 50, 20, RED);
    DrawCircle(50, 450, 20, GREEN);
    DrawCircle(150, 350, 20, RED);
    DrawCircle(250, 250, 20, ORANGE);
    DrawCircle(350, 150, 20, GREEN);
    DrawCircle(450, 50, 20, PURPLE);

    EndDrawing();
   }

    CloseWindow();          // Close window and OpenGL context
    

    return 0;
}
