#include <iostream>
#include <string>
#include <vector>

enum JustAnotherEnum {
  ONE = 1,
  TWO = 2,
  FOUR = 4
};

void print (int an_int) {
  JustAnotherEnum an_enum = static_cast<JustAnotherEnum>(an_int);
  std::cout << "print: an_int: " << an_int << std::endl;
  std::cout << "print: an_enum: " << an_enum << std::endl;
}

int main()
{
  print(1);
  print(2);
  print(3);
  print(4);
  print(300);
}

