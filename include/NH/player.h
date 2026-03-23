#pragma once
#include "entity.h"
class Player : public Entity {
public:
  Player() = default;
  Player(float x, float y);
  ~Player() = default;
  Player(const Player &other) = delete;
  Player(Player &&other) = default;
  Player &operator=(const Player &other) = delete;
  void draw() const override;
  void loop(float dt) override;

private:
  float m_speed = 10.0f;
};
