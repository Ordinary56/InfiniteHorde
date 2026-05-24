#pragma once
#include "scene/scene.h"

// Heterogen class for storing scenes
// NOTE: SceneManager is reponsible for the lifetime of objects

class SceneManager {
public:
  SceneManager() = default;
  ~SceneManager();

  // sets the current scene to a different one
  // @param scene - A scene from the SCENES enum
  // NOTE: for more informaion on the SCENES enum, look for it's implementation
  // in the scene.h declaration file
  void setScene(SCENES scene);

  // Call the current scene's update function
  void update(float dt);

  // Call the current scene's draw function
  // @param renderer - The current backend renderer
  void draw(Renderer &renderer) const;

private:
  static bool m_requestedSceneChange;
  IScene *m_currentScene = nullptr;
};
