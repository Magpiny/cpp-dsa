/// > This program attempts to calculate the amount of different coins
/// > and notes given in change when one buys sth. We use kenyan currency
/// > denominations here. Kibaki's  40bob rightfully ignored here.

#include <cmath>
#include <format>
#include <iostream>
#include <limits>
#include <print>
#include <string_view>
#include <vector>

const std::vector<std::pair<uint16_t, std::string_view>> denoms = {
    {1000, "thao"}, {500, "punch"}, {200, "rwabe"},
    {100, "soo"},   {50, "chwani"}, {20, "mbao"},
    {10, "kinde"},  {5, "kobole"},  {1, "Bob"}};

double get_amount(std::string_view prompt) {
  double amount;
  std::println("{}", prompt);

  while (!(std::cin >> amount) || amount < 0) {
    std::cerr << "Invalid Input: Please enter a non negative number >0" << "\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max());
  }
  return amount;
}

int main() {
  std::println("========================** Change Maker **==================");

  double charged = get_amount("Enter amount charged (Ksh): ");
  double given = get_amount("Enter amount given (Ksh.): ");

  if (given < charged) {
    std::println(
        "Insufficient funds: You need ksh.{} more to complete your purchase!",
        std::abs(given - charged));
    return 1;
  }

  double change = given - charged;

  if (change == 0) {
    std::println("No change needed. Thank you!");
    return 0;
  }

  int remaining = static_cast<int>(std::round(change));
  for (const auto &[value, name] : denoms) {
    int count = remaining / value;
    if (count > 0) {
      std::println(" {} x {} ", count, name);
      remaining -= count * value;
    }
  }
  std::println("============ ********************* ====================");
  std::println("***CHANGE: Ksh. {}*** ===CHARGED: {} ===Amount Paid: {}",
               change, charged, given);

  return 0;
}
