#include "core/game.h"
#include "core/input/raylibInputSystem.h"
#include "core/renderer/renderer.h"
#include "core/settings.h"
#include "platform/platform.h"
#include "scene/scene.h"
bool Game::m_shutdownRequested = false;
bool Game::m_sceneChangeRequested = false;
SCENES Game::m_pendingScene;
Game::Game(Platform &platform, Renderer &renderer)
    : m_platform(platform), m_renderer(renderer) {
  Settings &settings = Settings::instance();
  m_platform.initWindow(settings.getWindowWidth(), settings.getWindowHeight(),
                        "GAME");

  m_sceneManager.setScene(SCENES::MAIN_MENU);
}

Game::~Game() {}

void Game::run() {
  while (!m_platform.shouldClose() && !m_shutdownRequested) {
    if (m_sceneChangeRequested) {
      m_renderer.clear(COLOR_BLACK);
      m_sceneManager.setScene(m_pendingScene);
      m_sceneChangeRequested = false;
      continue;
    }
    float dt = m_platform.getDeltaTime();
    // update the current scene
    m_sceneManager.update(dt);
    m_renderer.beginFrame();
    m_renderer.clear(COLOR_WHITE);
    m_sceneManager.draw(m_renderer);
    m_renderer.endFrame();
  }
}

void Game::requestSceneChange(SCENES scene) {
  m_sceneChangeRequested = true;
  m_pendingScene = scene;
}
