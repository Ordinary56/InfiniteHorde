#pragma once
enum InputAction {
  MoveLeft = 0,
  MoveRight,
  MoveUp,
  MoveDown,
  Shoot,
  ActionCount
};
class InputSystem {
public:
  virtual ~InputSystem() = default;
  virtual void update() = 0;
  virtual void mapKey(InputAction action, int key) = 0;
  virtual bool getKeyPressed(InputAction action) = 0;
  virtual bool getKeyDown(InputAction action) = 0;

protected:
  int m_keyMaps[InputAction::ActionCount];
  bool m_currentState[InputAction::ActionCount];
  bool m_pressedState[InputAction::ActionCount];
};
