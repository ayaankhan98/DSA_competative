/**
 * @author ayaankhan98
 */
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <valarray>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <array>
#include <climits>
#include <limits>
#include <memory>
#include <bit>
#include <sstream>

using namespace std;

#define gc getchar_unlocked
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF ULLONG_MAX
#define dbg(x) cout << #x << "=" << x << endl
#define dbg2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define FIO                                                                    \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define setz(x) memset(x, 0, sizeof(x))
#define seto(x) memset(x, 1, sizeof(x))
#define PI 3.1415926535897932384626

typedef int64_t ll;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef vector<pii> vpii;
typedef vector<pair<ll, ll>> vpll;
typedef set<int> si;

auto ONLINE = []() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
};

void solve() {
  /// write your code here
}

int main() {
  FIO;
  ONLINE();
  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
