#include "entity/player.h"

#ifndef CPORTA
#include "core/input/raylibInputSystem.h"
#else
#include "core/input/consoleInputSystem.h"
#endif

#include "core/renderer/renderer.h"
#include "helpers/utils.hpp"

Player::Player(float x, float y) : Entity(x, y), m_weapon(x, y) {}
void Player::draw(Renderer &renderer) const {
  int pos_x = static_cast<int>(m_position.x);
  int pos_y = static_cast<int>(m_position.y);
  renderer.drawRectangle(pos_x, pos_y, m_hitBox.w, m_hitBox.h, COLOR_BLUE);
  m_weapon.draw(renderer);
}

void Player::update(float dt) {

  // Keep weapon attached to player
  const Rect &weaponHitbox = m_weapon.getHitBox();
  int hitbox_w = weaponHitbox.w;
  int hitbox_h = weaponHitbox.h;
  m_weapon.setPos(m_position.x + hitbox_w, m_position.y + hitbox_h);
#ifndef CPORTA
  RaylibInputSystem &input = RaylibInputSystem::instance();
#else
  ConsoleInputSystem &input = ConsoleInputSystem::instance();
#endif
  if (input.getKeyDown(InputAction::MoveUp)) {
    m_position.y -= dt * m_speed * 5;
  }
  if (input.getKeyDown(InputAction::MoveDown)) {
    m_position.y += dt * m_speed * 5;
  }
  if (input.getKeyDown(InputAction::MoveLeft)) {
    m_position.x -= dt * m_speed * 5;
  }
  if (input.getKeyDown(InputAction::MoveRight)) {
    m_position.x += dt * m_speed * 5;
  }
  m_hitBox.x = m_position.x;
  m_hitBox.y = m_position.y;
}

const Rect &Player::getHitBox() const { return m_hitBox; }

const float &Player::getHealth() const { return m_health; }

bool Player::isDead() const { return m_isDead; }

void Player::takeDamage(float damage) {

  m_health = utils::clamp<float>(m_health - damage, 0, 100);
  if (m_health == 0) {
    m_isDead = true;
  }
  m_damageTimer.start(0.75f);
}

Weapon &Player::getWeapon() { return m_weapon; }
