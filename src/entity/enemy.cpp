#include "entity/enemy.h"
#include "core/renderer/renderer.h"
#include "helpers/utils.hpp"

Enemy::Enemy() : Entity() {}
Enemy::Enemy(float x, float y) : Entity(x, y) {}

void Enemy::walkTo(const Vec2 &direction) {
  m_targetPosition.x = direction.x;
  m_targetPosition.y = direction.y;
}

void Enemy::update(float dt) {
  if(m_isDead) {
    return;
  }
  Vec2 target = utils::lerp(m_position, m_targetPosition, dt * 0.2f);
  m_position.x += target.x;
  m_position.y += target.y;
  m_hitBox.x = m_position.x;
  m_hitBox.y = m_position.y;
}

bool Enemy::checkPlayerCollision(const Rect &hitbox) {
  return utils::checkAABB(hitbox, m_hitBox);
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
