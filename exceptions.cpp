// Exceptions in C++
//
#include <iostream>
#include <print>
#include <string>

class RuntimeError {
  std::string err_mssg;

public:
  RuntimeError(const std::string &err) : err_mssg(err) {};

  virtual const std::string what() const { return err_mssg; };

  virtual ~RuntimeError() = default;
};

class InvalidArgumentError : public RuntimeError {
public:
  explicit InvalidArgumentError(const std::string &msg)
      : RuntimeError("Invalid Agrument Error: " + msg) {};
};

class OutofRangeError : public RuntimeError {
public:
  explicit OutofRangeError(const std::string &msg)
      : RuntimeError("Invalid Agrument Error: " + msg) {};
};

class LogicalError : public RuntimeError {
public:
  explicit LogicalError(const std::string &msg)
      : RuntimeError("Invalid Agrument Error: " + msg) {};
};

std::string cmp(int a, int b) {
  if (a <= 0 || b <= 0)
    throw InvalidArgumentError("Arguments cannot be equal to or less than 0");
  return a < b ? std::format("{} is greater than {}", b, a)
               : std::format("{} is greater than {}", a, b);
}

int main() {
  // sth sinister
  try {
    std::println("{}", cmp(-8, 15));
  } catch (const InvalidArgumentError &err) {
    std::cerr << err.what() << "\n";
  };

  return 0;
}
