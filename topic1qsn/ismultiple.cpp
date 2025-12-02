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
  std::println("Is 30 multipe of 7? {}", isMultiple(-7, 30));

  return EXIT_SUCCESS;
}
