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

  lastname.push_back('G');
  std::cout << "Hello, " << firstname << " " << lastname << "!\n";
  std::cout << lastname.length() << "!\n";

  std::string::iterator iter = lastname.begin();
  std::string partial_lastname(iter+5, iter+8);
  std::cout << "Hello, " << partial_lastname << "!\n";

  return 0;
}

