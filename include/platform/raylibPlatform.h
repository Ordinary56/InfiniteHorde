#pragma once
#include "platform.h"

struct Vec2;
class RaylibPlatform : public Platform {
public:
  void initWindow(int w, int h, const char *title) override;
  bool shouldClose() override;
  float getDeltaTime() override;
  void shutdownWindow() override;
  static Vec2 GetMousePosition();
};
