/*******************************************************************************************
*   raylib game template
*   Working on Mac for Adam Heaton with no build errors. Some extraneous files in here, but
*   this setup is the only one I've been able to get to work with Makefile (the only way I can
*   run anything) so please ignore them and only focus on this file, raylib_game.c
*
*   Run using Makefile with the following settings 
*   Configuration: Default
*   Build target: [raylib_game]
*   Launch target [raylib_game]
*
*   Thank you
*
********************************************************************************************/

#include "raylib.h"
#include "screens.h"    // NOTE: Declares global (extern) variables and screens functions

Font font = { 0 };
Music music = { 0 };
Sound fxCoin = { 0 };


//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main(void)
{
   InitWindow(500, 500, "WINDOW");
   while(!WindowShouldClose())
   {
    BeginDrawing();
    ClearBackground(ORANGE);
    DrawCircle(50, 50, 20, RED);
    DrawCircle(150, 50, 20, YELLOW);
    DrawCircle(250, 50, 20, RED);
    DrawCircle(350, 50, 20, GREEN);
    DrawCircle(450, 50, 20, RED);
    DrawCircle(50, 450, 20, GREEN);
    DrawCircle(150, 350, 20, RED);
    DrawCircle(250, 250, 20, BLUE);
    DrawCircle(350, 150, 20, GREEN);
    DrawCircle(450, 50, 20, PURPLE);

    EndDrawing();
   }

    CloseWindow();          // Close window and OpenGL context
    

    return 0;
}
