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
	i64 n, m; std::cin >> n >> m;
	vector<i64>A(n + 5, 0);
	vector<i64>pos(m + 5, 0);
	for (i64 i = 1; i <= n; i++)std::cin >> A[i];
	vector<i64>tr(m + 5);
	auto add = [&](i64 idx, i64 v) {
		for (; idx <= m; idx += (idx & -idx)) {
			tr[idx] = max(tr[idx], v);
		}
	};
	auto query = [&](i64 idx) {
		i64 ret = 0;
		for (; idx >= 1; idx -= (idx & -idx)) {
			ret = max(ret, tr[idx]);
		}
		return ret;
	};
	for (i64 i = 1; i <= n; i++) {
		if (A[i] <= m) {
			i64 l = i;
			while (A[i + 1] <= m and A[i + 1] - A[i] == 1 and i + 1 <= n)i++;
			add(A[l], A[i]);
		}
	}
	for (i64 i = 1; i <= m; i++) {
		if (pos[i] == -1) {
			puts("-1"); return;
		}
	}
	i64 p = 1, ans = 0;
	while (p <= m) {
		i64 nxt = query(p);
		ans++;
		p = nxt + 1;
	}
	std::cout  << ans << "\n";
;
}
int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout .tie(0);
	i64 T; std::cin >> T;
	while (T--)
		solve();
}