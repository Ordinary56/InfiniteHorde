#include "entity/weapon.h"
#include "core/input/consoleInputSystem.h"
#include "core/input/raylibInputSystem.h"
#include "core/renderer/renderer.h"
#include "entity/projectile.h"
#include "entity/projectileManager.h"
#include "helpers/utils.hpp"
#include "platform/raylibPlatform.h"

Weapon::Weapon() : Entity() { m_hitBox = {0, 0, 15, 15}; }
Weapon::Weapon(float x, float y) : Entity(x, y) {}

void Weapon::update(float dt) {
  (void)dt;
#ifndef CPORTA
  RaylibInputSystem &input = RaylibInputSystem::instance();
#else
  ConsoleInputSystem &input = ConsoleInputSystem::instance();
#endif
  if (input.getKeyDown(InputAction::Shoot)) {
    Projectile proj;
    Vec2 target;
    target.x = m_mouseToWorldPos.x - m_position.x;
    target.y = m_mouseToWorldPos.y - m_position.y;

    proj.setDirection(utils::normalize(target));
    proj.setPos(m_position.x, m_position.y);
    if (m_projectileManager != nullptr) {
      m_projectileManager->spawn(proj);
    }
  }
}

void Weapon::setMousePosition(const Vec2 &position) {
  m_mouseToWorldPos = position;
}

void Weapon::draw(Renderer &renderer) const {

  int x = static_cast<int>(m_position.x);
  int y = static_cast<int>(m_position.y);
  renderer.drawRectangle(x, y, m_hitBox.w, m_hitBox.h, COLOR_BLUE);
}

void Weapon::setProjectileManager(ProjectileManager *manager) {
  m_projectileManager = manager;
}
