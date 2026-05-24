#pragma once
#include <raylib.h>
class Settings {
public:
  Settings(const Settings &other) = delete;
  Settings &operator=(const Settings &other) = delete;

  static Settings &instance() {
    static Settings _instance;
    return _instance;
  }

  // Getters
  inline int getWindowWidth() const { return m_windowWidth; }
  inline int getWindowHeight() const { return m_windowHeight; }

  inline int getFontSize() const { return m_fontSize; }

  // Setters
  inline void setWindowWidth(int width) { m_windowWidth = width; }
  inline void setWindowHeight(int height) { m_windowHeight = height; }

private:
  Settings() = default;
  int m_windowWidth = 600;
  int m_windowHeight = 800;
  int m_fontSize = 15;
};
