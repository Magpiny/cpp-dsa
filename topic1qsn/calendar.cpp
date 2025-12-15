/**
 * @file calendar.cpp
 * @brief A C++23 console application to generate a yearly calendar.
 * @details This program accepts a four-digit year and prints a formatted calendar
 * for that year to the standard output. It handles leap year logic, calculates
 * the starting day of the week automatically, and formats the output using
 * `std::print` and ANSI color codes.
 * * @note This program requires a C++23 compliant compiler due to the usage
 * of `<print>` and `std::format`.
 */

#include <array>
#include <iostream>
#include <limits>
#include <print>
#include <stdexcept>
#include <string>

/**
 * @defgroup Constants Global Configuration Constants
 * @brief Static data used for calendar generation.
 * @{
 */

/// @brief Full names of the twelve months.
constexpr std::array<std::string, 12> MONTHS = {
  "January", "February", "March",     "April",   "May",      "June",
  "July",    "August",   "September", "October", "November", "December"};

  /// @brief Full names of the seven days of the week.
  constexpr std::array<std::string, 7> DAYS = {"Sunday",    "Monday",   "Tuesday",
    "Wednesday", "Thursday", "Friday",
    "Saturday"};

    /// @brief Abbreviated names of the days for column headers.
    constexpr std::array<std::string, 7> DAYS_ABBR = {"Sun", "Mon", "Tue", "Wed",
      "Thu", "Fri", "Sat"};

      /// @brief Standard number of days in each month (non-leap year).
      constexpr std::array<int, 12> DAYS_IN_MONTH = {31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31};
        /// @}

        // --> Helper functions

        /**
         * @brief Checks if a specific year is a leap year.
         * @details A year is a leap year if it is divisible by 4, except for end-of-century
         * years, which must be divisible by 400.
         * * @param year The year to validate.
         * @return `true` if the year is a leap year, `false` otherwise.
         */
        bool is_leap_year(int year) {
          return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
        }

        /**
         * @brief Determines the number of days in February for a specific year.
         * * @param year The year to check.
         * @return `29` if the year is a leap year, `28` otherwise.
         */
        int days_in_feb(int year) { return is_leap_year(year) ? 29 : 28; }

        /**
         * @brief Validates if the year is within the supported range.
         * * @param year The year input by the user.
         * @return `true` if year is between 1 and 9999, `false` otherwise.
         */
        bool is_valid_year(int year) { return year >= 1 && year <= 9999; };

        /**
         * @brief Calculates the day of the week for January 1st of the given year.
         * @details This function uses a variation of the standard day-of-week algorithms
         * (similar to Gauss's or Zeller's) to determine the offset.
         * * @param year The four-digit year.
         * @return An integer representing the day of the week (0 = Sunday, 1 = Monday, ..., 6 = Saturday).
         */
        int calculate_jan_1_day(int year) {
          int y = year - 1;
          return (y + y / 4 - y / 100 + y / 400 + 1) % 7;
        }

        /**
         * @brief Prints the formatted calendar to the console.
         * @details Iterates through all 12 months, calculating spacing for the first week
         * and wrapping weeks correctly. It highlights the date numbers in Cyan using ANSI escape codes.
         * * @param year The year to display.
         * @param start_day_num The calculated weekday index (0-6) for January 1st of that year.
         */
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
              // Print date in Cyan (ANSI \033[1;36m) and reset (\033[0m)
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

        /**
         * @brief Main entry point of the application.
         * @details Handles user input via Command Line Arguments or Standard Input.
         * It validates the input for numeric consistency and range before generating the calendar.
         * * @param argc Number of command-line arguments.
         * @param argv Array of command-line argument strings.
         * @return `0` on success, `1` on error (invalid input or out of range).
         * * @throws std::invalid_argument If non-numeric input is provided via `std::cin`.
         * @throws std::out_of_range If the year is not between 1 and 9999.
         */
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
