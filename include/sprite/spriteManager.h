#pragma once
#include "sprite/sprite_entry.h"
#include <cstddef>
#include <raylib.h>
#include <string>

// Constants
//
// the initial capacity count for the array
constexpr int INITIAL_CAPACITY_COUNT = 16;

// class for storing sprite imagese
// NOTE: this class is responsible for the lifetime of sprites
class SpriteManager {
public:
  // constructs and allocates resources for the members
  SpriteManager();

  // Delete the entries when the manager's lifetime ended
  ~SpriteManager();

  // prevent double deletes
  SpriteManager(const SpriteManager &other) = delete;

  // do not assign to another, there should be one SpriteManager
  SpriteManager &operator=(const SpriteManager &other) = delete;

  // Loads all the sprites specified in the specified folder
  // NOTE: if no image files were found in the folder,
  // this function doesn't do anything
  void loadSprites(const std::string &folder);

  // Returns the sprite's image from the array
  // @param - the sprite's name
  //
  // NOTE: if not found or the array is empty,
  // it returns NULL
  //
  // @returns - a pointer to the image, nullptr if not found or the array is empty
  // NOTE: Do not free the pointer
  Image *getSprite(const std::string &name);

private:
  // changes the dynamic array's size to fit more sprites
  void grow();

  SpriteEntry *m_sprites = nullptr;
  std::size_t m_capacity = INITIAL_CAPACITY_COUNT;
  std::size_t m_size = 0;
};
