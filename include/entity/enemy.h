#pragma once
#include "entity.h"

class Enemy : public Entity {
public:
  Enemy();
  Enemy(float x, float y);
  void takeDamage(float value);

  void walkTo(const Vec2 &direction);
  void update(float dt) override;
  void draw(Renderer &renderer) const override;

  bool checkPlayerCollision(const Rect &hitbox);

  bool isDead() const;

private:
  Rect m_hitBox = {0, 0, 50, 50};
  bool m_isDead = false;
  float m_speed = 3.0f;
  Vec2 m_targetPosition;
  float m_health = 50.0f;
};
