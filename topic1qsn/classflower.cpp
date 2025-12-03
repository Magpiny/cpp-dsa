#include <iostream>
#include <print>
#include <string>

class Flower {
public:
  Flower(const std::string name, int numofpetals, float amount)
      : flower_name(name), number_of_petals(numofpetals), price(amount) {};

  Flower() {
    flower_name = "Rose flower";
    number_of_petals = 71;
    price = 400.25f;
  };

  // --> Getters
  inline float getPrice() { return price; };
  inline const std::string getName() { return flower_name; };
  inline int getNumberOfPetals() { return number_of_petals; };

  // --> Setters
  void set_flowerName(const std::string &flowerName) {
    flower_name = flowerName;
  }
  void set_numofpetals(const int &petals_qty) { number_of_petals = petals_qty; }
  void set_price(const float &amount) { price = amount; }

  // --> print class items
  void print() {
    println("Flower Name: {} Number of Petals: {} Cost: {}", flower_name,
            number_of_petals, price);
  }

  friend std::ostream &operator<<(const std::ostream &out, const Flower &f);

private:
  std::string flower_name;
  int number_of_petals;
  float price;
};

int main() {
  Flower f;
  f.print();

  return 0;
}
