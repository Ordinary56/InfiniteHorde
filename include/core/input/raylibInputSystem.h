#pragma once
#include "core/input/inputSystem.h"
class RaylibInputSystem : public InputSystem {
public:
  static RaylibInputSystem &instance() {
    static RaylibInputSystem _instance;
    return _instance;
  }
  RaylibInputSystem(const RaylibInputSystem &other) = delete;
  RaylibInputSystem(const RaylibInputSystem &&other) = delete;
  RaylibInputSystem &operator=(const RaylibInputSystem &other) = delete;
  void update() override;
  void mapKey(InputAction action, int key) override;
  bool getKeyPressed(InputAction action) override;
  bool getKeyDown(InputAction action) override;

private:
  RaylibInputSystem();
};
