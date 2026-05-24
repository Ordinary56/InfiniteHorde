#pragma once
#include "core/math/rect.h"

// Forward declaration
class Renderer;

// Class for defining the world boundaries
class GameWorld {
public:
  GameWorld() = default;

  // Draw the world onto the screen
  // NOTE: this call function should be the first in the order
  // drawing happens on the order of draw calls
  void draw(Renderer &renderer) const;

  const Rect &getWorldBoundary() const;

private:
  Rect m_worldBoundary = {-10, -10, 1000, 1000};
};
