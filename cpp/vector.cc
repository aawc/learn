#include <iostream>
#include <string>
#include <vector>

void print (std::vector<std::string> list) {
    std::cout << "print: list: " << &list << std::endl;
    for (const auto& e : list) {
        std::cout << "e: " << e << std::endl;
    }
}

int main()
{
    std::vector<std::string> list;
    std::cout << "main: list: " << &list << std::endl;
    print(list);

    list.push_back("A");
    list.push_back("B");
    list.push_back("D");
    list.push_back("C");
    print(list);
}

