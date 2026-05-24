#pragma once

#include "cameraData.h"
class CameraController {
public:
  // Constructor/Desctructors
  CameraController();
  CameraController(const Vec2 &offset_vec);
  ~CameraController() = default;

  // Set the offset of the camera
  // @param new_offset - The camera's new offset
  void setOffset(const Vec2 &new_offset);

  // Set the target the player follows
  // @param target_vec - The target vector where the camera will look at
  void setTarget(const Vec2 &target_vec);

  // Get the camera.
  // This reference is immutable
  // @returns - A reference to the camera
  const CameraData &getCamera() const;

private:
  CameraData m_camera;
};
