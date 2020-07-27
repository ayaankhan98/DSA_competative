#include <iostream>
#include <cassert>

using namespace std;

/// calculates a ^ n
int binaryExponent(int a, int n) {
  /// at start initialilze result to 1
  int res = 1;
  while(n) { /// n is the power of a
    if (n % 2) { /// if n is odd
      res = (res * a); 
      n--;
    } else {
      a = (a * a);
      n /= 2;
    }
  }
  return res;
}

int main() {
  cout << "Testing..." << endl;
  assert(binaryExponent(8, 2) == 64);
  assert(binaryExponent(2, 3) == 8);
  cout << "Passed All Test cases... " << endl;
}
