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

//The following lines of code are extraneous but necessary to run using Makefile. Please ignore.
Font font = { 0 };
Music music = { 0 };
Sound fxCoin = { 0 };
//Texture2D scarfy = LoadTexture("/Users/adzo/Documents/DKIT /1. Software Engineering/Lecture 5/BLANK TEMPLATE/src/resources/scarfy.png");
int windowWidth = 500;
int windowHeight = 500;

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main(void)
{
   InitWindow(500, 500, "WINDOW");
    Texture2D scarfy = LoadTexture("resources/scarfy.png");

    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0; 
    Vector2 scarfyPos;
    scarfyPos.x = windowWidth/2 - scarfyRec.width/2;
    scarfyPos.y = windowHeight - scarfyRec.height*3;

   while(!WindowShouldClose())
   {
    BeginDrawing();
    DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);
    ClearBackground(RED);

    EndDrawing();
   }

    CloseWindow();          // Close window and OpenGL context
    return 0;
}
