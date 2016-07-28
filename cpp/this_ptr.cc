#include <iostream>
#include <string>

class A {
 public:
  A(int i) : iptr_(&i_) {
    i_ = i;
  }
  std::string getHi() {
    return "Hi!";
  }

  int* getIptr() {
    return iptr_;
  }

 private:
  int i_;
  int* iptr_;

};

int main() {
  A* aptr = nullptr;
  std::cout << "aptr: " << aptr << std::endl;
  std::cout << "aptr::getHi: " << aptr->getHi() << std::endl;
  std::cout << "aptr::getIptr: " << aptr->getIptr() << std::endl;

  return 0;
}
