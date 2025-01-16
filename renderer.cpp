#include <raylib.h>
#include "renderer.h"

Color rgb(RGBVal r, RGBVal g, RGBVal b);
void drawPixelMap(RGBValues pixelMap);

void initScreen(const PPM& ppm) {
  FileName windowName = ppm.getFileName();
  RGBValues pixelMap = ppm.getPixelMap();

  constexpr int screenWidth = 500;
  constexpr int screenHeight = 500;

  InitWindow(screenWidth, screenHeight, windowName.c_str());
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);
    drawPixelMap(pixelMap);
    EndDrawing();
  }

  CloseWindow();
}

Color rgb(RGBVal r, RGBVal g, RGBVal b) {
  return (Color) { r, g, b, 255 };
}

void drawPixelMap(RGBValues pixelMap) {
  int xPos = 0;
  int yPos = 0;
  constexpr int sideLen = 20;

  for (auto vect : pixelMap) {
    for (auto arr : vect) {
      DrawRectangle(xPos * sideLen, yPos * sideLen, 
          sideLen, sideLen,
          rgb(arr[0], arr[1], arr[2]));

      ++xPos;
    }
    xPos = 0;
    ++yPos;
  }

}
