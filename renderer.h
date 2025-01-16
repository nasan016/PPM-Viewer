#ifndef RENDERER_H
#define RENDERER_H

#include <raylib.h>
#include "PPM.h"

using RGBVal = unsigned char;

void initScreen(const PPM& ppm);

#endif
