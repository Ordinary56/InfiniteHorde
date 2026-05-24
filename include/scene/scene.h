#pragma once
enum class SCENES { MAIN_MENU, GAMEPLAY, GAME_OVER };

class Renderer;

class IScene {
public:
  virtual ~IScene() = default;
  virtual void update(float dt) = 0;
  virtual void draw(Renderer &renderer) const = 0;
};
