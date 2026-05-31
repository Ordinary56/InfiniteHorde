#include "core/game.h"
#include "core/input/consoleInputSystem.h"
#include "core/renderer/consoleRenderer.h"
#include "platform/consolePlatform.h"
#include "scene/gameplayScene.h"
#include "gtest_lite/gtest_lite.h"
#include "memtrace/memtrace.h"

int main() {
  GTINIT(std::cin);
  ConsolePlatform platform;
  ConsoleRenderer renderer;
  Game game(platform, renderer);
  TEST(game, openswindow) { game.run_once(); }
  ENDM

  TEST(game, scenechangesuccess) {
    Game::requestSceneChange(SCENES::GAMEPLAY);
    game.run_once();
    const GameplayScene *scene =
        dynamic_cast<const GameplayScene *>(game.getSceneManager().getScene());
    EXPECT_TRUE(scene != nullptr)
        << " == GameplayScene pointer == nulptr!! ==\n";
  }
  ENDM TEST(gameplay, playermoves) {
    std::stringstream fakeInput;
    fakeInput << "wa\n";
    ConsoleInputSystem::instance().setInput(fakeInput);
    const GameplayScene *scene =
        dynamic_cast<const GameplayScene *>(game.getSceneManager().getScene());
    auto &player = scene->getPlayer();
    const Vec2 &player_pos = player.getPos();
    Vec2 prev_pos = {player_pos.x, player_pos.y};
    game.run_once();
    EXPECT_NE(player_pos.x, prev_pos.x)
        << "== JÁTÉKOS NEM MOZDULT(x tengely) ==\n";
    EXPECT_NE(player_pos.y, prev_pos.y)
        << "== JÁTÉKOS NEM MOZDULT(y tengely) ==\n";
    ConsoleInputSystem::instance().setInput(std::cin);
  } ENDM 

  TEST(gameplay, player_can_shoot) {
      std::stringstream fakeInput;
      fakeInput << "f";
      ConsoleInputSystem::instance().setInput(fakeInput);
      game.run_once();
    const GameplayScene *scene =
        dynamic_cast<const GameplayScene *>(game.getSceneManager().getScene());
    const ProjectileManager& manager = scene->getProjectileManager();
    EXPECT_EQ(manager.getProjectileCount(), 1UL);
    ConsoleInputSystem::instance().setInput(std::cin);
      
  } ENDM
  TEST(gameplay, enemy_score_on_death) {
    const GameplayScene *scene =
        dynamic_cast<const GameplayScene *>(game.getSceneManager().getScene());
    GameplayScene* temp = const_cast<GameplayScene*>(scene); 
    EnemyManager& enemyManager = temp->getEnemyManager();
    Enemy* temp_enemy = new Enemy();
    enemyManager.addEnemy(temp_enemy);
    game.run_once();
    EXPECT_EQ(enemyManager.count(), 1UL);
    temp_enemy->takeDamage(100.0f); 
    game.run_once();
    EXPECT_EQ(temp->getScoreCount(), 1);
    EXPECT_EQ(enemyManager.count(), 0UL);
  }
  ENDM
  TEST(gameplay, player_took_damage) {
    // from the previous test case, the enemy spawns on top of player
    // they were colliding before the enemy was deleted, so the player
    // took damage from it
    const GameplayScene *scene =
        dynamic_cast<const GameplayScene *>(game.getSceneManager().getScene());
    
    EXPECT_NE(scene->getPlayer().getHealth(), 100.f);
  } ENDM

  if (!gtest_lite::test.fail() && gtest_lite::test.failed == 0) {
    std::cout << "== Az összes teszt eseten átment! == \n";
  }
  GTEND(std::cerr);
  return 0;
}
