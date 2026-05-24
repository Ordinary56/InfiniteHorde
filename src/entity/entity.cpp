#include "entity/entity.h"
#include "helpers/utils.hpp"

Entity::Entity(float x, float y) {
  m_position.x = x;
  m_position.y = y;
}

void Entity::setPos(float x = 0, float y = 0) {
  m_position.x = x;
  m_position.y = y;
}

void Entity::clampToWorld(const Rect &worldBounds) {
  float halfW = m_hitBox.w * 0.5f;
  float halfH = m_hitBox.h * 0.5f;

  m_position.x = utils::clamp(m_position.x, worldBounds.x + halfW,
                              worldBounds.x + worldBounds.w - halfW);
  m_position.y = utils::clamp(m_position.y, worldBounds.y + halfH,
                              worldBounds.y + worldBounds.h - halfH);
}

const Vec2 &Entity::getPos() const { return m_position; }
const Rect &Entity::getHitBox() const { return m_hitBox; }
