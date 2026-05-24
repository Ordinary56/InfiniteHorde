#include "ui/builders/uiButtonBuilder.h"

UIButtonBuilder &UIButtonBuilder::text(const std::string &text) {
  m_config.text = text;
  return *this;
}

UIButtonBuilder &UIButtonBuilder::position(Vec2 pos) {
  m_config.pos = pos;
  return *this;
}

UIButtonBuilder &UIButtonBuilder::size(Vec2 size) {
  m_config.size = size;
  return *this;
}
UIButtonBuilder &UIButtonBuilder::color(Color_rgb color) {
  m_config.color = color;
  return *this;
}

UIButton* UIButtonBuilder::build() const {
  return new UIButton(m_config.pos, m_config.size, m_config.color, m_config.text);
}
