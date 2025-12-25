#include <cctype>
#include <iostream>
#include <map>
#include <print>
#include <sstream>

int main() {
  std::println("Enter words separated by space..");

  // Read the entire line
  std::string line;
  std::getline(std::cin, line);

  // spline line using sstream
  std::stringstream ss(line);
  std::string word;

  // Map to store word count
  std::map<std::string, int> wordcount;

  // Extract each word and count it
  while (ss >> word) {
    ++wordcount[word];
  }

  std::cout << "\n===Word frequency count===\n";
  std::cout << "===Word \tCount\t===\n";
  std::cout << "===********************===\n";
  for (const auto &pair : wordcount) {
    std::println("{} \t\t {}", pair.first, pair.second);
  }

  std::println("------------------------ ---");
  std::println("Total Unique Words: {}", wordcount.size());

  return 0;
}
