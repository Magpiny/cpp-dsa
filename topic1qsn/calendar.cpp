/*
Write a C++ program that, when given a starting day
(Sunday through Saturday) as a string, and a four-digit
year, prints a calendar for that year. Each month should
contain the name of the month, centered over the dates
for that month and a line containing the names of the
days of the week, running from Sunday to Saturday.
Each week should be printed on a sep- arate line.
Be careful to check for a leap year.
*/

#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <print>
#include <stdexcept>
#include <string>

constexpr std::array<std::string, 12> MONTHS = {
    "January", "February", "March",     "April",   "May",      "June",
    "July",    "August",   "September", "October", "November", "December"};
constexpr std::array<std::string, 7> DAYS = {"Sunday",    "Monday",   "Tuesday",
                                             "Wednesday", "Thursday", "Friday",
                                             "Saturday"};

constexpr std::array<std::string, 7> DAYS_ABBR = {"Sun", "Mon", "Tue", "Wed",
                                                  "Thu", "Fri", "Sat"};
constexpr std::array<int, 12> DAYS_IN_MONTH = {31, 28, 31, 30, 31, 30,
                                               31, 31, 30, 31, 30, 31};
// --> Helper functions
std::string str2upper(const std::string &str) {
  std::string res = str;
  std::transform(res.begin(), res.end(), res.begin(), ::tolower);
  return res;
}

bool is_leap_year(int year) {
  return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int days_in_feb(int year) { return is_leap_year(year) ? 29 : 28; }

// Convert day name to number (Sunday = 0)
int day_name_to_num(const std::string &day) {
  for (int i = 0; i < 7; ++i) {
    if (DAYS[i].starts_with(day) || DAYS_ABBR[i] == day) {
      return i;
    }
  }
  throw std::invalid_argument("Invalid day name");
}

// Calender function
void print_calendar(int year, int start_day_num) {
  std::println("    {:^4}   ", year);
  std::println();

  int day_of_week = start_day_num;

  for (size_t month = 0; month < MONTHS.size(); ++month) {
    // Month name centered
    std::string month_name = MONTHS[month];
    int spaces = (20 - month_name.length()) / 2;
    std::print("{:>10}", "", spaces + 10);
    std::println("{}", month_name);

    // Day headers
    for (const auto &d : DAYS_ABBR) {
      std::print(" {} ", d);
    }
    std::println("");

    // Leading spaces
    for (int i = 0; i < day_of_week; ++i) {
      std::print("   ");
    }

    int days = (month == 1) ? days_in_feb(year) : DAYS_IN_MONTH[month];

    for (int date = 1; date <= days; ++date) {
      std::print("{:>4} ", date);

      if (++day_of_week > 6) {
        day_of_week = 0;
        std::println("");
      }
    }
    if (day_of_week != 0)
      std::println(""); // final newline
    std::println("");   // space between months

    day_of_week = (day_of_week + days) % 7; // carry over to next month
  }
}

int main() {
  try {
    std::string day;
    int year;

    std::print("Enter starting day (e.g. Sunday, Sun, Su): ");
    std::cin >> day;
    std::print("Enter four-digit year: ");
    std::cin >> year;

    int start_day = day_name_to_num(day);
    print_calendar(year, start_day);
  } catch (const std::invalid_argument &e) {
    std::cerr << "Invalid argument" << "\n";
  }

  return 0;
}
