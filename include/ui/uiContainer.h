#pragma once
#include "ui/uiElement.h"
#include <cstddef>

enum class LayoutDirection { Horizontal = 0, Vertical };
struct Renderer;

class UIContainer {
public:
  UIContainer();
  UIContainer(const UIContainer &other) = delete;
  UIContainer &operator=(const UIContainer &) = delete;
  ~UIContainer();
  void add(UIElement *child);
  void update(float dt);
  void draw(Renderer &renderer) const;
  void layout();

private:
  LayoutDirection m_layoutDir = LayoutDirection::Horizontal;
  float spacing = 5.0f;
  std::size_t m_size = 0, m_capacity = 5;
  UIElement **m_children = nullptr;
};
