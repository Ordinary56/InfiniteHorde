#include "platform/consolePlatform.h"

void ConsolePlatform::initWindow(int w, int h, const char *title) {
  (void)w;
  (void)h;
  (void)title;
}

bool ConsolePlatform::shouldClose() { return m_windowShouldClose; }

float ConsolePlatform::getDeltaTime() { return 0.016f; }



void ConsolePlatform::shutdownWindow() { ; }
