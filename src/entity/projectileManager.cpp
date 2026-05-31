#include "entity/projectileManager.h"
#include "core/gameWorld.h"
#include "entity/enemy.h"
#include "entity/projectile.h"
#include "helpers/utils.hpp"
#include <iostream>
#include <utility>
ProjectileManager::ProjectileManager()
    : m_projectiles(new Projectile[m_capacity]) {}

ProjectileManager::~ProjectileManager() { delete[] m_projectiles; }

void ProjectileManager::update(float dt) {
  for (std::size_t i = 0; i < m_count; i++) {
    m_projectiles[i].update(dt);
  }
}

void ProjectileManager::spawn(const Projectile &proj) {
  if (m_count >= m_capacity)
    return;
  m_projectiles[m_count++] = proj;
}
void ProjectileManager::draw(Renderer &renderer) const {
  for (std::size_t i = 0; i < m_count; i++) {
    m_projectiles[i].draw(renderer);
  }
}

bool ProjectileManager::checkEnemyHit(Enemy &enemy) {
  for (std::size_t i = 0; i < m_count; i++) {
    if (enemy.checkPlayerCollision(m_projectiles[i].getHitBox())) {
      enemy.takeDamage(m_projectiles[i].getDamage());
      remove(i);
      return true;
    }
  }
  return false;
}

void ProjectileManager::remove(std::size_t index) {
  m_projectiles[index] = std::move(m_projectiles[m_count - 1]);
  --m_count;
}

void ProjectileManager::checkInBounds(const GameWorld &world) {
  const Rect &boundary = world.getWorldBoundary();
  std::size_t i = 0;
  while (i < m_count) {
    const Vec2 &pos = m_projectiles[i].getPos();
    bool isOutOfBounds = pos.x < boundary.x ||
                         pos.x > boundary.x + boundary.w ||
                         pos.y < boundary.y || pos.y > boundary.y + boundary.h;
    if (isOutOfBounds) {
      remove(i);
    } else {
      i++;
    }
  }
}
