#pragma once
#include "ui/uiButton.h"

struct ButtonConfig {
  Vec2 pos;
  Vec2 size;
  Color_rgb color;
  std::string text;
};

class UIButtonBuilder {
public:
  UIButtonBuilder& text(const std::string &text);
  UIButtonBuilder &position(Vec2 pos);
  UIButtonBuilder &size(Vec2 size);
  UIButtonBuilder &color(Color_rgb color);
  UIButton* build() const;

private:
  ButtonConfig m_config;
};
