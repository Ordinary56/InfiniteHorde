#include "platform/raylibPlatform.h"
#include "core/math/vec2.h"
#include <raylib.h>
void RaylibPlatform::initWindow(int w, int h, const char *title) {
  InitWindow(w, h, title);
  SetTargetFPS(60);
}

bool RaylibPlatform::shouldClose() { return WindowShouldClose(); }

float RaylibPlatform::getDeltaTime() { return GetFrameTime(); }
void RaylibPlatform::shutdownWindow() { CloseWindow(); }

Vec2 RaylibPlatform::GetMousePosition() {
  Vector2 mousePos = ::GetMousePosition();
  return Vec2{mousePos.x, mousePos.y};
}
