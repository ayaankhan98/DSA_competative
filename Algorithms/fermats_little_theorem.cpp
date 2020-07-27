/**
 *
 * used to calculate modulo multiplicative inverse
 * fermat's little theorem states that
 *
 * a ^ (m - 1) (congurent to) 1 under (mod m)
 *
 * conditions - 
 * 1. m and a are co primes
 * 2. m is a prime number
 * 3. a is any integer
 *
 * divide both side by a or multiply by a ^ -1 that is a inverse
 * we get,
 *
 * a ^ (m - 2) (congurent to) a ^ -1 under (mod m)
 *
 * so this tells us that in  order to calculate a ^ -1 under mod m we just
 * need to calculate a ^ m-2 and to calculate a ^ m -2 we can use fast
 * exponentiation or binary exponentiation to get a ^ n in log(n) time.
 */

#include <iostream>
#include <cassert>

using namespace std;

int b_expo(int a, int n, int p) {
  int res = 1;
  while(n) {
    if (n % 2) {
      res = (res * a) % p;
      n--;
    }
    else {
      a = (a * a) % p;
      n /= 2;
    }
  }
  return res;
}

int main() {
  int a, m;
  cin >> a >> m;
  cout << "a ^ -1 = " << b_expo(a, m-2, m) << endl;
  return 0;
}
