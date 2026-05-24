#pragma once

class Timer {
public:
  Timer() = default;
  void start(float duration);
  void update(float dt);
  void reset();
  bool isFinished() const;
  bool isRunning() const;

private:
  float m_duration = 0.0f;
  float m_elapsed = 0.0f;
  bool m_running = false;
  bool m_finished = false;
};
