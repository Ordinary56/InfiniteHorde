#pragma once
#include "handler.h"
#include <iostream>

/// @summary - generic class for storing generic handlers
///
template <typename TOut = void, typename... Args> class EventManager {
public:
  EventManager() : m_handlers(new Handler<TOut, Args...>[m_capacity]) {}

  // Free all subscribers
  ~EventManager() {
    delete[] m_handlers;
    m_size = 0;
    m_capacity = 0;
  }

  // Invoke the event handler and notify the subscribers
  template <typename... CallArgs> void Invoke(CallArgs &&...args) {
    for (std::size_t i = 0; i < m_size; ++i) {
      m_handlers[i].func(std::forward<CallArgs>(args)...);
    }
  }

  // Subscribe a handler
  // @param func - the target function
  // @return - an ID for the function
  std::size_t Subscribe(std::function<TOut(Args...)> func) {
    if (m_size >= m_capacity)
      resize();
    std::size_t id = m_nextId++;
    m_handlers[m_size++] = {id, func};
    return id;
  }

  // Unsubscribe a handler
  // @param id - the handler's id for this instance of EventManager
  void Unsubscribe(std::size_t id) {
    for (std::size_t i = 0; i < m_size; ++i) {
      if (m_handlers[i].id == id) {
        for (std::size_t j = i; j < m_size - 1; ++j) {
          m_handlers[j] = std::move(m_handlers[j + 1]);
        }
        --m_size;
        return;
      }
    }
  }

private:
  void resize() {
    std::size_t newCapacity = m_capacity * 2;

    auto *new_handlers = new Handler<TOut, Args...>[newCapacity];

    for (std::size_t i = 0; i < m_size; ++i) {
      new_handlers[i] = std::move(m_handlers[i]);
    }

    delete[] m_handlers;

    m_handlers = new_handlers;
    m_capacity = newCapacity;
  }
  std::size_t m_size = 0;
  std::size_t m_capacity = 25;
  std::size_t m_nextId = 1;
  Handler<TOut, Args...> *m_handlers;
};
