/* Write a C++ program that has a Polygon interface that has abstract
 * functions, area(), and perimeter(). Implement classes for Triangle,
 * Quadrilateral, Pentagon, Hexagon, and Octagon, which implement this
 * interface, with the obvious meanings for the area() and perimeter()
 * functions. Also implement classes, IsoscelesTriangle, EquilateralTriangle,
 * Rectangle, and Square, which have the appropriate inheritance relationships.
 * Finally, write a simple user interface that allows users to create polygons
 * of the various types, input their geometric dimensions, and then output their
 * area and perimeter. For extra effort, allow users to input polygons by
 * specifying their vertex coordinates and be able to test if two such polygons
 * are similar.
 */

#include <cmath>
#include <format>
#include <iostream>
#include <numbers>
#include <print>
#include <stdexcept>
#include <vector>

class Polygon {
protected:
  struct Point {
    double x;
    double y;
  };

public:
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  virtual const std::string get_name() const = 0;
  virtual double get_distance(const Point &p1, const Point &p2) const {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
  }

  virtual ~Polygon() noexcept = default;
};

class Triangle : public Polygon {
protected:
  std::vector<double> sides;   /// > A triangle has 3 sides
  std::vector<Point> vertices; /// > A triangle has 3 vertices
  bool is_avecofvectors;

public:
  Triangle(std::vector<double> s = {0.0, 0.0, 0.0})
      : sides(s), is_avecofvectors(false) {
    if (s.size() < 3) {
      throw std::invalid_argument("Expected 3 arguments");
    }
  };

  Triangle(const std::vector<Point> &verts = std::vector<Point>(3, {0.0, 0.0}))
      : vertices(verts), is_avecofvectors(true) {
    if (verts.size() < 3) {
      throw std::invalid_argument("Expected 3 vectors of doubles");
    }
  };

  double area() const override {
    if (is_avecofvectors) {
      double area = 0.0;

      for (size_t i = 0; i < vertices.size(); ++i) {
        size_t j = (i + 1) % vertices.size();
        area += vertices[i].x * vertices[j].y;
        area -= vertices.at(j).y * vertices.at(i).x;
      }
      return std::abs(area) / 2.0;
    } else {
      double p = (sides[0] + sides[1] + sides[2]) / 2;
      double area =
          std::sqrt(p * (p - sides[0]) * (p - sides[1]) * (p - sides[2]));
      return area;
    }
  };

  double perimeter() const override {
    if (!is_avecofvectors) {
      return sides[0] + sides[1] + sides[2];
    } else {
      if (vertices.size() < 2)
        return 0.0;

      double perimeter = 0.0f;
      size_t n = vertices.size();

      for (size_t i = 0; i < n; ++i) {
        size_t j = (i + 1) % n;
        Point current = vertices[i];
        Point next = vertices[j];
        perimeter += get_distance(next, current);
      }
      return perimeter;
    }
  };

  const std::string get_name() const override {
    return std::format("This is a Triangle");
  }
};

class Quadrilateral : public Polygon {
protected:
  double length;             /// > length of each side of the quadrilateral
  int num_of_sides;          /// > number of sides of the quadrilateral
  bool is_vec;               /// > Check if the ctor has a vector of coordinates
  std::vector<Point> coords; /// > Coordinates of a vertex

public:
  Quadrilateral(double l = 0.0, int sides = 0)
      : length(l), num_of_sides(sides), is_vec(false) {
    if (l < 0.0)
      throw std::invalid_argument(
          "Invalid Lenth Error: length must be a positve value > 0!");
    if (sides < 3)
      throw std::invalid_argument(
          "Polygon Error: A polygon must have 3 or more sides");
  };
  Quadrilateral(const std::vector<Point> &verts) : is_vec(true), coords(verts) {
    if (verts.size() < 3)
      throw std::invalid_argument(
          "Polygon Error: A polygon MUST have 3 or more vertices!");
  };

  double area() const override {
    if (is_vec) {
      double sumup = 0.0;
      double sumdwn = 0.0;
      size_t n = coords.size();

      for (size_t i = 0; i < n; ++i) {
        int j = (i + 1) % n;

        sumup += coords[i].x * coords[j].y;
        sumdwn += coords[i].y * coords[j].x;
      }

      return std::abs(sumup - sumdwn) / 2.0;
    } else {
      return (num_of_sides * std::pow(length, 2)) /
             (4.0 * std::tan(std::numbers::pi / num_of_sides));
    }
  }
  double perimeter() const override {
    if (is_vec) {
      double perimeter = 0.0;
      size_t vertices = coords.size();

      for (size_t i = 0; i < vertices; ++i) {
        perimeter += get_distance(coords[i], coords[(i + 1) % vertices]);
      }
      return perimeter;
    } else {
      return num_of_sides * length;
    }
  }
  const std::string get_name() const override {
    return std::format("This is a quadrilateral");
  }
};

class Pentagon : public Quadrilateral {
public:
  Pentagon(double l) : Quadrilateral(l, 5) {};
  Pentagon(const std::vector<Point> &points) : Quadrilateral(points) {};

  const std::string get_name() const override {
    return std::format("Shape: Pentagon");
  }
};

class Octagon : public Quadrilateral {
  Octagon(double len) : Quadrilateral(len, 8) {};
  Octagon(const std::vector<Point> &pts) : Quadrilateral(pts) {};

  const std::string get_name() const override {
    return std::format("Shape: Pentagon");
  }
};

class Hexagon : public Quadrilateral {
public:
  Hexagon(double len) : Quadrilateral(len, 6) {};
  Hexagon(const std::vector<Point> &pts) : Quadrilateral(pts) {
    if (pts.size() < 6)
      throw std::invalid_argument(
          std::format("Hexagon Error: Must provide 6 coordinates of the "
                      "hexagon!\n {} provided",
                      pts.size()));
  };

  const std::string get_name() const override {
    return std::format("Shape: Hexagon");
  }
};

class IsoscelesTriangle : public Triangle {
public:
  IsoscelesTriangle(std::vector<double> p) : Triangle(p) {};
  IsoscelesTriangle(const std::vector<Point> &pts) : Triangle(pts) {};

  const std::string get_name() const override {
    return std::format("Shape: Isosceles Triangle");
  }
};

class EquilateralTriangle : public Triangle {
public:
  EquilateralTriangle(std::vector<double> p) : Triangle(p) {};
  EquilateralTriangle(const std::vector<Point> &pts) : Triangle(pts) {};

  const std::string get_name() const override {
    return std::format("Shape: Equilateral Triangle");
  }
};

int main() {
  try {
    Pentagon p({{0.0, 0.0}, {4.0, 0.0}, {4.0, 4.0}, {2.0, 6.0}, {0.0, 4.0}});
    Pentagon pp(4.5);
    EquilateralTriangle eqtr({4.0, 5.0, 6.0});

    std::println("Area of Pentagon1 is {}cm2 {}", p.area(), p.get_name());
    std::println("Area of Pentagon2 is {:.4f}cm2", pp.area());

    std::println("Perimeter of Pentagon1 is {:.4f}cm2", p.perimeter());
    std::println("Perimeter of Pentagon2 is {:.4f}cm2", pp.perimeter());

    std::println();
    std::println("Perimeter is {:.4f} {}", eqtr.perimeter(), eqtr.get_name());
  } catch (const std::exception &err) {
    std::cerr << err.what() << "\n";
  }

  return 0;
};
