#include "sprite/spriteManager.h"

SpriteManager::SpriteManager() {
  m_sprites = new SpriteEntry[m_capacity];
}

SpriteManager::~SpriteManager() {
  delete[] m_sprites; 
}
void SpriteManager::loadSprites(const std::string& folder) {
  (void)folder;
}
Image* SpriteManager::getSprite(const std::string& name) {
  (void)name;
  return nullptr;
}

void SpriteManager::grow() {
  ;
}

