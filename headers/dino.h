#ifndef DINO_H
#define DINO_H

#include "raylib.h"

struct Dino 
{
    Vector2 position;
    Vector2 size;
    float velocityY;
    int jumpCount;
    bool isGrounded;

    void Init();
    void Update(float dt);
    void Draw();
};

#endif
