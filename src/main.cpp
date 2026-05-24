#include "core/game.h"
#include "core/input/raylibInputSystem.h"
#include "core/renderer/raylibRenderer.h"
#include "memtrace/memtrace.h"
#include "platform/raylibPlatform.h"

#ifndef CPORTA
#include <raylib.h>
#endif

int main(void) {
#ifdef CPORTA
  ConsolePlatform platform;
  ConsoleRenderer renderer;
#else
  RaylibPlatform platform;
  RaylibRenderer renderer;
  RaylibInputSystem &raylibInput = RaylibInputSystem::instance();
  raylibInput.mapKey(InputAction::MoveLeft, KEY_A);
  raylibInput.mapKey(InputAction::MoveRight, KEY_D);
  raylibInput.mapKey(InputAction::MoveUp, KEY_W);
  raylibInput.mapKey(InputAction::MoveDown, KEY_S);
  raylibInput.mapKey(InputAction::Shoot, MOUSE_LEFT_BUTTON);
#endif
  Game game(platform, renderer);
  game.run();
  return 0;
}
