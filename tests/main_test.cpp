#include "core/game.h"
#include "core/renderer/consoleRenderer.h"
#include "gtest_lite/gtest_lite.h"
#include "platform/consolePlatform.h"
int main() {
  ConsolePlatform platform;
  ConsoleRenderer renderer;
  Game game(platform, renderer);
  TEST(GAME, OPENSWINDOW) {
    game.run(); 
    EXPECT_NO_THROW();
  }
  END

  TEST(GAME, WINDOWNOTCLOSED) {
    EXPECT_FALSE(platform.shouldClose());  
  }
  END



}
