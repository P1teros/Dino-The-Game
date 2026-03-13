#include "raylib.h"
#include "dino.h"
#include "obstacle.h"
#include "utils.h"
#include "vector"
using namespace std;


int main(void) 
{
    const int screenWidth = 800;
    const int screenHeight = 450;


    InitWindow(screenWidth, screenHeight, "Dino Raylib - Modular");
    SetTargetFPS(60);

    Dino player;
    player.Init();

    vector<Obstacle> obstacles;

    for (int i = 0; i < 3; i++) 
    {
        Obstacle o;
        o.Init();
        o.position.x = 800 + (i * 400); // ustawia je( przeszkody) w rzedzie co 400 pikseli
        obstacles.push_back(o);
    }
    
    int score = 0;
    float actualScore = 0.0f;
    int finalScore = 0;
    
    int gameState = 0;
    
    while (!WindowShouldClose()) 
    {
        float dt = GetFrameTime();

        if(gameState == 0)
        {
            if(IsKeyPressed(KEY_ENTER))
                gameState = 1; 
        }
        
         
        else if(gameState == 1) // zaczyna sie gra
            {
                actualScore += dt * 10;
                score = (int)actualScore;
                
                //speed 
                float currentSpeed = 200.0f + (actualScore * 0.5f);
                
                if(currentSpeed >  600.0f)
                {
                    currentSpeed = 600.0f;
                }        
                for (int i = 0; i < obstacles.size(); i++) 
                {
                    obstacles[i].speed = currentSpeed;
                }
                
                //ruch
                player.Update(dt);
                for (int i = 0; i < obstacles.size(); i++) 
                {
                    obstacles[i].Update(dt);
                    
                    if (obstacles[i].position.x < -50) 
                    {   
                        float maxRightX = 200.0f;
                        
                        for(int j = 0; j < obstacles.size(); j++)
                        {
                            if (obstacles[j].position.x > maxRightX)
                            {
                                maxRightX = obstacles[j].position.x;
                            }
                        }
                        obstacles[i].position.x = maxRightX + 200 + GetRandomValue(0, 600);
                    }
                }
                    
                // checking collision
                for(int i = 0; i < obstacles.size(); i++)
                {
                    if(CheckCollisionDinoObstacle(player,obstacles[i]) == true)
                    {
                        gameState = 2;
                        player.Init(); // restart dinusia
                        
                        finalScore = score; // Zapamiętujemy wynik przed resetem
                        actualScore = 0;
                        score = 0;
                        // restart przezkod
                        for (int j = 0; j < obstacles.size(); j++) 
                        {
                            obstacles[j].Init();
                            obstacles[j].position.x = 800 + (j * 400);
                        }
                        break; //przerwajnie sprawdzania innych kolizji w tej klatce
                    }
                }
            }
            else if(gameState == 2)
            {
                if(IsKeyPressed(KEY_ENTER))
                    gameState = 1; 
            }

        //rysowanie
        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            if(gameState == 0)
            {
                // Rysuj TYLKO napisy menu
                DrawText("Dino The Game", 200, 100, 60, BLUE);
                DrawText("Press ENTER to start", 220, 200, 30, GRAY);
            }
            
            else if(gameState == 1)
            {
                DrawText(TextFormat("FPS: %i", GetFPS()), 10, 10, 20, BLACK);
                DrawLine(0, 300, 800, 300, BLACK); // ziemia
                DrawText(TextFormat("SCORE: %i", score), 650, 20, 20, DARKGRAY);

                player.Draw();
                for (int i = 0; i < obstacles.size(); i++) 
                {
                    obstacles[i].Draw();
                }
            }
            
            else if(gameState == 2)
            {
                DrawText("GAME OVER", 200, 100, 60, RED);
                // Używamy zapamiętanego finalScore:
                DrawText(TextFormat("FINAL SCORE: %i", finalScore), 250, 170, 30, DARKGRAY);
                DrawText("Press ENTER to restart", 265, 210, 19, GRAY);
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
