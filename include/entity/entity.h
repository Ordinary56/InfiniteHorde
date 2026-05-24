#pragma once
#include "core/math/rect.h"

#include "core/math/vec2.h"

// Forward declaration
class Renderer;

// Base abstract class for moving and interacting units in the game
class Entity {
public:
  Entity() = default;
  Entity(float x, float y);
  Entity(const Entity &other) = default;
  Entity(Entity &&other) = default;
  Entity &operator=(const Entity &other) = default;

  void clampToWorld(const Rect& rect);
  virtual ~Entity() = default;
  // Draw the Entity onto the screen
  // @param renderer - The current backend renderer
  virtual void draw(Renderer &renderer) const = 0;

  // once per frame behaviour
  // @param dt - the current backend deltaTime
  virtual void update(float dt) = 0;

  // Getters
  const Vec2 &getPos() const;
  const Rect &getHitBox() const;

  // Setters
  void setPos(float x, float y);

protected:
  Vec2 m_position = {.x = 0.0f, .y = 0.0f};
  Rect m_hitBox;
};
