#pragma once

#include "entity/entity.h"

// Projectile that the weapon shoots upon clicking the left mouse button
//
class Projectile : public Entity {
public:
  // constructors
  Projectile();
  Projectile(float x, float y);

  // base class's functions
  void update(float dt) override;
  void draw(Renderer &renderer) const override;

  // Get the projectile's damage
  // @returns - the projectile's current damage
  // TODO: make an event when it collides with an enemy
  // TIP: use the generic EventManager, and use invoke() to fire it when
  // collision happens
  float getDamage() const;

  // Sets the projectile's speed
  void setSpeed(float value);

  // set's the projectile's angle
  // @param angle - the angle, represented as a vector
  void setDirection(const Vec2 &angle);

private:
  // default speed
  float m_speed = 10.5f;

  // default damage
  float m_damage = 5.f;
  // The normalized direction the projectile takes
  Vec2 m_direction;
};
