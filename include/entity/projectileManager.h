#pragma once

#include <cstddef>
class Projectile;
class Renderer;
class GameWorld;
struct Rect;
class Enemy;

constexpr std::size_t MAX_CAPACITY = 20;

class ProjectileManager {
public:
  ProjectileManager();
  ~ProjectileManager();

  void spawn(const Projectile &proj);

  void update(float dt);
  void draw(Renderer &renderer) const;
  void remove(std::size_t index);

  void checkInBounds(const GameWorld &world);
  bool checkEnemyHit(Enemy &enemy);
#ifdef CPORTA
  std::size_t getProjectileCount() const { return m_count; }
#endif

private:
  std::size_t m_capacity = MAX_CAPACITY;
  Projectile *m_projectiles = nullptr;
  std::size_t m_count = 0;
};
