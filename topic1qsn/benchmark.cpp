#include <chrono>
#include <print>
#include <string>
#include <thread>

// Your original mortal version
long long sumOfOdds_loop(long long n) {
  long long sum = 0;
  for (long long i = 1; i < n; i += 2) {
    sum += i;
  }
  return sum;
}

// Nephilim + Math Guru version
long long sumOfOdds_math(long long n) {
  long long k = n / 2;
  return k * k; // 1 + 3 + 5 + ... + (2k-1) = k²
}

// The benchmarking god function
void benchmark_function(const std::string &name, auto &&func, long long n,
                        int repetitions = 100) {
  using namespace std::chrono;
  auto start = high_resolution_clock::now();

  long long result = 0;
  for (int i = 0; i < repetitions; ++i) {
    result += func(n); // force computation
  }

  auto end = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(end - start);

  std::println(
      "[{}] {:>12} reps → {:>8} ns total → {:>6.2f} ns per call → result = {}",
      name, repetitions, duration.count(),
      duration.count() / double(repetitions), result / repetitions);
}

int main() {
  const long long N = 1'000LL; // 1 billion
  const int REPS = 200;        // repeat 200 times for stable timing

  std::println("ULTIMATE BENCHMARK: Sum of odds < {} ({} times each)", N, REPS);
  std::println("─────────────────────────────────────────────────────────────");

  // Run both in parallel — like gods racing
  std::jthread t1([&] {
    std::print("Starting LOOP version on core {}...",
               std::this_thread::get_id());
    std::println("");
    benchmark_function("LOOP (mortal)", sumOfOdds_loop, N, REPS);
  });

  std::jthread t2([&] {
    std::print("Starting MATH version on core {}...",
               std::this_thread::get_id());
    std::println("");
    benchmark_function("MATH (Nephilim)", sumOfOdds_math, N, REPS);
  });

  return 0;
}
