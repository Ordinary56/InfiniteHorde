#pragma once

#include "core/input/inputSystem.h"
#include <iostream>
#include <istream>
// Console based implementation of the InputSystem
// NOTE: it should be better to read and act based on the
// standard input system for better testability and it would make use
// for an engine-agnostic system

class ConsoleInputSystem : public InputSystem {
public:
  static ConsoleInputSystem &instance() {
    static ConsoleInputSystem _instance;
    return _instance;
  }
  void update() override;
  void mapKey(InputAction action, int key) override;
  bool getKeyPressed(InputAction action) override;
  bool getKeyDown(InputAction action) override;

  inline void setInput(std::istream &input) { m_input = &input; }

private:
  ConsoleInputSystem();
  void processCommand(const std::string &command);
  std::istream *m_input = &std::cin;
};
