#pragma once
#include "core/timer/timer.h"
#include "entity.h"
#include "entity/weapon.h"

class Player : public Entity {
public:
  Player() = default;
  Player(float x, float y);
  ~Player() = default;
  Player(const Player &other) = delete;
  Player(Player &&other) = default;
  Player &operator=(const Player &other) = delete;
  void draw(Renderer &renderer) const override;
  void update(float dt) override;
  Weapon &getWeapon();
  const Rect &getHitBox() const;
  const float &getHealth() const;
  bool isDead() const;
  void takeDamage(float damage);

private:
  Weapon m_weapon;
  float m_speed = 15.0f;
  Rect m_hitBox = {0, 0, 50, 50};
  float m_health = 100.0f;
  bool m_isDead = false;
  Timer m_damageTimer;
};
