#pragma once
struct Platform {

  virtual ~Platform() = default;
  virtual void initWindow(int w, int h, const char *title) = 0;
  virtual bool shouldClose() = 0;

  virtual float getDeltaTime() = 0;
  virtual void shutdownWindow() = 0;
};
