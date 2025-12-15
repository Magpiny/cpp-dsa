/**
 * @brief A header only c++ progression library
 * @author Magpiny BO
 * @date 15 December 2025
 *  @warning Ensure proper memory management while using this library
 * @note This library implements arithmetic, geometric and fibonacci
 * progressions only
 *
 */
#pragma once

#include <format>
#include <iostream>

/**
 * @brief Basic Usage
 * @code
 * #include "progression.hpp"
 *
 * int main(){
 * Progression *ap = new ArithProgression(2, 3);
 * ap->print_progression(10);
 *
 * delete ap;
 *
 * return EXIT_SUCCESS;
 * }
 * @endcode
 */

/**
 * @class Progression
 * @brief Abstract base class representing a generic numeric progression.
 *
 * This class defines the common interface for all progressions.
 * It cannot be instantiated directly because next_value() is pure virtual.
 * Derived classes must implement their specific way of advancing to the next
 * term.
 */
class Progression {
public:
  /**
   * @brief Resets the progression and returns the first value.
   *
   * This function is called at the beginning of print_progression()
   * to ensure the sequence starts from the beginning.
   * @return The first value in the progression.
   */
  virtual long first_value();

  /**
   * @brief Advances to and returns the next value in the progression.
   *
   * This is a pure virtual function – derived classes must provide
   * their own implementation.
   * @return The next value in the sequence.
   */
  virtual long next_value() = 0;

  /**
   * @brief Prints the first n terms of the progression.
   *
   * The output is space-separated on a single line followed by a newline.
   * @param n Number of terms to print (n ≥ 1).
   */
  void print_progression(int n);

  /** @brief Virtual destructor to allow proper cleanup of derived objects. */
  virtual ~Progression() = default;

protected:
  long curr;  ///< Current value in the progression
  long first; ///< First value of the progression
};

/**
 * @class ArithProgression
 * @brief Arithmetic progression: each term is obtained by adding a fixed
 * increment.
 *
 * Example with increment = 3, first = 2: 2, 5, 8, 11, ...
 */
class ArithProgression : public Progression {
public:
  /**
   * @brief Constructs an arithmetic progression.
   *
   * @param i Increment (default = 1)
   * @param f First value (default = 0)
   */
  ArithProgression(long i = 1, long f = 0);

  /**
   * @brief Returns the next term in the arithmetic progression.
   *
   * Adds the fixed increment to the current value.
   * @return The next value.
   */
  long next_value() override;

  friend std::ostream &operator<<(std::ostream &out,
                                  const ArithProgression &sdt);

protected:
  long inc; ///< Fixed increment added at each step
};

/**
 * @class GeometricProgression
 * @brief Geometric progression: each term is obtained by multiplying by a fixed
 * base.
 * @see FibonacciPg
 * Example with base = 2, first = 1: 1, 2, 4, 8, ...
 */
class GeometricProgression : public Progression {
public:
  /**
   * @brief Constructs a geometric progression.
   *
   * The first term is always 1.
   * @param b Multiplication factor (default = 2)
   */
  GeometricProgression(long b = 2);

  /**
   * @brief Returns the next term in the geometric progression.
   *
   * Multiplies the current value by the fixed base.
   * @return The next value.
   */
  long next_value() override;

protected:
  long base; ///< Fixed multiplier applied at each step
};

/**
 * @class FibonacciPg
 * @brief Fibonacci Progression: each term is the sum of the previous two terms
 * @note Example; with first term 0 and second term 1; the next term is 0+1=1,
 * ie 0,1,1,2,3,5,8,13,21,...
 */
class FibonacciPg : public Progression {
protected:
  long sec_v; ///< second value
  long prev;  ///< previous value

public:
  /**
   * @brief FibonacciPg constructor
   * Takes two arguments first value and second value
   * @param[in] f first value
   * @param[in] s second value
   * Initialize f and s to 0 and 1 respectively
   */
  FibonacciPg(long f = 0, long s = 1);

  /**
   * @brief sets the first value
   * @return first value
   */
  long first_value() override;

  /**
   * @brief Calculates the next value in the progression
   * @return next value in fibonacci progression
   */
  long next_value() override;
};

ArithProgression::ArithProgression(long i, long f) {
  inc = i;
  first = f;
  curr = f;
};

long Progression::first_value() {
  curr = first;
  return curr;
}

long ArithProgression::next_value() {
  curr += inc;
  return curr;
}

void Progression::print_progression(int n) {
  std::cout << std::format("{}", first_value());
  for (int i = 2; i <= n; ++i) {
    std::cout << std::format(" {} ", next_value());
  };
  std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &out, const ArithProgression &apg) {
  out << "first value: " << apg.first << " Current value: " << apg.curr
      << "increment by: " << apg.inc << "\n";

  return out;
};

/// Geometric Progression
GeometricProgression::GeometricProgression(long b) : base(b) {
  first = 1;
  curr = 1;
};

long GeometricProgression::next_value() {
  curr *= base;
  return curr;
}

/// Fibonacci Progression
FibonacciPg::FibonacciPg(long first_value, long second_value) {
  first = first_value;
  sec_v = second_value;
  prev = sec_v - first;
}

long FibonacciPg::first_value() {
  curr = first;
  prev = sec_v - first;
  return curr;
}

long FibonacciPg::next_value() {
  long next = curr + prev;
  prev = curr;
  curr = next;
  return curr;
}
