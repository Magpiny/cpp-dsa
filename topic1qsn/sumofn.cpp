// sum of numbers less than n

#include <print>

int sumofnumberslessthan_n(int n) {
  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    arr[i] = i;
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }

  delete[] arr;

  return sum;
};

int main() {
  int norma = sumofnumberslessthan_n(940);
  std::println("sum of n is {}", norma);

  return 0;
}
