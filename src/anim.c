//
// Created by paul on 14/08/2021.
//

#include "../include/anim.h"

Texture2D spriteAtlas;

void initAnim(){
    spriteAtlas = LoadTexture("assets/SpriteAtlas.png");
}

void endAnim() {
    UnloadTexture(spriteAtlas);
}

void drawAnimFrame(Anim *anim, Vector2 position, float deltaTime){

    Rectangle frame = anim->frame;
    frame.x = frame.x + (frame.width * anim->currentFrame);
    DrawTexturePro(spriteAtlas, frame, (Rectangle){position.x, position.y, anim->frame.width*2, anim->frame.height*2}, (Vector2){0,0}, 0, WHITE);

    anim->time += deltaTime;

    if(anim->time >= anim->delay){
        anim-> direction ? anim ->currentFrame++ : anim->currentFrame --;
        if (anim->currentFrame >= anim->maxFrames){
            anim->currentFrame= 0;
        }
        if (anim->currentFrame < 0){
            anim->currentFrame = anim->maxFrames-1;
        }
        anim->time = 0;
    }
}

