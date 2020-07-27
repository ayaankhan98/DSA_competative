#include <iostream>
#include <cassert>

using namespace std;

/// calculates a ^ n % p
int modularExponent(int a, int n, int p) {
  /// at start initialilze result to 1
  int res = 1;
  while(n) { /// n is the power of a
    if (n % 2) { /// if n is odd
      
      /// if RHS is more than 9 after (mod p) then to avoid overflow
      /// we can use 
      /// (A * B) (mod P) = ((A mod P) * (B mod P)) (mod P)
      res = (res * a) % p; 
      n--;
    } else {
      a = (a * a) % p;
      n /= 2;
    }
  }
  return res;
}

int main() {
  cout << "Testing..." << endl;
  assert(modularExponent(8, 2, 10) == 4);
  assert(modularExponent(1378, 2, 10) == 4);
  cout << "Passed All Test cases... " << endl;
}
