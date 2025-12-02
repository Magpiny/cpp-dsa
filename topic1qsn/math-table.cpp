#include <cctype>
#include <iostream>
#include <print>
#include <stdexcept>

// function signature
void print_math_table(long width, long height);

int main() {
  try {
    print_math_table(19, 19);
  } catch (const std::invalid_argument &err) {
    std::cerr << "Error: " << err.what() << "\n";
  }

  return 0;
}

// --> Function definition
void print_math_table(long rows, long cols) {
  if (rows <= 0 || cols <= 0) {
    std::invalid_argument("arguments must be positive integers");
  }

  // --> Make the table
  long **math_table = new long *[rows];

  // create the rows
  for (long i = 0; i < rows; ++i) {
    math_table[i] = new long[cols];
  }

  // --> Print the table Heading
  const std::string table_title = "A Multiplication Table";
  std::println("\n{:<10} : {}x{}", table_title, rows - 1, cols - 1);

  // --> Print the table header row
  std::print("   X  ");
  for (long j = 0; j < cols; ++j) {
    std::print("{:>4}", j);
  }
  std::print("\n ----|");
  for (long j = 0; j < cols; j++)
    std::print("----");
  std::println();

  // --> Print the contents of the table
  for (long i = 0; i < rows; ++i) {
    std::print("{:4} |", i);
    for (long j = 0; j < cols; ++j) {
      math_table[i][j] = i * j;
      std::print("{:4}", math_table[i][j]);
    }
    std::println("");
  }

  // deallocate memory
  for (long i = 0; i < rows; ++i) {
    delete[] math_table[i];
  }

  delete[] math_table;
}
