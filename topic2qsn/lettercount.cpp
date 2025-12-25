#include <cctype>
#include <iostream>
#include <map>
#include <print>
#include <string>

int main() {
  std::map<char, int> char_count;

  std::println(
      "Enter text (press Ctrl+D on Unix/Mac or Ctrl+Z on Windows when done)");
  std::println("{}", '-' * 23);

  std::string line;
  int total_alpha = 0; // Total alphabetic characters

  while (std::getline(std::cin, line)) {
    for (char ch : line) {
      if (std::isalpha(ch)) {
        char lower =
            static_cast<char>(std::tolower(static_cast<unsigned int>(ch)));
        char_count[lower]++;
        total_alpha++;
      }
    }
  }

  if (total_alpha == 0) {
    std::println("\n No alphabetic x-ters found in the input");
    return 0;
  }

  /// > // Find the maximum frequency for scaling the bar chart
  int max_br_frq = 0;
  for (auto &pair : char_count) {
    if (pair.second > max_br_frq) {
      max_br_frq = pair.second;
    }
  }

  /// > Calulate the bar width
  const int MAX_BAR_WIDTH = 80;
  double scale = (max_br_frq > MAX_BAR_WIDTH)
                     ? static_cast<double>(MAX_BAR_WIDTH) / max_br_frq
                     : 1.0;

  std::println("{}", '=' * 23);
  std::println("CHARACTER FREQUENCY BAR CHART");
  std::println("{}", '=' * 23);
  std::println("Total alphabetic characters: {}", total_alpha);
  std::println("Total unique letters: {}", char_count.size());
  std::println("{}", '-' * 23);

  for (auto &pair : char_count) {
    auto letter = pair.first;
    auto count = pair.second;
    auto bar_length = static_cast<int>(count * scale);
    auto percent = (static_cast<double>(count) / total_alpha) * 100.0;

    std::print("{}\t\t{}\t", letter, count);
    std::print("{:.1f}% | ", percent);

    for (int i = 0; i < bar_length; ++i) {
      std::print("█");
    }

    std::println();
  }

  std::println("{}", '-' * 23);

  if (scale < 1.0) {
    std::print("Note: Bars are scale max({} ) chars = {} occurences",
               MAX_BAR_WIDTH, max_br_frq);
  }

  return 0;
}
