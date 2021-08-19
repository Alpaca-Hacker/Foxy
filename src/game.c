//
// Created by paul on 15/08/2021.
//

#include "../include/game.h"
#include "../include/anim.h"
#include "../include/constants.h"
#include "../include/utility.h"

// *** Local Decs ***
void gameInit();
void gameUpdate();
void gameEnd();
void gameRun();
void gameDraw();

// *** Vars ***
float deltaTime;
enum Direction {Up=0, Right, Down, Left};
enum Action {Idle=0, Run=4};


typedef struct GameObject {
    Vector2 position;
    enum Direction direction;
    enum Action action;
    bool isActive;
    Anim anim[9];
}GameObject;

GameObject foxy = {0};

float foxySpeed = 3;


// ********************

void gameStart(){
    gameInit();
    gameRun();
    gameEnd();
}

void gameRun() {
    while (!WindowShouldClose()){
        deltaTime = GetFrameTime();
        gameUpdate();
        gameDraw();
    }
}

void gameInit() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Foxy");
    initAnim();

    SetTargetFPS(FPS);

    foxy = (GameObject)  {
        (Vector2) { 100, 100},
        Right,
        Idle,
        true,
        };

    Anim foxyAnim[] = {foxyBackIdle, foxySideIdle, foxyFrontIdle, foxySideIdleLeft, foxyBackRun, foxySideRun,foxyFrontRun, foxySideRunLeft};

    for (int i = 0; i < 8; ++i) {
        foxy.anim[i] = foxyAnim[i];
    }

//    Anim foxy[] = {foxyBackIdle, foxyBackRun, foxyFrontIdle, foxyFrontRun, foxySideIdle,foxySideRun, foxySideIdleLeft, foxySideRunLeft};
//    Anim doggy[] = {dogBackIdle, dogBackRun, dogFrontIdle, dogFrontRun, dogSideIdle, dogSideRun, dogSideIdleLeft, dogSideRunLeft};
//    Anim chick[] = {chickBackIdle, chickBackRun, chickFrontIdle, chickFrontRun, chickSideIdle, chickSideRun, chickSideIdleLeft, chickSideRunLeft, chickLayEgg};
//    Anim misc[] = {egg, exclamation, goldEgg, menuButton, musicButton, playButton, restartButton, scoreButton, shadow};
}

void gameUpdate() {
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)){
        foxy.direction = Up;
        foxy.action = Run;
        foxy.position.y -= foxySpeed * (deltaTime * 60);
    } else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)){
        foxy.direction = Down;
        foxy.action = Run;
        foxy.position.y += foxySpeed * (deltaTime * 60);
    } else if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)){
        foxy.direction = Left;
        foxy.action = Run;
        foxy.position.x -= foxySpeed * (deltaTime * 60);
    } else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)){
        foxy.direction = Right;
        foxy.action = Run;
        foxy.position.x += foxySpeed * (deltaTime * 60);
    } else {
        foxy.action = Idle;
    }
    foxy.position = Vector2Clamp(foxy.position, 0, SCREEN_WIDTH - 60, 0, SCREEN_HEIGHT-60);

}

void gameDraw() {

    BeginDrawing();

    ClearBackground(RAYWHITE);

    drawAnimFrame(&foxy.anim[foxy.direction+ foxy.action], foxy.position, deltaTime);
    EndDrawing();
}


void gameEnd() {
    endAnim();
    CloseWindow();
}

