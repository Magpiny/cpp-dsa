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

#include <array>
#include <iostream>
#include <limits>
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

bool is_leap_year(int year) {
  return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int days_in_feb(int year) { return is_leap_year(year) ? 29 : 28; }

bool is_valid_year(int year) { return year >= 1 && year <= 9999; };

// Calculates the day of the week for January 1st of the given year
// Returns: 0 = Sunday, 1 = Monday, ..., 6 = Saturday
int calculate_jan_1_day(int year) {
  int y = year - 1;
  return (y + y / 4 - y / 100 + y / 400 + 1) % 7;
}

// Calender function
void print_calendar(int year, int start_day_num) {
  std::println("\n{:=^40}", "");
  std::println("  {:^40}  ", std::format("Calender for the year {}   ", year));

  int day_of_week = start_day_num;

  for (size_t month = 0; month < MONTHS.size(); ++month) {
    std::string month_name = (MONTHS[month]);

    // Month name centered over a calendar
    std::println("{:^28}", month_name);

    // Day headers(Sun Mon Tue Wed Thur Fri Sat Sun)
    for (const auto &d : DAYS_ABBR) {
      std::print(" {:^3} ", d);
    }
    std::println("");

    // Printing Leading spaces for 1st week
    for (int i = 0; i < day_of_week; ++i) {
      std::print("     ");
    }

    // Set number of days for each month
    int days = (month == 1) ? days_in_feb(year) : DAYS_IN_MONTH[month];

    // --> Print all days of the particular month
    for (int date = 1; date <= days; ++date) {
      std::print("\033[1;36m{:^4}\033[0m ", date);

      // move to the next day of the week and move to the next line if its a
      // saturday (>6)
      if (++day_of_week > 6) {
        day_of_week = 0;
        std::println(" ");
      }
    }

    // End current line if not already at start of new line
    if (day_of_week != 0)
      std::println("");

    std::println(); // space between months
  }
}

int main(int argc, char *argv[]) {
  try {
    std::string day;
    int year;

    // cli first implementation; ENTER values at once
    if (argc == 2) {
      year = std::stoi(argv[1]);
    } else {

      // Enter values one by one through prompts
      std::print("Enter four-digit year: ");
      std::cin >> year;
    }
    // Verify user input
    if (!is_valid_year(year)) {
      throw std::out_of_range("Year must be between 1 and 9999!!");
    }
    // Handle cin failure states
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      throw std::invalid_argument("Invalid input");
    }

    int start_day = calculate_jan_1_day(year);
    print_calendar(year, start_day);
  } catch (const std::invalid_argument &e) {
    std::cerr << "Invalid argument: " << e.what() << "\n";
    return 1;
  } catch (const std::out_of_range &err) {
    std::cerr << "Invalid argument: " << err.what() << "\n";
    return 1;
  }

  return 0;
}
