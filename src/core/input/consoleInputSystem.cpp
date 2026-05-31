#include "core/input/consoleInputSystem.h"

ConsoleInputSystem::ConsoleInputSystem() {
  for (int i = 0; i < InputAction::ActionCount; i++) {
    m_keyMaps[i] = -1;
    m_pressedState[i] = false;
    m_keyDownState[i] = false;
  }
}
void ConsoleInputSystem::mapKey(InputAction action, int key) {
  (void)action;
  (void)key;
  throw std::runtime_error("ConsoleInputSystem does not support mapkey");
}

void ConsoleInputSystem::update() {
  for (int i = 0; i < InputAction::ActionCount; ++i) {
    m_keyDownState[i] = false;
    m_pressedState[i] = false;
  }
  // Read one command line
  std::string line;
  if (m_input == &std::cin) {
    return;
  }
  if (m_input && std::getline(*m_input, line)) {
    processCommand(line);
  }
}
void ConsoleInputSystem::processCommand(const std::string &command) {

  InputAction input;
  for (const char &action : command) {
    switch (action) {
    case 'w':
      input = InputAction::MoveUp;
      break;
    case 'a':
      input = InputAction::MoveLeft;
      break;
    case 's':
      input = InputAction::MoveDown;
      break;
    case 'd':
      input = InputAction::MoveRight;
      break;
    case 'f':
      input = InputAction::Shoot;
      break;
    }
    m_pressedState[static_cast<int>(input)] = true;
    m_keyDownState[static_cast<int>(input)] = true;
  }
}

bool ConsoleInputSystem::getKeyPressed(InputAction action) {
  return m_pressedState[static_cast<int>(action)];
}

bool ConsoleInputSystem::getKeyDown(InputAction action) {
  return m_keyDownState[static_cast<int>(action)];
}
