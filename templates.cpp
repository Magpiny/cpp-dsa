#include "progression.hpp"

/// Templates
/// A function template is a blueprint for a family of functions.
/// You write it once — it works with int, double, std::string, your Vector2,
/// anything.

/// 1.0 Function templates
template <typename T, typename U>
T sumoftwo(T a, U b) { // sum of any two values of numerical type;
  return a + b;
}

template <typename T> void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;

  std::cout << std::format(" {} {}", a, b) << std::endl;
}

/// 2.0 Class Templates i.e Vector version 2
template <typename T> class MyVector {
  T a;
  T b;

public:
  // MyVector type ctor
  MyVector(T x = T(), T y = T()) : a(x), b(y) {};

  // operator+ add two vectors of type MyVector
  MyVector operator+(const MyVector &other) {
    return MyVector(a + other.a, b + other.b);
  };

  // operator* multiply
  MyVector operator*(T scalar) const {
    return MyVector(a * scalar, b * scalar);
  };

  friend MyVector operator*(T scalar, const MyVector &v) { return scalar * v; };

  // operator[] access operator
  T &operator[](int index) {
    // access value in 'array'
    return index == 0 ? a : b;
  };

  const T &operator[](int index) const {
    // const value [] overloading
    return index == 0 ? a : b;
  };

  // operator== -comparison
  bool operator==(const MyVector &v) const { return a == v.a && b == v.b; };

  // operator<< for printing type elements
  friend std::ostream &operator<<(std::ostream &out, const MyVector &v) {
    out << std::format("({},{}) \n", v.a, v.b);
    return out;
  };
};

int main() {
  Progression *fb = new FibonacciPg();
  fb->print_progression(10);

  // Templates (function templates)
  int sm = sumoftwo(12, 13);
  std::cout << sm << std::endl;
  std::cout << sumoftwo(12.5, 13.9) << std::endl;

  // function templates
  int x = 9;
  int y = 10;
  swap(x, y);

  std::string fnm = "Magpiny";
  std::string lnm = "BO";

  swap(fnm, lnm);
  std::cout << fnm << " " << lnm << std::endl;

  // class templates
  MyVector<int> v1 = {3, 4};
  MyVector<double> v2 = {2.34, 8.66};
  MyVector<std::string> str = {"Magpiny", "BO"};
  MyVector<int> v4{3, 4};

  std::cout << v1 << std::endl;
  std::cout << v2 << std::endl;
  std::cout << str << std::endl;

  std::cout << v1 * 2 << std::endl;
  std::cout << v2 + v2 << std::endl;
  std::cout << str[1] << std::endl;

  bool comp = v1 == v4 ? true : false;
  std::cout << comp << std::endl;

  delete fb;
  return EXIT_SUCCESS;
}
