#include "entity/enemy.h"
#include "core/renderer/renderer.h"
#include "helpers/utils.hpp"

Enemy::Enemy() : Entity() {}
Enemy::Enemy(float x, float y) : Entity(x, y) {}

void Enemy::walkTo(const Vec2 &direction) {
  m_lastPosition.x = direction.x;
  m_lastPosition.y = direction.y;
}

void Enemy::update(float dt) {
  (void)dt;
  Vec2 target = utils::lerp(m_position, m_lastPosition, 1.0f);
  setPos(target.x, target.y);
}

bool Enemy::checkPlayerCollision(const Rect &hitbox) {
  if (utils::checkAABB(m_hitBox, hitbox)) {
    return true;
  }
  return false;
}

void Enemy::takeDamage(float value) {
  m_health = utils::clamp<float>(m_health - value, 0, m_health);
  if (m_health == 0) {
    m_isDead = true;
  }
}

void Enemy::draw(Renderer &renderer) const {
  renderer.drawRectangle(m_position.x, m_position.y, m_hitBox.w, m_hitBox.h,
                         COLOR_RED);
}

bool Enemy::isDead() const { return m_isDead; }
