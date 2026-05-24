#pragma once
#include "core/math/vec2.h"
struct CameraData {
  Vec2 target{};
  Vec2 offset{};
  float rotation{0.0f};
  float zoom{1.0f};
};
