// Example program
#include <iostream>

int main()
{
  size_t a = 3, b = 3;
  if (a > 5) a = 5;
  std::cout << "Hello, 2%0: " << 2%(a - b) << "!\n";

  return 0;
}

