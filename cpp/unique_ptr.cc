#include <iostream>
#include <memory>
#include <cstring>

void PrintInfo(std::string s) {
  std::cout << "-----------" << std::endl;
  int n = s.size();
  std::unique_ptr<char> cptr(new char[n]);
  strncpy(cptr.get(), s.c_str(), n);
  std::cout << "n: " << n << ": cptr.get(): " << cptr.get() << std::endl;
  std::cout << "sizeof(s): " << sizeof(s) << std::endl;
  std::cout << "s.capacity(): " << s.capacity() << std::endl;
  std::cout << "sizeof(cptr): " << sizeof(cptr) << std::endl;
  std::cout << "sizeof(cptr.get()): " << sizeof(cptr.get()) << std::endl;
  std::cout << "-----------" << std::endl;
}

int main()
{
  std::string s = "Hahasasdasdaqwertyuiopasdfghjklzx";
  PrintInfo(s);
  s.append("_");
  PrintInfo(s);
  s.erase();
  PrintInfo(s);
  s = "Hahasasdasdaqwertyuiopasdfghjklzx";
  PrintInfo(s);
}


