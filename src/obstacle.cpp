#include "obstacle.h"

void Obstacle::Init() 
{
    position = { 800, 260 };
    speed = 200.0f;
}

void Obstacle::Update(float dt) 
{
    position.x -= speed * dt;
}

void Obstacle::Draw() 
{
    Vector2 p1 = { position.x, 300 };
    Vector2 p2 = { position.x + 50, 300 };
    Vector2 p3 = { position.x + 25, 260 };
    DrawTriangle(p1, p2, p3, BLUE);
}
