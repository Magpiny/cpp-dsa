// Returns true if m is a multiple of n

#include <format>
#include <print>
#include <stdexcept>

bool isMultiple(long m, long n) {
  if (m <= 0 || n <= 0) {
    throw std::invalid_argument(std::format(
        "Both m and n must be greater than zero, 0!!\n Received: m = {} n = {}",
        m, n));
  };

  // simple and readable
  if (n % m == 0) {
    return true;
  };

  return false;
};

int main() {
  int a = 50;
  int b = 68;
  int mod = (a - b) % 100;

  std::println("(50-68)%100 is:{}", mod);
  std::println("Is 30 multipe of 10? {}", isMultiple(10, 30));

  return EXIT_SUCCESS;
}
