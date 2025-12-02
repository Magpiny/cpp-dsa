#include <cstdlib>
#include <format>
#include <iostream>
#include <print>
#include <stdexcept>

void printArray(size_t rows, size_t cols) {

  if (rows <= 0 || cols <= 0)
    throw std::invalid_argument(
        std::format("row and columns must be greater that zero\n RECEIVED: "
                    "rows = {} columns = {}",
                    rows, cols));

  int **A = new int *[rows];

  // Allocate memory for each row
  for (size_t i = 0; i < rows; ++i)
    A[i] = new int[cols];

  // outer row
  for (size_t i = 0; i < rows; ++i) {
    // for each column
    for (size_t j = 0; j < cols; ++j) {
      A[i][j] = i * cols + j;
      std::cout << A[i][j] << " \t";
    }
    std::println("\n");
  }

  // free up memory: each row;
  for (size_t i = 0; i < rows; ++i) {
    delete[] A[i];
  }

  // free the entire 2d mem alloc
  delete[] A;
};

int main() {
  try {
    printArray(8, 8);
  } catch (const std::invalid_argument &e) {
    std::cerr << "Error: " << e.what() << "\n";
  };

  return EXIT_SUCCESS;
}
