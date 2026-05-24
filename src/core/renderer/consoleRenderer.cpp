#include "core/renderer/consoleRenderer.h"
#include <iostream>
static constexpr int CONSOLE_TEXT_WIDTH = 5;
void ConsoleRenderer::beginFrame() { std::cout << "--- FRAME START ---"; }

void ConsoleRenderer::endFrame() { std::cout << "--- FRAME END ---"; }

void ConsoleRenderer::clear(Color_rgb color) { (void)color; }

void ConsoleRenderer::drawText(const std::string &text, int x, int y,
                               int fontSize, Color_rgb color) {

  (void)x;
  (void)y;
  (void)fontSize;
  (void)color;
  std::cout << text;
}

void ConsoleRenderer::drawRectangle(int x, int y, int w, int h,
                                    Color_rgb color) {
  (void)x;
  (void)y;
  (void)w;
  (void)h;
  (void)color;
}

void ConsoleRenderer::drawCircle(int centerX, int centerY, float radius,
                                 Color_rgb color) {
  (void)centerX, (void)centerY, (void)radius, (void)color;
}

int ConsoleRenderer::measureText(const char *text, int fontSize) {
  (void)text;
  (void)fontSize;
  return CONSOLE_TEXT_WIDTH;
}
