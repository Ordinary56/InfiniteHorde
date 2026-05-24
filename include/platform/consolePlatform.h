#pragma once
#include "platform.h"
class ConsolePlatform : public Platform {
public:
  void initWindow(int w, int h, const char *title) override;
  bool shouldClose() override;
  float getDeltaTime() override;
  void shutdownWindow() override;
private:
  bool m_windowShouldClose = false;
};
