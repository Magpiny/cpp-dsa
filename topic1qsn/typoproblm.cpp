/* PROBLEM STATEMENT
A common punishment for school children is to write out the
same sen- tence multiple times. Write a C++ stand-alone program
that will write out the following sentence one hundred times:
“I will always use object- oriented design.” Your program should
number each of the sentences and it should “accidentally” make
eight different random-looking typos at var- ious points in the
listing, so that it looks like a human typed it all by hand.
*/

// SOLUTION
/*
Print “I will always use object- oriented design.” a hundred times
Exactly 8 of those lines must contain human-looking typos
The typos must be random in position and type
It must look like a real child made the mistakes — not obvious patterns
The program must be stand-alone (no input, just runs)
*/

// --> Code:
#include <algorithm>
#include <print>
#include <random>
#include <string>
#include <vector>

using std::println;
using std::random_device; // true h/w randomness
using std::string;

void typoproblem();

int main() {
  typoproblem();

  return EXIT_SUCCESS;
};

void typoproblem() {
  const string sentence = "I will always use object - oriented design";
  const int total_lines = 100;
  const int typo_count = 8;

  random_device rd;
  std::mt19937 gen(rd()); // seed

  std::uniform_int_distribution<> line_dist(1, total_lines);
  std::uniform_int_distribution<> pos_dist(0, 35);
  std::uniform_int_distribution<> typo_type(0, 5);

  std::vector<int> typo_lines; // container for the 8 lines with typo

  while (typo_lines.size() < typo_count) {
    int line = line_dist(gen);

    // Weed out duplicates
    if (std::find(typo_lines.begin(), typo_lines.end(), line) ==
        typo_lines.end()) {
      typo_lines.push_back(line);
    }
  }

  // Iterate thought the 100 lines and commit the 5 deadly sins randomly
  for (int i = 1; i <= total_lines; ++i) {
    string line = sentence;

    // commit the 5 deadly sins(5 different typos)
    if (std::find(typo_lines.begin(), typo_lines.end(), i) !=
        typo_lines.end()) {
      size_t pos = pos_dist(gen);
      string s;

      // Apply if this lin is chosen
      if (pos < line.length()) {
        switch (typo_type(gen)) {
        case 0: // swap
          line[pos] = line[pos] == 'o' ? 'O' : 'o';
          break;
        case 1: // delete a character
          if (pos + 1 < line.length())
            line.erase(pos, 1);
          break;
        case 2: // add a similar extra character
          line.insert(pos, 1, line[pos]);
          break;
        case 3: // switch characters
          if (pos > 0)
            line[pos - 1] = line[pos];
          break;
        case 4: // add vowel swap
          line[pos] = string{"aeiou"}[typo_type(gen) % 5];
          break;
        }
      }
    }
    println("{:>4}. {}", i, line);
  }
};
