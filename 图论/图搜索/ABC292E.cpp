/*我们对每个源点跑bfs*/
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

i64 N, M, u, v;
vector<i64>tr[maxn];
void solve() {
	std::cin >> N >> M;
	for (i64 i = 1; i <= M; i++) {
		std::cin >> u >> v;
		tr[u].push_back(v);
	}
	i64 cnt = 0;
	vector<bool>vis(N + 5, false);
	function<void(i64)>dfs = [&](i64 u) {
		vis[u] = 1; cnt++;
		for (auto v : tr[u]) {
			if (vis[v])continue;
			dfs(v);
		}
	}; i64 ans = 0;
	for (i64 i = 1; i <= N; i++) {
		for (i64 i = 1; i <= N; i++) {
			vis[i] = 0;
		}
		cnt = 0;
		dfs(i); //std::cout  << cnt << "\n";
;
		ans += cnt - 1 - tr[i].size();
	}
	std::cout  << ans << "\n";
;
}
int main() {
	solve();
}