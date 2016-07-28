#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

typedef std::unordered_map<int, std::string> IntToStringMap;
typedef std::pair<int, std::string> IntStringPair;

void print (IntToStringMap map) {
  std::cout << "print: map: " << &map << std::endl;
  for (const auto& pair : map) {
    std::cout << "pair.first: " << &pair.first << ": " << pair.first << std::endl;
    std::cout << "pair.second: " << &pair.second << ": " << pair.second << std::endl;
  }
  std::cout << std::endl;
}

void PopulateMap(const std::vector<IntStringPair>& in, IntToStringMap* map) {
  std::cout << "GenerateMap: in: " << &in << std::endl;
  std::cout << "GenerateMap: map: " << map << std::endl;
  for (const auto& pair : in) {
    std::cout << "GenerateMap: pair: " << &pair << std::endl;
    std::cout << "pair.first: " << &pair.first << ": " << pair.first << std::endl;
    std::cout << "pair.second: " << &pair.second << ": " << pair.second << std::endl;

    (*map)[pair.first] = pair.second;
  }
  std::cout << std::endl;
}

int main()
{
  IntToStringMap map;
  std::cout << "main: map: " << &map << std::endl;
  print(map);

  std::vector<IntStringPair> in;
  in.push_back(std::make_pair(6, "vector"));
  in.push_back(std::make_pair(3, "map"));
  std::cout << "main: in: " << &in << std::endl;
  PopulateMap(in, &map);
  std::cout << "main: map: " << &map << std::endl;
  print(map);

  map[3] = "set";
  map[5] = "array";
  map[4] = "hash";
  print(map);

  print(map);
}

