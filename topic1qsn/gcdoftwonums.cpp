#include "../benchmark.hpp"

int main() {
  const int repetitions = 100;
  int m = 80844, n = 25320; // The two expected integers

  auto gcd_loop = [](int a, int b) -> int {
    while (b != 0) {
      int remainder = a % b;
      a = b;
      b = remainder;
    }
    return a;
  };

  auto gcd_recursion = [](this auto &&self, int x, int y) -> int {
    return y == 0 ? x : self(y, x % y);
  };

  // Test if the funcs are working by printing the gcd to console
  std::println("GCD from loop is {}", gcd_loop(m, n));
  std::println("GCD from recursion is {}", gcd_recursion(m, n));

  // Benchmark the speed of two functions ie loop vs recursion
  benchmark("Loop GCD", [&]() { gcd_loop(m, n); }, repetitions);
  benchmark("Recursion GCD", [&]() { gcd_recursion(m, n); }, repetitions);
}
