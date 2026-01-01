# C++ LIBRARIES

## C++ Libraries I've discovered a long the way

--1 mpunits [webpage]("https://mpusz.github.io/mp-units/latest")
### The quantities and units library for C++

mp-units is a modern C++ library for compile‑time dimensional analysis 
and unit/quantity manipulation. The earliest versions were inspired by 
std::chrono::duration, but with each release the interfaces intentionally 
diverged to provide a better user experience.

#### sample code (usage)

```cpp 
#include <mp-units/systems/international.h>
#include <mp-units/systems/isq.h>
#include <mp-units/systems/si.h>
#include <format>
#include <iomanip>
#include <iostream>
#include <print>

using namespace mp_units;

constexpr QuantityOf<isq::speed> auto avg_speed(QuantityOf<isq::length> auto d,
                                                QuantityOf<isq::time> auto t)
{
  return d / t;
}

int main()
{
  using namespace mp_units::si::unit_symbols;
  using namespace mp_units::international::unit_symbols;

  constexpr quantity v1 = 110 * km / h;
  constexpr quantity v2 = 70 * mph;
  constexpr quantity v3 = avg_speed(220. * isq::distance[km], 2 * h);
  constexpr quantity v4 = avg_speed(isq::distance(140. * mi), 2 * h);
  constexpr quantity v5 = v3.in(m / s);
  constexpr quantity v6 = value_cast<m / s>(v4);
  constexpr quantity v7 = value_cast<int>(v6);

  std::cout << v1 << '\n';                                        // 110 km/h
  std::cout << std::setw(10) << std::setfill('*') << v2 << '\n';  // ***70 mi/h
  std::cout << std::format("{:*^10}\n", v3);                      // *110 km/h*
  std::println("{:%N in %U of %D}", v4);                          // 70 in mi/h of LT⁻¹
  std::println("{::N[.2f]}", v5);                                 // 30.56 m/s
  std::println("{::N[.2f]U[dn]}", v6);                            // 31.29 m⋅s⁻¹
  std::println("{:%N}", v7);                                      // 31
}
```

--2 {fmt} A modern formating library  [format lib webpage]("https://fmt.dev/12.0")

{fmt} is an open-source formatting library providing a fast and safe 
alternative to C stdio and C++ iostreams.

```cpp 
#include "fmt/base.h"
#include <fmt/chrono.h>

int main() {
  auto now = std::chrono::system_clock::now();
  fmt::print("Date and time: {}\n", now);
  fmt::print("Time: {:%H:%M}\n", now);

  fmt::print("{}", std::vector{1, 2, 3});
}
```

