#pragma once
#include "NH/entity.h"
#include <memory>
#include <raylib.h>
#include <vector>
class Game {
public:
  Game();
  Game(const Game &other) = delete;
  Game(Game &&other) = delete;
  Game &operator=(const Game &other) = delete;
  ~Game();

  void run();
  void addEntity(Entity* ent);

  // Getters
  std::vector<Entity*> &getEntityContainer();

  inline static int getWidth() { return WIDTH; }
  inline static int getHeight() { return HEIGHT; }

private:
  static constexpr int WIDTH = 600, HEIGHT = 800;
  std::vector<Entity*> m_entities;
  Font m_font;
};
