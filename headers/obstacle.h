#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"

struct Obstacle 
{
    Vector2 position;
    float speed;

    void Init();
    void Update(float dt);
    void Draw();
};

#endif
