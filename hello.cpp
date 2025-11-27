#include <print>
#include <string>

int main() {
  short int age = 20;
  float height = 1.389e-3f;

  // pointers &--> Address of
  char grade = 'A';
  char *g_addr = &grade;

  // strings
  std::string mname = "Joel Doe"; // stl-strings

  // enum and structs
  enum position { GK, DF, MDF, ATT }; // enum

  // struct
  struct Player {
    std::string pname;
    short int age;
    float height;
    position p_pos;
  };

  Player p1 = {"John Koffi", 23, 123e-2f, MDF};
  Player *p2 = new Player;

  p2->age = 27;
  p2->height = 1.61;
  p2->pname = "Janeko Kipkalia";
  p2->p_pos = GK;

  // casting
  int a = 23;
  float b = (float)a; // c-style casting
  float d = float(a); // c++ casting

  std::string gt = (10 > 30) ? "10 > 30" : "10<30";

  std::println("{}", gt);

  std::println("Name: {} height {}", p2->pname, p2->height);

  std::println("Name: {} position: {}", p1.pname, static_cast<int>(p1.p_pos));

  std::println("value: {}", *g_addr);

  std::println("I'm {}yrs old height: {}", age, height);

  delete p2;    // <-- memory leak source
  p2 = nullptr; // <-- dangling pointers source

  return EXIT_SUCCESS;
}
