/**
 * @author ayaankhan98
 */
#include <bits/stdc++.h>

using namespace std;

#define INF ULLONG_MAX
#define FIO                                                                    \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define setz(x) memset(x, 0, sizeof(x))
#define seto(x) memset(x, 1, sizeof(x))
#define PI 3.1415926535897932384626

#define logs(a)                                                                \
  {                                                                            \
    cout << #a << " : [";                                                      \
    for (auto &x : a)                                                          \
      cout << x << ", ";                                                       \
    cout << "]\n";                                                             \
  }

#define loga(a)                                                                \
  {                                                                            \
    cout << #a << " :\n[\n";                                                   \
    for (auto x : a)                                                           \
      cout << "  " << x.first << " : " << x.second << "\n";                    \
    cout << "]\n";                                                             \
  }

#define debug(...) (debugPrint(#__VA_ARGS__ " : ", __VA_ARGS__))
template <typename... Args>
void debugPrint(const char *label, Args &&... args) {
  cout << "\n[";
  auto l = [](auto &&arg) {
    std::cout << std::forward<decltype(arg)>(arg) << ", ";
  };
  std::cout << label;
  (l(std::forward<Args>(args)), ...);
  cout << "\b\b]\n";
}

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
