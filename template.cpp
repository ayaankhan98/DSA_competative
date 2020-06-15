/**
 *
 * @Filename : template.cpp
 * @Author : Ayaan Khan
 *
 * template file
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

#define gc getchar_unlocked
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 1e9
#define debug(x) cout<< #x << "=" << x <<endl
#define debug2(x,y) cout<< #x << "=" << x << ", " << #y << "=" << y << endl
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626

typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef vector<pii> vpii;

auto ONLINE = [] () {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
};

void solve() {
  // write your code here
}

int main() {
  FIO;
  ONLINE();
  int t;
  cin>>t;
  while(t--)
    solve();
  return 0;
}
