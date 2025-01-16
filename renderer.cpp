#include "raylib.h"
#include "raymath.h"
#include "renderer.h"

Color rgb(RGBVal r, RGBVal g, RGBVal b);

void moveCamera(Camera2D& camera);
void cameraZoom(Camera2D& camera);
void drawPixelMap(RGBValues pixelMap);

void initScreen(const PPM& ppm) {
  FileName windowName = ppm.getFileName();
  RGBValues pixelMap = ppm.getPixelMap();

  constexpr int screenWidth = 500;
  constexpr int screenHeight = 500;

  Camera2D camera {
      { 0.0f, 0.0f }, 
      { 0.0f, 0.0f },
      0.0f,
      1.0f
  };

  InitWindow(screenWidth, screenHeight, windowName.c_str());
  SetTargetFPS(60);

  while (!WindowShouldClose()) {

    moveCamera(camera);
    cameraZoom(camera);

    BeginDrawing();

    BeginMode2D(camera);
    ClearBackground(RAYWHITE);
    drawPixelMap(pixelMap);

    EndDrawing();
  }

  CloseWindow();
}

Color rgb(RGBVal r, RGBVal g, RGBVal b) {
  return (Color) { r, g, b, 255 };
}

void moveCamera(Camera2D& camera) {
  if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
    Vector2 delta = GetMouseDelta();
    delta = Vector2Scale(delta, -1.0f/camera.zoom);
    camera.target = Vector2Add(camera.target, delta);
  }
}

void cameraZoom(Camera2D& camera) {
  float wheel = GetMouseWheelMove();

  if (wheel != 0) {
    Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);

    camera.offset = GetMousePosition();

    camera.target = mouseWorldPos;

    float scaleFactor = 1.0f + (0.25f*fabsf(wheel));
    if (wheel < 0) scaleFactor = 1.0f/scaleFactor;
    camera.zoom = Clamp(camera.zoom*scaleFactor, 0.125f, 64.0f);
  }
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
