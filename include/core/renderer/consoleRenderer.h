#pragma once
#include "renderer.h"

class ConsoleRenderer : public Renderer {
  void beginFrame() override;
  void endFrame() override;
  void clear(Color_rgb color) override;
  void drawText(const std::string &text, int x, int y, int fontSize,
                Color_rgb color) override;
  void drawRectangle(int x, int y, int width, int height,
                     Color_rgb color) override;

  void drawCircle(int centerX, int centerY, float radius,
                  Color_rgb color) override;
  int measureText(const char *text, int fontSize) override;
};
