#include "NH/game.h"
#include "NH/player.h"
static constexpr int FPS = 60;
Game::Game() {
  InitWindow(WIDTH, HEIGHT, "GAME");
  SetTargetFPS(FPS);
  m_font = LoadFont("/usr/share/fonts/TTF/FiraCode-Bold.ttf");
  addEntity(new Player(WIDTH / 2.0f, HEIGHT / 2.0f));
}

Game::~Game() {
  for (Entity *ent : m_entities) {
    delete ent;
  }
  UnloadFont(m_font);
  CloseWindow();
}

void Game::run() {
  while (!WindowShouldClose()) {
    float dt = GetFrameTime();
    for (Entity *ent : m_entities) {
      ent->loop(dt);
    }
    BeginDrawing();
    ClearBackground(WHITE);
    for (Entity *ent : m_entities) {
      ent->draw();
    }
    DrawFPS(WIDTH - 90, 10);
    EndDrawing();
  }
}

void Game::addEntity(Entity *ent) { m_entities.push_back(ent); }

std::vector<Entity *> &Game::getEntityContainer() { return m_entities; }
