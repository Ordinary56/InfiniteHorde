#include "scene/gameplayScene.h"
#include "core/game.h"
#include "core/input/raylibInputSystem.h"
#include "core/renderer/renderer.h"
#include "core/settings.h"
#include "entity/enemy.h"
#include <algorithm>
#include <random>
#include <sstream>

namespace Random {

std::random_device dev;
std::mt19937 gen(dev());

inline int Range(int min, int max) {
  std::uniform_int_distribution<int> dist(min, max);
  return dist(gen);
}

inline float Range(float min, float max) {
  std::uniform_real_distribution<float> dist(min, max);
  return dist(gen);
}

} // namespace Random

GameplayScene::GameplayScene() : m_player() {
  Settings &settings = Settings::instance();
  float x = settings.getWindowWidth() / 2.f;
  float y = settings.getWindowHeight() / 2.f;
  m_cameraController.setOffset({x, y});
  float random_start = Random::Range(1, 15);
  m_spawnTimer.start(random_start);
  m_enemyManager.onEnemyKilled().Subscribe([this]() { m_score++; });
  m_player.getWeapon().setProjectileManager(&m_projectileManager);
}

void GameplayScene::update(float dt) {
  const Rect &boundary = m_world.getWorldBoundary();
  if (m_player.isDead()) {
    Game::requestSceneChange(SCENES::GAME_OVER);
  }
#ifndef CPORTA
  RaylibInputSystem &input = RaylibInputSystem::instance();
#endif
  input.update();
  m_player.update(dt);
  for (auto enemy : m_enemyManager) {
    enemy.walkTo(m_player.getPos());
    enemy.update(dt);
  }
  bool enemyCollided = std::any_of(
      m_enemyManager.begin(), m_enemyManager.end(), [this](Enemy &enemy) {
        return enemy.checkPlayerCollision(m_player.getHitBox());
      });
  if (enemyCollided) {
    m_player.takeDamage(2.0f);
  }
  m_player.clampToWorld(boundary);
  // Always follow player
  m_cameraController.setTarget(m_player.getPos());
  m_spawnTimer.update(dt);
  if (m_spawnTimer.isFinished()) {
    int randomX = Random::Range(boundary.x, boundary.x + boundary.w);
    int randomY = Random::Range(boundary.y, boundary.y + boundary.h);
    m_enemyManager.addEnemy(new Enemy(randomX, randomY));
    float random_start = Random::Range(2, 10);
    m_spawnTimer.start(random_start);
  }
}
void GameplayScene::draw(Renderer &renderer) const {
  renderer.beginCamera(m_cameraController.getCamera());
  m_world.draw(renderer);
  m_player.draw(renderer);
  for (auto enemy : m_enemyManager) {
    enemy.draw(renderer);
  }
  renderer.endCamera();
  drawUI(renderer);
}

void GameplayScene::drawUI(Renderer &renderer) const {
  Settings &settings = Settings::instance();
  std::stringstream ss;
  ss << "HEALTH: " << m_player.getHealth();

  renderer.drawText(ss.str(), 20, 20, settings.getFontSize(), COLOR_BLACK);
}
