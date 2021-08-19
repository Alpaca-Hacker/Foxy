//
// Created by paul on 19/08/2021.
//

#include <raymath.h>
#include "../include/utility.h"


Vector2 Vector2Clamp(const Vector2 vec, const float xMin, const float xMax, const float yMin, const float yMax) {
    return (Vector2){Clamp(vec.x, xMin, xMax), Clamp(vec.y, yMin, yMax)};
}
