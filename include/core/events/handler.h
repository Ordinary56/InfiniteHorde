#pragma once
#include <cstddef>
#include <functional>
template <typename TOut, typename... Args> struct Handler {
  std::size_t id;
  std::function<TOut(Args...)> func;
};
