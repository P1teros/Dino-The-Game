#include "dino.h"

const float GRAVITY = 1100.0f;
const float JUMP_FORCE = -450.0f;
const float GROUND_Y = 260.0f;

void Dino::Init() 
{
    position = { 150, GROUND_Y };
    size = { 40, 40 };
    velocityY = 0;
    jumpCount = 0;
}

void Dino::Update(float dt) 
{
    if (IsKeyPressed(KEY_SPACE) && jumpCount < 2) 
    {
        velocityY = JUMP_FORCE;
        jumpCount++;
    }

    velocityY += GRAVITY * dt;
    position.y += velocityY * dt;

    if (position.y > GROUND_Y) 
    {
        position.y = GROUND_Y;
        velocityY = 0;
        jumpCount = 0;
    }
}

void Dino::Draw() 
{
    DrawRectangleV(position, size, PINK);
}
