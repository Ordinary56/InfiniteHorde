#include "core/input/raylibInputSystem.h"
#include <iostream>
#include <raylib.h>

RaylibInputSystem::RaylibInputSystem() {
  for (int i = 0; i < InputAction::ActionCount; i++) {
    // -1 - unmapped key
    m_keyMaps[i] = -1;
    m_currentState[i] = false;
    m_pressedState[i] = false;
  }
}

void RaylibInputSystem::update() {
  for (int i = 0; i < InputAction::ActionCount; i++) {
    int key = m_keyMaps[i];
    m_pressedState[i] = IsKeyPressed(key);
    m_currentState[i] = IsKeyDown(key);
  }
}

void RaylibInputSystem::mapKey(InputAction action, int key) {
  m_keyMaps[static_cast<int>(action)] = key;
}

bool RaylibInputSystem::getKeyPressed(InputAction action) {
  return m_pressedState[static_cast<int>(action)];
}

bool RaylibInputSystem::getKeyDown(InputAction action) {
  return m_currentState[static_cast<int>(action)];
}
