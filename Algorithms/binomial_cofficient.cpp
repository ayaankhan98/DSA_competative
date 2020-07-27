/**
 *
 * Calculating nCr or Binomial coefficients using Modulo Inverse
 *
 * nCr = N! / r! * (n - r)!
 *
 * using modulo inverse we can rewrite this formula as
 *
 * nCr = n! % p / r! % p * (n - r)! % p
 *
 */

#include <iostream>
#include <cassert>

#define P 1000000007

using namespace std;

int fact[1000001];

// calculating inverse using fermat's little theorem
int inverse(int a, int n) {
  int res = 1;
  while(n) {
    if (n % 2) {
      res = (res * 1LL * a) % P;
      n--;
    } else {
      a = (a * 1LL * a) % P;
      n /= 2;
    }
  }
  return res;
}

int C(int n, int r) {

  if (r > n) return 0;

  int res = fact[n];  // consider numerator n! % p

  // now we need to calculate the denominator but we cannot
  // simply divide res by r! and (n-r)! because we are working in
  // modulo system and in modulo system instead of division we multiply
  // by modulo inverse of required number
  

  // multiplying with 1LL to avoid integer overflow
  res = (res * 1LL * inverse(fact[r], P - 2)) % P;
  res = (res * 1LL * inverse(fact[n - r], P - 2)) % P;

  return res;
}

int main() {
  /// suppose we are given q queries and for each query we have to find
  /// nCr
  /// suppose range of n is upto 10^6, so we can pre calculate the factorial of
  /// numbers % p upto 10^6
  
  fact[0] = fact[1] = 1;
  for (int i = 2; i < 1000000; i++) 
    fact[i] = (fact[i-1] * i) % P;
  
  int q;
  cin >> q;
  int n, r;
  while(q--) {
    cin >> n >> r;
    cout << C(n,r) << endl;
  }
}
