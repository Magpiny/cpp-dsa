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

/*
Write a short C++ function that takes a positive double
value x and returns the number of times we can divide x
by 2 before we get a number less than 2.
*/

double div_times(double n) {
  if (n <= 0) {
    throw std::invalid_argument("Value must be greater than zero!");
  }
}
