#include "core/camera/cameraController.h"

CameraController::CameraController() : CameraController({0.0f, 0.0f}) {}
CameraController::CameraController(const Vec2 &offset_vec) {
  m_camera.offset = offset_vec;
}

void CameraController::setOffset(const Vec2 &new_offset) {
  m_camera.offset = new_offset;
}

void CameraController::setTarget(const Vec2 &target_vec) {
  m_camera.target = target_vec;
}

const CameraData &CameraController::getCamera() const { return m_camera; }
