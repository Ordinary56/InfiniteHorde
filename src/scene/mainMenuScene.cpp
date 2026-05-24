#include "scene/mainMenuScene.h"
#include "core/game.h"
#include "core/settings.h"
#include "ui/builders/uiButtonBuilder.h"
#include "ui/uiButton.h"

MainMenuScene::MainMenuScene() { createLayout(); }

void MainMenuScene::update(float dt) { m_container.update(dt); }

void MainMenuScene::draw(Renderer &renderer) const {
  m_container.draw(renderer);
}

void MainMenuScene::createLayout() {
  Settings &settings = Settings::instance();
  int window_x_center = settings.getWindowWidth() / 2;
  int window_y_center = settings.getWindowHeight() / 2;
  UIButtonBuilder Play = UIButtonBuilder()
                             .text("Play")
                             .position({static_cast<float>(window_x_center),
                                        window_y_center - 75.0f})
                             .size({100, 50})
                             .color(COLOR_BLACK);

  UIButtonBuilder Quit = UIButtonBuilder()
                             .text("Quit")
                             .position({static_cast<float>(window_x_center),
                                        window_y_center - 15.0f})
                             .size({100, 50})
                             .color(COLOR_BLACK);
  UIButton *Play_btn = Play.build();
  UIButton *Quit_btn = Quit.build();
  Play_btn->ButtonClicked().Subscribe(
      []() { Game::requestSceneChange(SCENES::GAMEPLAY); });
  Quit_btn->ButtonClicked().Subscribe([]() { Game::requestQuit(); });
  m_container.add(Play_btn);
  m_container.add(Quit_btn);
}
