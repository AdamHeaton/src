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
*
********************************************************************************************/

#include "raylib.h"

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------


//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Pong Game");

    Vector2 ballPosition = {screenWidth/2, screenHeight/2};
    Color ballColor = DARKBLUE;
    int paddlePosition = screenHeight/2;
    int paddleWidth = 10;
    int paddleHeight = 50;
    int ballRadius = 10;

    SetTargetFPS(60);                 // Set our game to run at 60 frames-per-second
    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        paddlePosition = GetMouseY();

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, LIGHTGRAY);                
            // Draw a line across the middle of the screen vertically, for testing
            DrawLine(0, screenHeight/2, screenWidth, screenHeight/2, LIGHTGRAY);                
            // Draw a line across the middle of the screen horizontally, for testing

            if ((paddlePosition - paddleHeight/2) <= 0) paddlePosition = paddleHeight/2;    
            /* this if statement checks to see if the paddle goes off the top of the screen 
            (ie has a value LESS than zero when the paddle's height is factored in)
            and then it stays at the height of the paddle divided by two */
            if ((paddlePosition + paddleHeight/2) >= screenHeight) paddlePosition = screenHeight-paddleHeight/2;    
            /* and this does roughly the same in order to check that the paddle doesn't go off the bottom of the screen */
        
            DrawRectangle((screenWidth/100*1)-paddleWidth/2, paddlePosition-paddleHeight/2, paddleWidth, paddleHeight, BLACK);
            /* This line of code draws our left paddle. It factors in the paddle's height and width in order to draw the paddle from 
            the centre instead of the top left.
            */
            DrawRectangle((screenWidth/100*99)-paddleWidth/2, (screenHeight-paddleHeight)-(paddlePosition-paddleHeight/2), paddleWidth, paddleHeight, BLACK);
            /* This line of code draws our right paddle. It factors in the paddle's height and width in order to draw the paddle from 
            the centre instead of the top left. */

            DrawCircle((screenWidth/2), screenHeight/2, ballRadius, RED);





            DrawText(TextFormat("Paddle position Y: %03i", paddlePosition-paddleHeight/2), 10, 40, 20, GRAY);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
