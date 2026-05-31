#pragma once
#include "core/math/vec2.h"
#include "platform.h"
class ConsolePlatform : public Platform {
public:
  ConsolePlatform();
  ~ConsolePlatform();
  void initWindow(int w, int h, const char *title) override;
  bool shouldClose() override;
  float getDeltaTime() override;
  void shutdownWindow() override;
  static inline void setMousePosition(float x, float y) {
    m_fakeMousePos.x = x;
    m_fakeMousePos.y = y;
  }

  static inline Vec2 getMousePosition() { return m_fakeMousePos; }
  static bool isMouseButtonPressed() { return m_fakeMouseButtonPressed; }

private:
  bool m_windowShouldClose = false;
  static Vec2 m_fakeMousePos;
  static bool m_fakeMouseButtonPressed;
};
