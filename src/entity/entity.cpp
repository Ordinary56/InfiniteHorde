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

  m_position.x =
      utils::clamp(m_position.x, worldBounds.x, worldBounds.x + worldBounds.w);
  m_position.y =
      utils::clamp(m_position.y, worldBounds.y, worldBounds.y + worldBounds.h);
}

const Vec2 &Entity::getPos() const { return m_position; }
const Rect &Entity::getHitBox() const { return m_hitBox; }
