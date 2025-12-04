/*
Write an efficient C++ function that takes any integer
value i and returns 2i , as a long value. Your function
should not multiply 2 by itself i times; there are much
faster ways of computing 2i .
*/

#include <format>
#include <print>
#include <stdexcept>

// ???? Bit shift sth sth!

using std::format;

long twopower_i(int i) {
  // Check error bounds
  if (i < 0)
    throw std::invalid_argument(
        format("Only positive integers accepted! :{} is negative", i));

  if (i > 62)
    throw std::overflow_error(
        format("2^{} is too big for a long: Expected 2^n<=62", i));

  return 1L << i;
}

int main() {
  int poweri = 7;
  std::println("2 power {} is {}", poweri, twopower_i(poweri));

  return 0;
}
