#include "core/renderer/raylibRenderer.h"
#include "core/camera/cameraData.h"
#include <raylib.h>

Camera2D RaylibRenderer::toRaylibCamera(const CameraData &camera) {
  Camera2D cam{};
  cam.offset = {camera.offset.x, camera.offset.y};
  cam.target = {camera.target.x, camera.target.y};
  cam.rotation = camera.rotation;
  cam.zoom = camera.zoom;
  return cam;
}

void RaylibRenderer::beginFrame() { BeginDrawing(); }

void RaylibRenderer::endFrame() { EndDrawing(); }

void RaylibRenderer::beginCamera(const CameraData &camera) {
  Camera2D cam = toRaylibCamera(camera);
  BeginMode2D(cam);
}
void RaylibRenderer::endCamera() { EndMode2D(); }

void RaylibRenderer::drawRectangle(int x, int y, int width, int height,
                                   Color_rgb color) {
  DrawRectangle(x, y, width, height, {color.r, color.g, color.b, color.a});
}

void RaylibRenderer::clear(Color_rgb color) {
  ClearBackground({color.r, color.g, color.b, color.a});
}

void RaylibRenderer::drawText(const std::string &text, int x, int y,
                              int fontSize, Color_rgb color) {
  DrawText(text.c_str(), x, y, fontSize,
           Color{color.r, color.g, color.b, color.a});
}

void RaylibRenderer::drawCircle(int centerX, int centerY, float radius,
                                Color_rgb color) {
  DrawCircle(centerX, centerY, radius, {color.r, color.g, color.b, color.a});
}

int RaylibRenderer::measureText(const char *text, int fontSize) {
  return MeasureText(text, fontSize);
}
