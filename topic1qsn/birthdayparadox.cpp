/*
The birthday paradox says that the probability that two
people in a room will have the same birthday is more
than half as long as the number of people in the room (n),
is more than 23. This property is not really a para- dox,
but many people find it surprising. Design a C++ program
that can test this paradox by a series of experiments on
randomly generated birth- days, which test this paradox
for n = 5, 10, 15, 20, . . . , 100. You should run at least
10 experiments for each value of n and it should output,
for each n, the number of experiments for that n, such that
two people in that test have the same birthday.
*/
#include <iostream>
#include <print>
#include <stdexcept>
#include <string>

using std::println;
using std::string;

/*
    Birthday Paradox Simulation
    Objective: Test how many people (n) are needed in a room
    before it's likely two share a birthday.
*/

#include <iostream>
#include <print>  // For std::print / std::println
#include <random> // For random number generation
#include <vector>

// --> Helper Function: Get a random day (1 - 365)
// Why? We encapsulate the complex random logic here so main() stays clean.
int get_random_birthday() {
  // We use 'static' so the generator is created only once (performance)
  static std::mt19937 mt{std::random_device{}()};
  static std::uniform_int_distribution<> dist{1, 365};
  return dist(mt);
}

// --> Helper Function: Run one experiment
// Why? This isolates the logic of "checking a room" from the logic of "counting
// stats". Returns: true if two people share a birthday, false otherwise.
bool check_for_shared_birthday(int n_people) {
  // 1. Create a list (vector) to hold the birthdays
  std::vector<int> room;

  // 2. Fill the room with random birthdays
  for (int i = 0; i < n_people; ++i) {
    room.push_back(get_random_birthday());
  }

  // 3. Check for duplicates
  // We use a "Nested Loop" approach.
  // Take person 'i' and compare them against every subsequent person 'j'.
  for (size_t i = 0; i < room.size(); ++i) {
    for (size_t j = i + 1; j < room.size(); ++j) {

      // If they have the same number, we found a shared birthday!
      if (room[i] == room[j]) {
        return true;
      }
    }
  }

  // If we finish the loops without returning true, no matches were found.
  return false;
}

int main() {
  std::println("Birthday Paradox Simulation");
  std::println("{:=^50}", "");
  std::println(" {:^10} | {:^15} | {:^15} ", "People(n)", "Experiments",
               "Matches Found");
  std::println("{:-^50}", "");

  // The question asks for n = 5, 10, 15 ... up to 100.
  // So we step by 5.
  for (int n = 5; n <= 100; n += 5) {

    int matches_found = 0;
    int total_experiments =
        100; // Question says "at least 10". 100 gives better accuracy.

    // Run the experiment multiple times for this specific 'n'
    for (int i = 0; i < total_experiments; ++i) {
      if (check_for_shared_birthday(n)) {
        matches_found++;
      }
    }

    // Output the results for this group size
    std::println(" {:^10} | {:^15} | {:^15} ", n, total_experiments,
                 matches_found);
  }

  std::println("{:=^50}", "");
  return EXIT_SUCCESS;
}
