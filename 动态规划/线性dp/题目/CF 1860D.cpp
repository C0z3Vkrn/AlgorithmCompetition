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
	string s; std::cin >> s; i64 n = s.size(); s = " " + s;
	vector dp(n + 5, vector(n + 5, vector<i64>(6000, inf)));
	dp[0][0][3000] = 0;
	i64 cnt = 0; for (i64 i = 1; i <= n; i++)if (s[i] == '1')cnt++;
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 0; j <= cnt; j++) {
			for (i64 z = 500; z <= 5500; z++) {
				if (s[i] == '1') {
					i64 p = i - j;//第i位置是否转换
					if (j >= 1)
						dp[i][j][z] = min(dp[i][j][z], dp[i - 1][j - 1][z + p]);
					dp[i][j][z] = min(dp[i][j][z], dp[i - 1][j][z - j] + 1);
				} else {
					dp[i][j][z] = min(dp[i][j][z], dp[i - 1][j][z - j]);
					if (j >= 1) {
						i64 p = i - j;
						dp[i][j][z] = min(dp[i][j][z], dp[i - 1][j - 1][z + p] + 1);
					}
				}
			}
		}
	}
	std::cout  << dp[n][cnt][3000] / 2 << "\n";
;
}
int main() {

	solve();
}