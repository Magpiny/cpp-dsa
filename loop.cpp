#include <print>

enum Medal { GOLD, SILVER, BRONZE };

int main() {

  // switch statement

  Medal medal = BRONZE;
  switch (medal) {
  case GOLD:
    std::println("NO. 1: Won Gold");
    break;

  case SILVER:
    std::println("No. 2: Won Gold");
    break;

  case BRONZE:
    std::println("No.3: Won Gold");
    break;

  default:
    std::println("Try next time");
    break;
  };

  // while loop
  int n = 20;
  while (n >= 0) {
    std::println("N is {}", n);
    n -= 1;
  }

  // do while loop
  do {
    std::println("T is {}", n);
    n++;
  } while (n <= 30);

  // using continue; break and return in loops
  // ie printing odd number between 1 and 50
  while (n > 0) {
    if (n % 2 == 0) {
      n--;
      continue;
    }

    std::println("odd number: {}", n);
    n--;
  }
}
