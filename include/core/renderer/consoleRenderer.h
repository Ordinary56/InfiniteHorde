#pragma once
#include "core/math/vec2.h"
#include "renderer.h"

class ConsoleRenderer : public Renderer {
public:
  ConsoleRenderer() = default;
  ~ConsoleRenderer() = default;

  void beginFrame() override;
  void endFrame() override;
  void clear(Color_rgb color) override;

  void beginCamera(const CameraData &data) override;
  void endCamera() override;

  void drawText(const std::string &text, int x, int y, int fontSize,
                Color_rgb color) override;
  void drawRectangle(int x, int y, int width, int height,
                     Color_rgb color) override;

  void drawCircle(int centerX, int centerY, float radius,
                  Color_rgb color) override;
  int measureText(const char *text, int fontSize) override;


private:
};
