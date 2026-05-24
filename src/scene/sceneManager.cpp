#include "scene/sceneManager.h"
#include "scene/gameplayScene.h"
#include "scene/mainMenuScene.h"

SceneManager::~SceneManager() { delete m_currentScene; }


void SceneManager::setScene(SCENES scene) {
  delete m_currentScene;
  m_currentScene = nullptr;
  switch (scene) {
  case SCENES::MAIN_MENU:
    m_currentScene = new MainMenuScene();
    break;
  case SCENES::GAMEPLAY:
    m_currentScene = new GameplayScene();
    break;
  case SCENES::GAME_OVER:
    break;
  default:
    m_currentScene = nullptr;
    break;
  }
}

void SceneManager::update(float dt) {
  if (m_currentScene != nullptr) {
    m_currentScene->update(dt);
  }
}

void SceneManager::draw(Renderer &renderer) const {
  if (m_currentScene != nullptr) {
    m_currentScene->draw(renderer);
  }
}

