#include <climits>
#include <cstdint>
#include <iostream>
#include <print>

int main() {
  std::println("Enter a +ve integer greater than 2");

  uint64_t number;

  if (!(std::cin >> number)) {
    std::println("{} is not a number!", number);
    return 1;
  }

  if (number <= 2) {
    std::println("Error: Number must be greater than 2");
    return 1;
  }

  if (number > std::numeric_limits<uint64_t>::max()) {
    std::println("Overflow error: {} is greater than the type max size ",
                 number);
    return 1;
  }

  int count = 0;
  while (number >= 2) {
    number /= 2;
    count++;
  }

  std::println("It takes {} divisions by 2 to get to less than 2", count);

  return 0;
}
