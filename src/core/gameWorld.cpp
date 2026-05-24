#include "core/gameWorld.h"
#include "core/renderer/renderer.h"


void GameWorld::draw(Renderer &renderer) const {
  renderer.drawRectangle(m_worldBoundary.x, m_worldBoundary.y,
                         m_worldBoundary.w, m_worldBoundary.h,
                         {128, 128, 128, 255});
}

const Rect &GameWorld::getWorldBoundary() const { return m_worldBoundary; }
