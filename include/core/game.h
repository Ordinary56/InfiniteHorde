#pragma once
#include "scene/sceneManager.h"

// Forward declarations
class Platform;
class InputSystem;
class Game {
public:
  Game(Platform &platform, Renderer &renderer);
  Game(const Game &other) = delete;
  Game(Game &&other) = delete;
  Game &operator=(const Game &other) = delete;
  ~Game();

  void run();
  static void requestQuit() { m_shutdownRequested = true; }
  static void requestSceneChange(SCENES scene);

#ifdef CPORTA
  inline SceneManager &getSceneManager() { return m_sceneManager; }
  // Used for testing.
  // similiar to run, but it only ticks once, letting other functions for testing
  void run_once();
#endif

private:
  SceneManager m_sceneManager;
  Platform &m_platform;
  Renderer &m_renderer;
  static bool m_shutdownRequested;
  static SCENES m_pendingScene;
  static bool m_sceneChangeRequested;
};
