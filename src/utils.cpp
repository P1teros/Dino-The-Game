#include "utils.h"

bool CheckCollisionDinoObstacle(Dino player, Obstacle tri) 
{
    // okreslanei krawędzi Dino (prostokąt)
    float pLeft = player.position.x;
    float pRight = player.position.x + player.size.x;
    float pTop = player.position.y;
    float pBottom = player.position.y + player.size.y;

    // krawędzie przeszkody (traktujemy troijakt jak prostokąt)
    float tLeft = tri.position.x + 10;
    float tRight = tri.position.x + 40; // szerokość trójkąta 
    float tTop = 270;                   // szczyt trójkąta
    float tBottom = 300;                // podstawa trójkąta

    // algorytm aabb Ssrawdzamy czy prostokąty nachodzą na siebie
    if (pRight >= tLeft && pLeft <= tRight && pBottom >= tTop && pTop <= tBottom)
    {
        return true; 
    }

    return false;
}
