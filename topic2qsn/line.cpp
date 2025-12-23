/*
 * Design a class Line that implements a line, which is represented by the
 * formula y = ax + b. Your class should store a and b as double member
 * variables. Write a member function intersect(ℓ) that returns the x
 * coordinate at which this line intersects line ℓ. If the two lines are
 * parallel, then your function should throw an exception Parallel. Write
 * a C++ program that creates a number of Line objects and tests each pair
 * for intersection. Your program should print an appropriate error message
 * for parallel lines.
 */

#include <format>
#include <iostream>
#include <print>
#include <stdexcept>
#include <vector>

class Parallel : public std::exception {
public:
  const char *what() const noexcept override {
    return "Lines are parallel - no intersection";
  };
};

class Line {
  double a; // slope
  double b; // x-intercept
public:
  Line(double slope, double x_intercept) : a(slope), b(x_intercept) {};

  /// @brief Returns x where this line intersects this other
  double intersect(const Line &l) const {
    if (a == l.a)
      throw Parallel();
    return ((l.b - b) / (l.a - a));
  }

  void print() const { std::println("y = {}x + {}", a, b); }
};

int main() {
  std::vector<Line> lines = {Line(0, 3), Line(3, 3), Line(2, 1), Line(2, 1)};

  std::println("Testing all pairs for intersection");

  for (size_t i = 0; i < lines.size(); ++i) {
    for (size_t j = i + 1; j < lines.size(); ++j) {
      std::print(" Line {}: ", i);
      lines[i].print();

      std::print("\n Line {}: ", j);
      lines[j].print();
      std::println();

      try {
        double x = lines[i].intersect(lines[j]);
        std::println(" -> intersect at x = {} \n\n", x);
      } catch (const Parallel &err) {
        std::cerr << " --> " << err.what() << "\n\n";
      }
    }
  }

  return 0;
}
