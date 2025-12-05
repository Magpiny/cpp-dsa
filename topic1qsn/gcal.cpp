#include <array>
#include <chrono> // For automatic day calculation
#include <format>
#include <iostream>
#include <print>
#include <string>
#include <vector>

class CalendarYear {
public:
  CalendarYear(int year, int start_day_index)
      : m_year(year), m_start_day_index(start_day_index) {}

  // 1. Separation of Concerns: This function yields a buffer (string)
  // instead of printing directly. This allows us to print to file, console, or
  // GUI.
  std::string to_string() const {
    std::string buffer;
    std::format_to(std::back_inserter(buffer), "\n{:=^40}\n", "");
    std::format_to(std::back_inserter(buffer), "  {:^40}  \n",
                   std::format("Calendar for {}", m_year));

    int current_day_of_week = m_start_day_index;

    for (size_t i = 0; i < 12; ++i) {
      buffer += generate_month(i, current_day_of_week);
    }
    return buffer;
  }

private:
  int m_year;
  int m_start_day_index;

  // Constexpr data belongs inside the class or a namespace
  static constexpr std::array<std::string_view, 12> MONTH_NAMES = {
      "January", "February", "March",     "April",   "May",      "June",
      "July",    "August",   "September", "October", "November", "December"};

  static constexpr std::array<int, 12> DAYS_IN_MONTH = {31, 28, 31, 30, 31, 30,
                                                        31, 31, 30, 31, 30, 31};

  bool is_leap(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
  }

  int get_days_in_month(size_t month_idx) const {
    if (month_idx == 1 && is_leap(m_year))
      return 29;
    return DAYS_IN_MONTH[month_idx];
  }

  std::string generate_month(size_t month_idx, int &current_day_node) const {
    std::string m_buf;

    // Header
    std::format_to(std::back_inserter(m_buf), "{:^28}\n",
                   MONTH_NAMES[month_idx]);
    m_buf += " Sun Mon Tue Wed Thu Fri Sat\n";

    // Leading spaces
    for (int i = 0; i < current_day_node; ++i)
      m_buf += "    ";

    int days = get_days_in_month(month_idx);

    for (int date = 1; date <= days; ++date) {
      // Note: Removed ANSI colors for pure portability,
      // but you can inject them here if strict console output is desired.
      std::format_to(std::back_inserter(m_buf), "{:^4}", date);

      if (++current_day_node > 6) {
        current_day_node = 0;
        m_buf += "\n";
      }
    }
    if (current_day_node != 0)
      m_buf += "\n";
    m_buf += "\n"; // Spacing between months
    return m_buf;
  }
};

int main() {
  // Usage is now cleaner
  int year = 2024;
  int start_day = 1; // Monday

  CalendarYear cal(year, start_day);

  // We print the result of the logic
  std::print("{}", cal.to_string());

  return 0;
}
