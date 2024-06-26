#include<bits/extc++.h>

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

constexpr i64 mod = 998244353;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
	i64 n; std::cin >> n;
	vector<i64>a(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	vector<vector<i64>>dp(n + 5, vector<i64>(4, -inf));
	dp[0][1] = dp[0][0] = 0;
	for (i64 i = 1; i <= n; i++) {
		dp[i][0] = max(dp[i][0], dp[i - 1][0] + a[i]);
		dp[i][0] = max(dp[i][0], dp[i - 1][1] - a[i]);
		dp[i][1] = max(dp[i][1], dp[i - 1][0] - a[i]);
		dp[i][1] = max(dp[i][1], dp[i - 1][1] + a[i]);
	}
	std::cout  << max(dp[n][0], dp[n][1]) << "\n";
;
}
i64 T;
int main() {
	std::cin >> T;
	while (T--)solve();
}