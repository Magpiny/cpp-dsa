#include <iostream>
#include <print>
#include <stdexcept>

// function signature
void print_math_table(long width, long height);

int main(int argc, char *argv[]) {
  try {
    long cols;
    long rows;

    if (argc == 3) {
      cols = std::stoi(argv[1]);
      rows = std::stoi(argv[2]);
    } else {
      // Enter values one by one through prompts
      std::print("Enter number of rows: ");
      std::cin >> rows;
      std::print("Enter number of columns: ");
      std::cin >> cols;
    }

    // Handle cin failure states
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      throw std::invalid_argument("Invalid input");
    }

    print_math_table(cols, rows);
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
  long **math_table = new long *[rows + 1];

  // create the rows
  for (long i = 1; i < rows + 1; ++i) {
    math_table[i] = new long[cols + 1];
  }

  // --> Print the table Heading
  const std::string table_title = "A Multiplication Table";
  std::println("\n{:<20} : {}x{}", table_title, rows, cols);

  // --> Print the table header row
  std::print("\033[1;32m {:^5} \033[0m", "X");

  for (long j = 1; j < cols + 1; ++j) {
    std::print("\033[1;31m{:4}\033[0m", j);
  }

  std::print("\n -----|");
  for (long j = 1; j < cols + 1; j++)
    std::print("----");
  std::println();

  // --> Print the contents of the table
  for (long i = 1; i < rows + 1; ++i) {
    std::print("\033[1;31m {:4} |\033[0m", i);
    for (long j = 1; j < cols + 1; ++j) {
      math_table[i][j] = i * j;
      std::print("\033[1;34m{:4}\033[0m", math_table[i][j]);
    }
    std::println("");
  }

  // deallocate memory
  for (long i = 1; i < rows + 1; ++i) {
    delete[] math_table[i];
  }

  delete[] math_table;
}
