# Dino-The-Game
Clone of the Chrome Dino game written in C++ using the Raylib graphics library.

The purpose of this project was to practice the fundamentals of game development such as game loops, physics simulation, input handling, and procedural generation of obstacles.

## Features

- Player character represented as a square
- Jump system with gravity physics
- Double jump mechanic
- Randomly generated obstacles
- Obstacles move from right to left
- Frame-independent movement using delta time
- Score system displayed during gameplay
- Start menu before the game begins
- Game over menu showing the final score
- Simple and clean game loop structure

## Technologies

- C++
- Raylib

## How the Game Works

The game runs on a standard game loop:

1. Player input is checked (keyboard)
2. Physics updates are applied (gravity and velocity)
3. Obstacles move toward the player
4. Score increases over time
5. The screen is redrawn every frame

Obstacles spawn randomly at the right side of the screen and move left toward the player. The player must jump to avoid them.

If the player collides with an obstacle, the game ends and a **Game Over screen** appears showing the **final score**.

## Game States

The game contains multiple states:

- **Start Menu** – displayed before the game begins
- **Gameplay** – the main game where the player avoids obstacles
- **Game Over Menu** – shown after losing, displaying the final score

## Controls

SPACE — Jump  
ENTER — Start / Restart game


## Video of gameplay:
https://github.com/user-attachments/assets/fb995967-8d86-4ebb-a897-cdaa6418c2d5
