#include <chrono>
#include <iostream>
#include <list>
#include <numeric> // for std::iota
#include <vector>

// A helper function to easily time code blocks
template <typename Func> void measure_time(const std::string &name, Func func) {
  auto start = std::chrono::high_resolution_clock::now();

  func(); // Run the task

  auto end = std::chrono::high_resolution_clock::now();

  // Calculate duration in milliseconds
  std::chrono::duration<double, std::milli> duration = end - start;
  std::cout << name << " took: " << duration.count() << " ms\n";
}

int main() {
  const int N = 10'000'000; // 10 Million elements

  std::cout << "Initializing containers (this might take a moment)...\n";
  std::vector<int> vec(N, 1);
  std::list<int> lst(N, 1);

  std::cout << "--- Starting Benchmark ---\n";

  // Test 1: Vector Traversal
  measure_time("Vector Sum", [&]() {
    long long sum = 0;
    for (int x : vec) {
      sum += x;
    }
    // We print sum to prevent the compiler from optimizing the loop away
    // entirely
    std::cout << "  (Sum: " << sum << ") ";
  });

  // Test 2: List Traversal
  measure_time("List Sum  ", [&]() {
    long long sum = 0;
    for (int x : lst) {
      sum += x;
    }
    std::cout << "  (Sum: " << sum << ") ";
  });

  return 0;
}
