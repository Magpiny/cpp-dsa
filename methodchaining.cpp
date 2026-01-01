#include <print>
#include <string>

struct Character {
  std::string name;
  int health = 100;

  // "Self" is a template parameter.
  // It will automatically become Character&, const Character&, or Character&&
  // depending on how you call it!
  template <typename Self> auto &&set_name(this Self &&self, std::string &&n) {
    self.name = std::move(n);
    return std::forward<Self>(self); // Returns exactly the right type of 'this'
  }

  template <typename Self> auto &&take_damage(this Self &&self, int amount) {
    self.health -= amount;
    return std::forward<Self>(self);
  }
};

int main() {
  // Elegant method chaining!
  Character hero;
  hero.set_name("Aragorn").take_damage(20).take_damage(10);

  std::println("Name: {} Health: {}", hero.name, hero.health);

  return 0;
}
