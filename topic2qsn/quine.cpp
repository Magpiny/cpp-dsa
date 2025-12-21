// Quinine: A program that outputs its own code

#include <iostream>

#include <string>

int main() {
  std::string s = R"quine(
        #include <iostream>
        #include <string>

        int main(){
        std::string s = R"quine()";
        std::cout << s.substr(0, 108) << s << s.substr(108) << std::endl;
        return 0;
    })quine";

  std::cout << s.substr(0, 108) << s << s.substr(108) << std::endl;
  return 0;
}
