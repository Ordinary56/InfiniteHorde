#pragma once
#include "core/camera/cameraController.h"
#include "core/gameWorld.h"
#include "core/renderer/renderer.h"
#include "core/timer/timer.h"
#include "entity/enemyManager.h"
#include "entity/player.h"
#include "entity/projectileManager.h"
#include "scene.h"

class GameplayScene : public IScene {
public:
  GameplayScene();
  ~GameplayScene() = default;
  void update(float dt) override;
  void draw(Renderer &renderer) const override;

private:
  void drawUI(Renderer &renderer) const;
  int m_score = 0;
  Player m_player;
  EnemyManager m_enemyManager;
  CameraController m_cameraController;
  ProjectileManager m_projectileManager;
  GameWorld m_world;
  Timer m_spawnTimer;
};
