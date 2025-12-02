#include <print>

struct Pair {
  int first;
  double second;
};

int main() {
  // --> 3 ways of defining a struct"❯"

  Pair sem;
  sem.first = 12;
  sem.second = 12.0;

  Pair sem2(13, 13.5);

  Pair *sem3 = new Pair();
  sem3->first = 14;
  sem3->second = 14.5;

  double *db[10];
  for (int i = 0; i < 10; i++) {
    db[i] = new double();
    *db[i] = 0.0;
    std::println("i is: {}", *db[i]);
  };

  for (int i = 0; i < 10; i++) { // free up memory
    delete db[i];
    db[i] = nullptr;
  };

  std::println("Hello world {}", sem3->second);

  delete sem3;
  sem3 = nullptr;
}
