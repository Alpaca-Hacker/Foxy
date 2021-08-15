//
// Created by paul on 15/08/2021.
//

#include "../include/game.h"
#include "../include/anim.h"
#include "../include/constants.h"

// *** Local Decs ***
void gameInit();
void gameUpdate();
void gameEnd();
void gameRun();
void gameDraw();

// *** Vars ***
float deltaTime;
enum Direction {Back=0, Right, Down, Left};
enum Action {Idle=0, Run=4};


typedef struct GameObject {
    Vector2 position;
    enum Direction direction;
    enum Action action;
    bool isActive;
    Anim anim[9];
}GameObject;

GameObject foxy = {0};


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

    Anim foxyAnim[] = {foxyBackIdle, foxySideIdle, foxyFrontIdle, foxySideIdleLeft,foxyBackRun, foxySideRun,foxyFrontRun, foxySideRunLeft};

    for (int i = 0; i < 8; ++i) {
        foxy.anim[i] = foxyAnim[i];
    }

//    Anim foxy[] = {foxyBackIdle, foxyBackRun, foxyFrontIdle, foxyFrontRun, foxySideIdle,foxySideRun, foxySideIdleLeft, foxySideRunLeft};
//    Anim doggy[] = {dogBackIdle, dogBackRun, dogFrontIdle, dogFrontRun, dogSideIdle, dogSideRun, dogSideIdleLeft, dogSideRunLeft};
//    Anim chick[] = {chickBackIdle, chickBackRun, chickFrontIdle, chickFrontRun, chickSideIdle, chickSideRun, chickSideIdleLeft, chickSideRunLeft, chickLayEgg};
//    Anim misc[] = {egg, exclamation, goldEgg, menuButton, musicButton, playButton, restartButton, scoreButton, shadow};
}

void gameUpdate() {


    }

void gameDraw() {

    BeginDrawing();

    ClearBackground(RAYWHITE);

    for (int i = 0; i < 8; ++i) {
        drawAnimFrame(&foxy.anim[i], (Vector2){i* 65+65, 100}, deltaTime);
    }

//    for (int i = 0; i < 8; ++i) {
//        drawAnimFrame(&doggy[i], (Vector2){i* 65+65, 300}, deltaTime);
//    }
//    for (int i = 0; i < 9; ++i) {
//        drawAnimFrame(&chick[i], (Vector2){i* 65+ 65, 500}, deltaTime);
//    }
//    for (int i = 0; i < 9; ++i) {
//        drawAnimFrame(&misc[i], (Vector2){ i* 65 +65, 700}, deltaTime);
//    }

    EndDrawing();
}


void gameEnd() {
    endAnim();
    CloseWindow();
}

