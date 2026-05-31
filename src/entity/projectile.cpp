#include "entity/projectile.h"
#include "core/renderer/renderer.h"

Projectile::Projectile() : Entity() {}

Projectile::Projectile(float x, float y) : Entity(x, y) {}

void Projectile::update(float dt) {
  m_position.x += (m_direction.x * m_speed * dt);
  m_position.y += (m_direction.y * m_speed * dt);
  m_hitBox.x = m_position.x;
  m_hitBox.y = m_position.y;
}

void Projectile::draw(Renderer &renderer) const {

  renderer.drawCircle(m_position.x, m_position.y, 5, COLOR_GREEN);
}

void Projectile::setSpeed(float value) { m_speed = value; }

void Projectile::setDirection(const Vec2 &angle) {
  m_direction.x = angle.x;
  m_direction.y = angle.y;
}

float Projectile::getDamage() const { return m_damage; }
