/*
 *
 *Write a C++ function printArray(A, m, n) that prints
 * an m × n two- dimensional array A of integers, declared
 * to be “int** A,” to the standard output. Each of the m rows
 * should appear on a separate line.
 */

#include <iostream>
#include <print>
#include <stdexcept>

void printArray(int **A, size_t m, size_t n) {
  if (A == nullptr || m <= 0 || n <= 0) {
    throw std::invalid_argument(
        "A must be a valid pointer and m & n must be greater than zero, 0!");
  }

  for (size_t i = 0; i < m; ++i) {
    for (size_t j = 0; j < n; j++) {
      std::print("{:4}", A[i][j]);
    }
    std::println("");
  }
}

int main() {
  try {
    size_t cols = 13;
    size_t rows = 14;

    int **B = new int *[rows];

    for (size_t i = 0; i < rows; ++i) {
      B[i] = new int[cols];
      for (size_t j = 0; j < cols; ++j) {
        B[i][j] = i * cols + j + 1;
      }
    }

    printArray(B, rows, cols);

    for (size_t i = 0; i < rows; ++i) {
      delete[] B[i];
    };
    delete[] B;
  } catch (const std::invalid_argument &e) {
    std::cerr << "Error: " << e.what() << "\n";
  }

  return 0;
}
