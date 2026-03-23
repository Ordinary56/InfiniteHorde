#include "NH/player.h"
#include <iostream>
#include <raymath.h>
static constexpr float RADIUS = 4.5f;

Player::Player(float x, float y) : Entity(x, y) {}
void Player::draw() const {
  int pos_x = static_cast<int>(m_position.x);
  int pos_y = static_cast<int>(m_position.y);
  DrawEllipse(pos_x, pos_y, RADIUS, RADIUS, RED);
}

void Player::loop(float dt) {
  if (IsKeyDown(KEY_W))
    m_position.y -= m_speed * dt;
  if (IsKeyDown(KEY_S))
    m_position.y += m_speed * dt;
  if (IsKeyDown(KEY_A))
    m_position.x -= m_speed * dt;
  if (IsKeyDown(KEY_D))
    m_position.x += m_speed * dt;
}
