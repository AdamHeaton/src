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
********************************************************************************************/

#include "raylib.h"

int score = 0;
int bounce = 0;

typedef struct Ball
{
    int radius;
    int speedX;
    int speedY;
    int x;
    int y;
};

/*typedef struct Paddle
{
    float x, y;
    float speed;
    float width, height;
    void Draw()
    {

    }
    */

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

    struct Ball ball;
    ball.radius = 10;
    ball.x = screenWidth/2;
    ball.y = screenHeight/2;
    ball.speedX = 3;
    ball.speedY = 5;

    int borderWidth = 25;
    int borderHeight= 25;
    int paddlePosition = screenHeight/2;
    int paddleWidth = 25;
    int paddleHeight = 75;

    
    //struct Paddle leftPaddle;


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
            //BORDER CODE, do I want to implement or not?
            DrawRectangle(0,0, borderWidth, screenHeight, LIGHTGRAY);
            DrawRectangle(0,0, screenWidth, borderHeight, LIGHTGRAY);
            DrawRectangle(0, screenHeight-borderHeight, screenWidth, screenHeight, LIGHTGRAY);
            DrawRectangle(screenWidth-borderWidth, 0, borderWidth, screenHeight, LIGHTGRAY);


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
        
            DrawRectangle(0, paddlePosition-paddleHeight/2, paddleWidth, paddleHeight, BLACK);
            /* This line of code draws our left paddle. It factors in the paddle's height and width in order to draw the paddle from 
            the centre instead of the top left.
            */
            DrawRectangle(screenWidth-paddleWidth, (screenHeight-paddleHeight)-(paddlePosition-paddleHeight/2), paddleWidth, paddleHeight, BLACK);
            /* This line of code draws our right paddle. It factors in the paddle's height and width in order to draw the paddle from 
            the centre instead of the top left. */

            
            //Ball bouncing on right hand side of screen being returned
            if (ball.x >= screenWidth-borderWidth-ball.radius) {
                if ((ball.y < screenHeight-(paddlePosition-paddleHeight/2)) && (ball.y > screenHeight-(paddlePosition+paddleHeight/2))) {
                    DrawRectangle(screenWidth/2-50, screenHeight/2-50, 100, 100, RED);
                    score++;
                }
                ball.speedX = ball.speedX*-1; //return the ball by reversing the ball's X speed
                bounce++;
            }
            
           //Ball bouncing on bottom section of screen being returned
            if (ball.y >= screenHeight-borderHeight-ball.radius) {
                ball.speedY = ball.speedY*-1; //return the ball by reversing the ball's Y speed
                bounce++;
            }

            //ball bouncing on left hand side of screen being returned
            if (ball.x <= ball.radius+borderWidth) {
                if ((ball.y > paddlePosition-paddleHeight/2) && (ball.y < paddlePosition+paddleHeight/2)) {
                    DrawRectangle(screenWidth/2-50, screenHeight/2-50, 100, 100, RED);
                    score++;
                }
                ball.speedX = ball.speedX*-1; //return the ball by reversing the ball's X speed
                bounce++;
            }
            
            //ball bouncing on top section of screen being returned
            if (ball.y <= ball.radius+borderWidth) {
                ball.speedY = ball.speedY*-1; //return the ball by reversing the ball's Y speed
                bounce++;
            }
            
            
            ball.x -= ball.speedX;
            ball.y -= ball.speedY;

            DrawCircle(ball.x, ball.y, ball.radius, RED);

            DrawText(TextFormat("Paddle position Y: %03i", paddlePosition-paddleHeight/2), 10, 40, 20, GRAY);
            DrawText(TextFormat("Ball's X position is: %03i", ball.x), 10, 90, 20, GRAY);
            DrawText(TextFormat("Ball's Y position is: %03i", ball.y), 10, 140, 20, GRAY);
            DrawText(TextFormat("paddlePosition+paddleHeight is: %03i", (paddlePosition+paddleHeight)), 10, 190, 20, GRAY);
            DrawText(TextFormat("SCORE is: %03i", score), screenWidth/2, 80, 30, GRAY);
            DrawText(TextFormat("BOUNCE is: %03i", bounce), screenWidth/2, 120, 30, GRAY);




        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
