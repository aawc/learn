//  Example program
#include <iostream>
#include <string>

int main() {
  std::string name =
      "1a4f692a639af6c62eaf73d06fd731eb771d43e32b93ce678b59f998d4da4f3c6fb0e8a5"
      "788d623618fe081e78d814322484611cf33763c4a0887b74cb64c85cba05";
  for (int i = 0; i < name.length(); i += 2) {
    if (i % 2 == 0) {
      std::cout << "\\x";
    }
    std::cout << name[i] << name[i + 1];
  }
  std::cout << std::endl;
  return 0;
}
