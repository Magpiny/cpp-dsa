#include <print>
#include <string>

using std::println;
using std::string;

struct Student {
  int AdmNo;
  std::string Sname;
  std::string grade;
  float height;
};

class StudentDetails {
public:
  StudentDetails() { // default constructor
    adm_no = my_adm + 1;
    stud_name = "John Doe";
    stud_class = "UNKNOWN";
    stud_height = 0.00;
  };

  // destructor
  virtual ~StudentDetails();

  StudentDetails(int reg_no, const string &sname, const string &sgrade,
                 float height = 0.0); // -> Constructor given member value;

  StudentDetails(const Student &stud) { // copy constructor
    adm_no = stud.AdmNo;
    stud_name = stud.Sname;
    stud_class = stud.grade;
    stud_height = stud.height;
  };

  // allow moving
  StudentDetails(const StudentDetails &&) noexcept = default;
  StudentDetails &operator=(const StudentDetails &&) noexcept = default;

  StudentDetails(const StudentDetails &) = delete; //-->Disable Copy constructor
  StudentDetails &operator=(const StudentDetails &) = delete;
  //-->Disable copy assignment

  void print();
  string getName() const;

private:
  int adm_no;
  string stud_name;
  string stud_class;
  float stud_height;
  static constexpr int my_adm = 4000;
};

int main() {
  Student f1 = {5078, "Jake Vibes", "Grade 12", 2.34f};

  StudentDetails s1; // default constructor
  StudentDetails s2(4092, "Jakom Okuome", "Grade 11");
  StudentDetails s3(f1);

  s1.print();
  s2.print();
  s3.print();

  println("S1 Name: {}", s1.getName());

  return 0;
}

// --> initializing a constructor using an initializer list
StudentDetails::StudentDetails(int adm, const string &sname,
                               const string &sgrade, float h)
    : adm_no(adm), stud_name(sname), stud_class(sgrade) {
  stud_height = h;
};

void StudentDetails::print() {
  println(" Adm No: {}\n Name: {}\n Class: {}\n Height: {}\n", adm_no,
          stud_name, stud_class, stud_height);
};

inline string StudentDetails::getName() const { return stud_name; };
