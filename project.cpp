#include  "raylib.h"
int main()
{
    // window dimentions
    int width{1200};
    int height{800};
    InitWindow(width, height, "Bugra's Window");

    // circle coordinates
    int circle_x{width / 2};
    int circle_y{height / 2};
    int circle_radius{25};

    // circle edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    //axe coordinates
    int axe_x{400};
    int axe_y{0};
    int axe_length{50};

    //axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    
    int direction{10};

    //collision detection
    bool collision_with_axe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (l_axe_x <= r_circle_x) && 
                        (r_axe_x >= l_circle_x);

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        //game over
        if (collision_with_axe)
        {
            DrawText("Game Over", 400, 200, 20, RED);
            
        }
        else
        {
            // game logic begins

            //update edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            // update collision with axe
            collision_with_axe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (l_axe_x <= r_circle_x) && 
                        (r_axe_x >= l_circle_x);

        DrawCircle(circle_x, circle_y, circle_radius, BLUE);
        DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED); 

        
        // axe movement
        axe_y += direction;
        if (axe_y > height || axe_y < 0)
        {
            direction = -direction;
        }
        

        if (IsKeyDown(KEY_D) && circle_x < width)
        {
            circle_x += 10;
        }
        if (IsKeyDown(KEY_A) && circle_x > 0)
        {
            circle_x -= 10;
        }
        if (IsKeyDown(KEY_W) && circle_y > 0)
        {
            circle_y -= 10;
        }
        if (IsKeyDown(KEY_S) && circle_y < height)
        {
            circle_y += 10;
        }

        //game logic ends   
        }
        
        EndDrawing();
    }
}
