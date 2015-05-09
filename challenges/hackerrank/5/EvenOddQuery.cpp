#include "EvenOddQuery.h"

int main() {
  unsigned n;
  cin >> n;
  if (n == 0) {
    return 0;
  }

  vector<unsigned> numbers;
  for(unsigned i = 0; i < n; i++) {
    unsigned number;
    cin >> number;
    numbers.push_back(number);
  }

  unsigned num_pairs;
  cin >> num_pairs;
  if (num_pairs == 0) {
    return 0;
  }

  typedef std::pair<unsigned, unsigned> pair;
  vector<pair> pairs;
  for(unsigned i = 0; i < num_pairs; i++) {
    unsigned x, y;
    cin >> x; cin >> y;
    pairs.push_back(make_pair(x, y));
  }
  for(unsigned i = 0; i < num_pairs; i++) {
    unsigned x = pairs[i].first;
    unsigned y = pairs[i].second;
#if DEBUG
    cout << x << ", " << y << ": ";
#endif
    bool number_is_odd = isOdd(find(numbers, x-1, y-1));
    cout << (number_is_odd ? "Odd" : "Even") << endl;
  }
  return 0;
}

unsigned find(
    vector<unsigned> numbers,
    unsigned x,
    unsigned y) {
#if DEBUG
  cout << "(" << x << ", " << y << "), ";
#endif
  if (x > y) {
#if DEBUG==2
    cout << "Returning 1 for x: " << x << ", y: " << y << " ";
#endif
    return 1;
  }

  unsigned base = numbers[x];
  unsigned exponent = ((y == x) || numbers[x+1]) ? 1 : 0;
  unsigned out = exponent ? base : 1;
#if DEBUG==2
  cout << "(" << x << ", " << y << "): pow(" << base <<
    ", " << exponent << ") = " << out << ", ";
#endif
  return out;
}

bool isOdd(unsigned x) {
  return x % 2;
}
