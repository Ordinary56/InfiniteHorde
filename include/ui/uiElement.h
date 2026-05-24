#pragma once
#include "core/math/vec2.h"
#include "core/renderer/renderer.h"
class UIElement {
public:
  UIElement(const Vec2 position, Color_rgb color);
  virtual ~UIElement() = default;
  virtual void update(float dt) = 0;
  virtual void draw(Renderer &renderer) const = 0;

  inline bool isVisible() { return m_visible; }
  inline void setVisible(bool value) { m_visible = value; }

protected:
  Vec2 m_position;
  Color_rgb m_color;
  bool m_visible = true;
};
