#include "entity/enemyManager.h"

EnemyManager::EnemyManager() { m_enemies = new Enemy[m_capacity]; }
EnemyManager::~EnemyManager() {
  delete[] m_enemies;
  m_enemies = nullptr;
  m_count = 0;
  m_capacity = 0;
}

void EnemyManager::addEnemy(Enemy *ent) {
  if (ent == nullptr) {
    return;
  }
  if (m_count >= m_capacity) {
    delete ent;
    return;
  }
  m_enemies[m_count++] = *ent;
  delete ent;
}

void EnemyManager::removeEnemy(std::size_t index) {
  if (index >= m_count) {
    return;
  }
  m_enemies[index] = std::move(m_enemies[m_count - 1]);
  --m_count;
  m_enemyKilled.Invoke();
}
void EnemyManager::resize() {
  m_capacity *= 2;
  Enemy *temp = new Enemy[m_capacity];
  for (size_t i = 0; i < m_count; i++) {
    temp[i] = m_enemies[i];
  }
  delete[] m_enemies;
  m_enemies = temp;
}

void EnemyManager::update() {
  std::size_t index = 0;
  while (index < m_count) {
    if (m_enemies[index].isDead()) {
      removeEnemy(index);
    } else {
      ++index;
    }
  }
}

EventManager<void> &EnemyManager::onEnemyKilled() { return m_enemyKilled; }

EnemyManager::iterator EnemyManager::begin() { return iterator(m_enemies); }
EnemyManager::iterator EnemyManager::end() {
  return iterator(m_enemies + m_count);
}

EnemyManager::const_iterator EnemyManager::begin() const {
  return const_iterator(m_enemies);
}
EnemyManager::const_iterator EnemyManager::end() const {
  return const_iterator(m_enemies + m_count);
}
