//
// Created by paul on 14/08/2021.
//
#include <raylib.h>

#ifndef FOXY_ANIM_H
#define FOXY_ANIM_H

#endif //FOXY_ANIM_H

typedef struct Anim{
    Rectangle frame;
    int maxFrames;
    int currentFrame;
    float time;
    float delay;
    bool direction;
}Anim;

static const float foxyRunDelay = 0.10f;
static const float foxyIdleDelay = 0.25f;

static const Anim foxyBackIdle      = {(Rectangle){0, 37, 21, 25}, 4, 0, 0.0f, foxyIdleDelay, false};
static const Anim foxyBackRun       = {(Rectangle){0, 62, 21, 25}, 4, 0, 0.0f, foxyRunDelay, false};
static const Anim foxyFrontIdle     = {(Rectangle){228, 91, 21, 25}, 4, 0, 0.0f, foxyIdleDelay, false};
static const Anim foxyFrontRun      = {(Rectangle){312, 91, 21, 25}, 4, 0, 0.0f, foxyRunDelay, false};
static const Anim foxySideIdle      = {(Rectangle){0, 116, 20, 25}, 4, 0, 0.0f, foxyIdleDelay, false};
static const Anim foxySideIdleLeft  = {(Rectangle){396, 91, 20, 25}, 4, 0, 0.0f, foxyIdleDelay, false};
static const Anim foxySideRun       = {(Rectangle){160, 116, 20, 25}, 4, 0, 0.0f, foxyRunDelay, false};
static const Anim foxySideRunLeft   = {(Rectangle){80, 116, 20, 25}, 4, 0, 0.0f, foxyRunDelay, false};

static const Anim chickBackIdle     = {(Rectangle){238, 0, 18, 22}, 4, 0, 0.0f, 0.25f, false};
static const Anim chickBackRun      = {(Rectangle){310, 0, 18, 22}, 4, 0, 0.0f, 0.25f, false};
static const Anim chickFrontRun     = {(Rectangle){0, 15, 18, 22}, 4, 0, 0.0f, 0.25f, false};
static const Anim chickFrontIdle    = {(Rectangle){382, 0, 18, 22}, 4, 0, 0.0f, 0.25f, false};
static const Anim chickLayEgg       = {(Rectangle){84, 44, 25, 22}, 15, 0, 0.0f, 0.25f, false};
static const Anim chickSideIdle     = {(Rectangle){72, 15, 21, 22}, 4, 0, 0.0f, 0.25f, false};
static const Anim chickSideIdleLeft = {(Rectangle){232, 22, 21, 22}, 4, 0, 0.0f, 0.25f, false};
static const Anim chickSideRun      = {(Rectangle){316, 22, 21, 22}, 4, 0, 0.0f, 0.25f, false};
static const Anim chickSideRunLeft  = {(Rectangle){400, 22, 21, 22}, 4, 0, 0.0f, 0.25f, false};

static const Anim dogBackIdle      = {(Rectangle){84, 66, 25, 25}, 4, 0, 0.0f, 0.25f, false};
static const Anim dogBackRun       = {(Rectangle){384, 66, 25, 25}, 4, 0, 0.0f, 0.25f, false};
static const Anim dogFrontIdle     = {(Rectangle){184, 66, 25, 25}, 4, 0, 0.0f, 0.25f, false};
static const Anim dogFrontRun      = {(Rectangle){284, 66, 25, 25}, 4, 0, 0.0f, 0.25f, false};
static const Anim dogSideIdle      = {(Rectangle){0, 87, 19, 25}, 4, 0, 0.0f, 0.25f, false};
static const Anim dogSideIdleLeft  = {(Rectangle){156, 17, 19, 25}, 4, 0, 0.0f, 0.25f, false};
static const Anim dogSideRun       = {(Rectangle){152, 91, 19, 25}, 4, 0, 0.0f, 0.25f, false};
static const Anim dogSideRunLeft   = {(Rectangle){76, 91, 19, 25}, 4, 0, 0.0f, 0.25f, false};

static const Anim egg           = {(Rectangle){0, 0, 13, 15}, 3, 0, 0.0f, 0.25f, false};
static const Anim exclamation   = {(Rectangle){188, 0, 9, 17}, 2, 0, 0.0f, 0.25f, false};
static const Anim goldEgg       = {(Rectangle){39, 0, 13, 15}, 5, 0, 0.0f, 0.25f, false};
static const Anim menuButton    = {(Rectangle){240, 116, 47, 26}, 2, 0, 0.0f, 0.25f, false};
static const Anim musicButton   = {(Rectangle){104, 0, 16, 15}, 2, 0, 0.0f, 0.25f, false};
static const Anim playButton    = {(Rectangle){206, 0, 16, 17}, 2, 0, 0.0f, 0.25f, false};
static const Anim restartButton = {(Rectangle){334, 116, 47, 26}, 2, 0, 0.0f, 0.25f, false};
static const Anim scoreButton   = {(Rectangle){136, 0, 18, 15}, 2, 0, 0.0f, 0.25f, false};
static const Anim shadow        = {(Rectangle){172, 0, 16, 16}, 1, 0, 0.0f, 0.25f, false};


void initAnim();
void endAnim();
void drawAnimFrame(Anim *anim, Vector2 position, float deltaTime);


