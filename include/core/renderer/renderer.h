#pragma once
#include <string>

// Forward declaration
struct CameraData;

// 24 bit color struct
struct Color_rgb {
  unsigned char r, g, b, a;
};

// Constants
constexpr Color_rgb COLOR_WHITE = Color_rgb{255, 255, 255, 255};
constexpr Color_rgb COLOR_BLACK = Color_rgb{0, 0, 0, 255};
constexpr Color_rgb COLOR_RED = Color_rgb{255, 0, 0, 255};
constexpr Color_rgb COLOR_BLUE = Color_rgb{0, 0, 255, 255};
constexpr Color_rgb COLOR_GREEN = Color_rgb{0, 255, 0, 255};

struct Renderer {
  virtual ~Renderer() = default;
  virtual void beginFrame() = 0;
  virtual void endFrame() = 0;
  virtual void clear(Color_rgb color) = 0;

  virtual void beginCamera(const CameraData &camera) = 0;
  virtual void endCamera() = 0;

  virtual void drawText(const std::string &text, int x, int y, int fontSize,
                        Color_rgb color) = 0;

  virtual void drawRectangle(int x, int y, int width, int height,
                             Color_rgb color) = 0;
  virtual void drawCircle(int centerX, int centerY, float radius,
                          Color_rgb color) = 0;

  virtual int measureText(const char *text, int fontSize) = 0;
};

