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
  
private:
  SceneManager m_sceneManager;
  Platform &m_platform;
  Renderer &m_renderer;
  static bool m_shutdownRequested;
  static SCENES m_pendingScene;
  static bool m_sceneChangeRequested;
};
