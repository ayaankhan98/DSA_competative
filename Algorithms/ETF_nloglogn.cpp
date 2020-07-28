/**
 *
 * An optimized approach to calculate Phi(N) using sieve in
 * O(nlog(log(n))
 *
 */

#include <iostream>
#include <cassert>

using namespace std;

// taking a phi array and initialize the ith index with i
int phi[1000001];

void init(int maxN) {
  // initializing the phi array
  // phi [] =  index : 1        2       3       4       5       6       7       8   ...
  //           value : 1        2       3       4       5       6       7       8   ...
  
  for(int i = 1; i <= maxN; i++)
    phi[i] = i;

  for(int i = 2; i <= maxN; i++) {
    // if number is prime.
    if (phi[i] == i) {

      // number is prime then for all it's multiple divide each multiple by
      // prime i and multiply it by (i - 1)
      for(int j = i; j <= maxN; j += i) {
        phi[j] /= i;
        phi[j] *= (i - 1);
      }
    }
  }
}

int main() {
  init(1000000);
  cout << "Testing..." << endl;
  assert(phi[200] == 80);
  assert(phi[5] == 4);
  assert(phi[500] = 200);
  assert(phi[120] == 32);
  cout << "Passed all test cases" << endl;

  int n;
  cin >> n;
  cout << phi[n] << endl;
}
