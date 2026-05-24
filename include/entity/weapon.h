#pragma once
#include "entity.h"

class Projectile;
class ProjectileManager;
class Weapon : public Entity {
public:
  Weapon();
  Weapon(float x, float y);
  void update(float dt) override;
  void draw(Renderer &renderer) const override;
  void setProjectileManager(ProjectileManager* manager);

private:
  // NOTE: weapon DOES NOT OWN  this pointer
  ProjectileManager *m_projectileManager;
};
