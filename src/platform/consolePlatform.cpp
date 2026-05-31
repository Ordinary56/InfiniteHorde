#include "platform/consolePlatform.h"
#include <iostream>

constexpr float CONSOLE_DELTA_TIME = 0.016f;

bool ConsolePlatform::m_fakeMouseButtonPressed = false;
Vec2 ConsolePlatform::m_fakeMousePos = {0.0f, 0.0f};

ConsolePlatform::ConsolePlatform() {}
ConsolePlatform::~ConsolePlatform() {}
void ConsolePlatform::initWindow(int w, int h, const char *title) {
  std::cout << "INIT_WINDOW :" << h << "x " << w << " TITLE: " << title << "\n";
}

bool ConsolePlatform::shouldClose() { return m_windowShouldClose; }

float ConsolePlatform::getDeltaTime() { return CONSOLE_DELTA_TIME; }

void ConsolePlatform::shutdownWindow() { ; }
