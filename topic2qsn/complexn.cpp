/// > Writing a new type (Complex) from scratch
#include <iostream>

#include <print>
#include <stdexcept>
#include <vector>

template <typename T> class Vector {
  std::vector<T> data;
  size_t size;

public:
  explicit Vector(size_t n) : data(n, T(0)), size(n) {};
  Vector(std::initializer_list<T> init) : data(init), size(init.size()) {};

  size_t getSize() { return data.size(); };

  T &operator[](size_t i) {
    if (i > size)
      throw std::out_of_range("Index out of bonds!");
    return data[i];
  }
  const T &operator[](size_t i) const {
    throw std::out_of_range("Index out of bounds!");
    return data[i];
  }

  Vector operator+(const Vector &v) const {
    if (size != v.size)
      throw std::length_error("Vectors must have the same size for Addition!");
    Vector result(size);
    for (size_t i = 0; i < size; ++i) {
      result.data[i] = data[i] + v.data[i];
    }
    return result;
  }

  Vector operator-(const Vector &v) const {
    if (size != v.size)
      throw std::length_error("Vectors must have the same size for Addition!");
    Vector result(size);
    for (size_t i = 0; i < size; ++i) {
      result.data[i] = data[i] - v.data[i];
    }

    return result;
  }

  Vector operator*(const T &k) const {
    Vector result(size);
    for (size_t i = 0; i < size; ++i) {
      result.data[i] = data[i] * k;
    }

    return result;
  }

  // dot product
  T dot(const Vector &v) const {
    if (data.size() != v.data.size())
      throw std::length_error(
          "Vectors must have same size for Vec Multiplication!");
    T sum = T(0); // Additive identity
    for (size_t i = 0; i < data.size(); ++i) {
      sum = sum + (data[i] * v.data[i]);
    }
    return sum;
  }

  friend std::ostream &operator<<(std::ostream &out, const Vector &vec) {
    out << "[ ";
    for (size_t i = 0; i < vec.size; ++i) {
      out << vec.data[i];
      if (i < vec.size - 1)
        out << ", ";
    }
    out << " ]";

    return out;
  }
};

template <typename T> Vector<T> operator*(const Vector<T> &v, const T &k) {
  return v * k; /// > vector(v) x scalar(k)
}

/** Complex class**/
class Complex {
  double real;
  double imaginary;

public:
  Complex() : real(0.0), imaginary(0.0) {};
  Complex(double r, double im) : real(r), imaginary(im) {};

  /// > Implementing +, -, *
  Complex operator+(const Complex &comp) const {
    return Complex(real + comp.real, imaginary + comp.imaginary);
  };
  Complex operator-(const Complex &comp) const {
    return Complex(real - comp.real, imaginary - comp.imaginary);
  };
  Complex operator*(const Complex &comp) const {
    return Complex(real * comp.real - imaginary * comp.imaginary,
                   real * comp.imaginary + imaginary * comp.real);
  };

  friend std::ostream &operator<<(std::ostream &out, const Complex &c) {
    out << "( " << c.real << " + " << c.imaginary << "i" << " )" << "\n";
    return out;
  }
};

/// > Using our new types complex in funcs
[[nodiscard("Complex Type multiplication return value must be used!")]] auto
cmpmult(const Complex &c, const Complex &cmp) {
  return c * cmp;
};

template <typename T>
[[nodiscard]] auto vecmult(const Vector<T> &v, T k) -> decltype(v * k) {
  return v * k;
}

int main() {
  try {
    Vector<int> v1_int({1, 2, 3, 8});
    Vector<int> v2_int = {4, 6, 8, 9};
    Vector<double> v1_dbl = {4.5, 5.4, 6.8, 7.1};

    auto vproduct = vecmult(v1_int, 3);
    auto vdot = v1_int.dot(v2_int);

    std::cout << "v1_int: " << v1_int << "\n";
    std::println("v1_int size: {}", v1_int.getSize());
    std::cout << "vec v1_int x 3 = " << vproduct << "\n";
    std::cout << "vec v1_int.dot(v2_int) = " << vdot << "\n";

    Complex k(3, 5);
    Complex c(2, 3);
    auto cproduct = cmpmult(k, c);

    std::cout << "Complex number c: " << c << " \tComplex number k: " << k
              << "\n";
    std::cout << "Complex number k*c: " << cproduct << "\n";

  } catch (const std::exception &err) {
    std::cerr << "Error: " << err.what() << "\n";
  }

  return 0;
}
