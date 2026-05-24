#pragma once
#include "scene.h"
#include "ui/uiContainer.h"

class MainMenuScene : public IScene {
public:
  MainMenuScene();
  ~MainMenuScene() = default;
  void update(float dt) override;
  void draw(Renderer& renderer) const override;

private:
  void createLayout();
  UIContainer m_container;
};
