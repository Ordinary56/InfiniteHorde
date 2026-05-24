#pragma once
#include "core/events/eventManager.hpp"
#include "entity/enemy.h"
#include <cstddef>
#include <iterator>
constexpr int INITIAL_CAPACITY = 15;
class Enemy;
class Renderer;

// Heterogen collection for entities

class EnemyManager {

public:
  class iterator;
  class const_iterator;
  EnemyManager();

  EnemyManager(const EnemyManager &other) = delete;
  EnemyManager &operator=(const EnemyManager &other) = delete;

  ~EnemyManager();

  void addEnemy(Enemy *enemy);
  void removeEnemy(std::size_t index);

  void update();

  EventManager<void> &onEnemyKilled();

  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  inline std::size_t size() const { return m_capacity; }

  class iterator : public std::iterator<std::forward_iterator_tag, Enemy> {
  public:
    iterator() : ptr(nullptr) {}
    explicit iterator(Enemy *p) : ptr(p) {}
    Enemy &operator*() const { return *ptr; }
    Enemy *operator->() const { return ptr; }
    iterator &operator++() {
      ++ptr;
      return *this;
    }
    iterator operator++(int) {
      iterator tmp = *this;
      ++ptr;
      return tmp;
    }
    bool operator==(const iterator &other) const { return ptr == other.ptr; }
    bool operator!=(const iterator &other) const { return !(*this == other); }

  private:
    Enemy *ptr;
  };
  class const_iterator : public iterator {
  public:
    const_iterator() : iterator() {}
    explicit const_iterator(const Enemy *p)
        : iterator(const_cast<Enemy *>(p)) {}
    const Enemy &operator*() const { return iterator::operator*(); }
    const Enemy *operator->() const { return iterator::operator->(); }
  };

private:
  void resize();
  Enemy *m_enemies = nullptr;
  std::size_t m_capacity = INITIAL_CAPACITY;
  std::size_t m_count = 0;
  EventManager<void> m_enemyKilled;
};
