#include<bits/stdc++.h>
using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed long long;
using u64 = unsigned long long;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = long double;
using namespace std;
const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
/*枚举边dp*/
void solve() {
  i64 n, m, T; std::cin >> n >> m >> T;
  vector dp(n + 1, vector<i64>(n + 1, inf));
  auto pre = dp;
  dp[0][1] = 0;
  vector<array<i64, 3>>e(m + 1);
  for (i64 i = 1; i <= m; i++) {
    std::cin >> e[i][0] >> e[i][1] >> e[i][2];
  }
  i64 ans = 0;
  for (i64 i = 1; i < n; i++) {
    for (i64 j = 1; j <= m; j++) {
      auto [u, v, w] = e[j];
      i64 cur = dp[i - 1][u] + w;
      if (cur < dp[i][v]) {
        dp[i][v] = cur;
        pre[i][v] = u;
      }
    }
    if (dp[i][n] <= T) {
      ans = i;
    }
  }
  std::cout  << ans + 1 << "\n";;
  i64 s = n;
  vector<i64>p;
  for (i64 i = ans; i >= 0; i--) {
    p.push_back(s);
    s = pre[i][s];
  }
  reverse(p.begin(), p.end());
  for (i64 i = 0; i < p.size(); i++) {
    std::cout  << p[i] << " \n"[i == p.size() - 1];
  }

}
int main() {
  solve();
}





#include<bits/stdc++.h>
using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed long long;
using u64 = unsigned long long;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = long double;
using namespace std;
const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
/*枚举边dp*/
void solve() {
  i64 n, m, T; std::cin >> n >> m >> T;
  vector dp(n + 1, vector<i64>(n + 1, inf));
  auto pre = dp;
  dp[0][1] = 0;
  vector<array<i64, 3>>e(m + 1);
  std::vector<vector<pair<i64, i64>>>g(n + 1);
  for (i64 i = 1; i <= m; i++) {
    std::cin >> e[i][0] >> e[i][1] >> e[i][2];
    g[e[i][1]].push_back({e[i][0], e[i][2]});
  }
  i64 ans = 0;
  /*O(n  * (n + m))*/
  for (i64 i = 1; i < n; i++) {
    for (i64 j = 1; j <= n; j++) {
      for (auto [v, w] : g[j]) {
        if (dp[i - 1][v] + w < dp[i][j]) {
          dp[i][j] = dp[i - 1][v] + w;
          pre[i][j] = v;
        }
      }
    }
    if (dp[i][n] <= T) {
      ans = i;
    }
  }
  std::cout  << ans + 1 << "\n";;
  i64 s = n;
  vector<i64>p;
  for (i64 i = ans; i >= 0; i--) {
    p.push_back(s);
    s = pre[i][s];
  }
  reverse(p.begin(), p.end());
  for (i64 i = 0; i < p.size(); i++) {
    std::cout  << p[i] << " \n"[i == p.size() - 1];
  }

}
int main() {
  solve();
}