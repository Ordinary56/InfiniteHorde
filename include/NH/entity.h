#pragma once
#include <raylib.h>
class Entity {
public:
  Entity() = default;
  Entity(float x, float y);
  Entity(const Entity &other) = default;
  Entity(Entity &&other) = default;
  virtual ~Entity() = default;
  Entity &operator=(const Entity &other) = default;
  virtual void draw() const = 0;
  virtual void loop(float dt) = 0;

  // Getters
  inline Vector2 getPos() const { return m_position; }

  // Setters
  inline void setPos(float x = 0, float y = 0) {
    m_position.x = x;
    m_position.y = y;
  }

protected:
  Vector2 m_position = {.x = 0.0f, .y = 0.0f};
};
