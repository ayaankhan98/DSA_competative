/**
 *
 * Euler's Toitent Function in O(Sqrt(N))
 *
 * Euler's Totitent function is used to count the number of positive coprimes
 * upto n which are coprimes with n
 *
 * represented by Phi(n) = number of positive integers which are coprime with n
 *
 * example Phi(5) = 4
 *
 * the function Phi(N) is given by
 *
 * Phi(N) = N * [ (P1 - 1) / P1 ] * [ (P2 - 1) / P2 ] * [ (P3 - 1) / P3 ] .....
 *
 * where P1, P2, P3,.... are the Prime divisors of N.
 *
 */

#include <iostream>
#include <cassert>

using namespace std;

int phi(int n) {
  int res = n;
  for (int i = 2; i * i <= n; i++) {
    /// this will be true when i is a prime divisor of n
    if (n % i == 0) {
      res /= i; // divide result by prime factor
      res *= (i - 1); // multiply result by prime factor - 1
      while(n % i == 0)
        n /= i;
    }
  }
  if (n > 1)
    res /= n, res *= n-1;
  return res;
}

int main() {
  cout << "Testing...\n";
  assert(phi(50) == 20);
  assert(phi(200) == 80);
  assert(phi(500) == 200);
  assert(phi(61) == 60);
  assert(phi(120) == 32);
  cout << "All test passed\n";
  int n;
  cin >> n;
  cout << phi(n) << endl;
  return 0;
}
