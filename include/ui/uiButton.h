#pragma once
#include "core/events/eventManager.hpp"
#include "ui/uiElement.h"
class UIButton : public UIElement {
public:
  UIButton(Vec2 position, Vec2 size, Color_rgb color, const std::string& text);

  UIButton(const UIButton &other) = default;
  UIButton &operator=(const UIButton &other) = default;

  void update(float dt) override;
  void draw(Renderer& renderer) const override;

  inline void setText(const char *newText) { m_text = newText; }

  inline EventManager<void>& ButtonClicked() { return m_onClickedEvent; }
  void TriggerClick();

private:
  EventManager<void> m_onClickedEvent;
  std::string m_text;
  Vec2 m_size;
};
