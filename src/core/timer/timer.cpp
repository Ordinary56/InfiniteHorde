#include "core/timer/timer.h"

void Timer::start(float duration) {
  m_duration = duration;
  m_elapsed = 0.f;
  m_finished = false;
  m_running = true;
}
void Timer::update(float dt) {
  if (!m_running || m_finished)
    return;

  m_elapsed += dt;

  if (m_elapsed >= m_duration) {
    m_finished = true;
    m_running = false;
  }
}

void Timer::reset() {
  m_elapsed = 0.f;
  m_finished = false;
  m_running = false;
}

bool Timer::isRunning() const { return m_running; }

bool Timer::isFinished() const { return m_finished; }
