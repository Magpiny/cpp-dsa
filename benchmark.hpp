#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <chrono>
#include <print>

template <typename Func>
void benchmark(const std::string &fname, Func &&func, int REPS) {
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < REPS; ++i) {
    func();
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto time_dur =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  std::println("[{:<15}] {:>6} reps → {:>12} ns → {:>8.2f} ns/call", fname,
               REPS, time_dur, double(time_dur) / REPS);
}

#endif
