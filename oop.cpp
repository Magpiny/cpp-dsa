/**
 *  OOP (Classes in CPP)
 *  Abstract classes
 *  Inheritance
 *  Polymorphism
 *  Access modifiers --> public, private, protected
 *
 *
 */

#include <format>
#include <iostream>

class Progression {
public:
  virtual long first_value();
  virtual long next_value() = 0;
  void print_progression(int n);

  virtual ~Progression() = default;

protected:
  long curr;
  long first;
  long inc;
};

/// Child classes: Arithmetic Progression
class ArithProgression : public Progression {
public:
  ArithProgression(long i = 1, long f = 0);

  long next_value() override;

  friend std::ostream &operator<<(std::ostream &out,
                                  const ArithProgression &sdt);
};

/// Child classes: Geometric Progression
class GeometricProgression : public Progression {
public:
  GeometricProgression(long b = 2);

  long next_value() override;

protected:
  long base;
};

class FibonacciPg : public Progression {
protected:
  long sec_v;
  long prev;

public:
  FibonacciPg(long f = 0, long s = 1);

  long first_value() override;
  long next_value() override;
};

int main() {
  int a = 12;
  ArithProgression *ap = new ArithProgression(3, 2);

  // Polymorphism
  Progression *gp = new GeometricProgression(2);
  Progression *fbp = new FibonacciPg();

  ap->print_progression(a);
  gp->print_progression(a);
  fbp->print_progression(a);

  /// freeup memory after use
  delete ap;
  delete gp;
  delete fbp;

  return 0;
}

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
  long temp = prev;
  prev = curr;
  curr += temp;
  return curr;
}
