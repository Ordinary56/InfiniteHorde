#include "ui/uiButton.h"
#include "core/math/rect.h"
#include "core/settings.h"
#include "helpers/utils.hpp"
#ifdef CPORTA
#include "platform/consolePlatform.h"
#endif
#include <cmath>

UIButton::UIButton(Vec2 position, Vec2 size, Color_rgb color,
                   const std::string &text)
    : UIElement(position, color), m_text(text), m_size(size) {}

void UIButton::update(float dt) {
  (void)dt;
  Rect rect = {m_position.x, m_position.y, m_size.x, m_size.y};
  Vec2 mouse_pos;
#ifndef CPORTA
  Vector2 temp = GetMousePosition();
  mouse_pos = {temp.x, temp.y};
#else
  mouse_pos = ConsolePlatform::getMousePosition();
#endif
  if (utils::checkMouseInRect(mouse_pos, rect)) {
#ifndef CPORTA
    // set the mouse to pointing
    SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    // check if user clicked left click
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      // TODO: fire an associated event
      TriggerClick();
    }
#else
    if (ConsolePlatform::isMouseButtonPressed()) {
      TriggerClick();
    }
#endif
  }
}

void UIButton::draw(Renderer &renderer) const {
  Settings &settings = Settings::instance();
  // round and truncate the positions
  int x = static_cast<int>(std::ceil(m_position.x));
  int y = static_cast<int>(std::ceil(m_position.y));

  // get the text's width and coordiantes
  int textWidth = renderer.measureText(m_text.c_str(), settings.getFontSize());
  int text_x = x + (m_size.x - textWidth) / 2;
  int text_y = y + (m_size.y - settings.getFontSize()) / 2;

  renderer.drawRectangle(x, y, m_size.x, m_size.y,
                         {m_color.r, m_color.g, m_color.b, m_color.a});
  renderer.drawText(m_text, text_x, text_y, settings.getFontSize(),
                    COLOR_WHITE);
}

void UIButton::TriggerClick() { m_onClickedEvent.Invoke(); }
