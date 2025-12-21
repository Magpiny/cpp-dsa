#include <print>

int imposibo(int sth) {
  if (sth > 0 && sth < 0)
    std::println("This is impossible");
  return sth;
}

int main() {
  int imp = imposibo(56);
  std::println("is it?: {}", imp);

  return 0;
}
