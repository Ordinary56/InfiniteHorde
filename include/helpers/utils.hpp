#pragma once

#include "core/math/rect.h"
#include "core/math/vec2.h"
#include <cmath>
#ifndef CPORTA
#include <raylib.h>
#endif
namespace utils {

template <typename T, typename U>
constexpr T lerp(const T &a, const T &b, U t) {
  return (b - a) * t;
}

template <> inline Vec2 lerp(const Vec2 &a, const Vec2 &b, float t) {
  Vec2 res;
  res.x = a.x + (b.x - a.x) * t;
  res.y = a.y + (b.y - a.y) * t;
  return res;
}

template <typename T> constexpr T clamp(T val, T min, T max) {
  return (val) > max ? max : (val) < min ? min : val;
}

inline bool checkAABB(const Rect &r1, const Rect &r2) {
  return !(r1.x + r1.w <= r2.x || r2.x + r2.w <= r1.x || r1.y + r1.h <= r2.y ||
           r2.y + r2.h <= r1.y);
}

inline bool checkMouseInRect(const Vec2 &mousePos, const Rect &rect) {
  return (mousePos.x >= rect.x && mousePos.x <= rect.x + rect.w &&
          mousePos.y >= rect.y && mousePos.y <= rect.y + rect.h);
}

inline float length(const Vec2 &v) { return std::sqrt(v.x * v.x + v.y * v.y); }

inline Vec2 normalize(const Vec2 &v) {
  float len = length(v);
  if (len <= 0.00001f) {
    return Vec2{0.0f, 0.0f};
  }
  return Vec2{v.x / len, v.y / len};
}
} // namespace utils
