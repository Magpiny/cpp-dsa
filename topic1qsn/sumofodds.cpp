#include <print>

int sumofodds(int n) {
  int *nums = new int[n];

  for (int i = 0; i < n; ++i) {
    nums[i] = i;
  }

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0)
      continue;
    sum = sum + nums[i];
  }

  delete[] nums;

  return sum;
};

long long sumOfOdds(int n) {
  int k = n / 2; // for n=7 → k=3 (1+3+5), n=8 → k=4 (1+3+5+7)
  return 1LL * k * k;
}

int main() {
  int sumofods = sumofodds(4);
  std::println("Sum of odd numbers less than {} is {}", 7, sumOfOdds(7));

  return 0;
}
