// Example program
#include <iostream>
#include <string>

int main()
{
  std::string firstname, lastname;
  firstname = "Mahatma";
  lastname = "Gandhi";

  std::cout << "Hello, " << firstname << " " << lastname << "!\n";
  std::cout << lastname.length() << "!\n";

  lastname.push_back('\0');
  std::cout << "Hello, " << firstname << " " << lastname << "!\n";
  std::cout << lastname.length() << "!\n";
}

