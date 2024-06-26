/*仍然需要用到拓扑排序*/
/*根据大小关系建立起来的拓扑图是不能存在环的,意味着矛盾*/
/*只能有一个最大值,这意味着入度为零的点唯一*/
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

vector<i64>tr[maxn];
queue<i64>q; i64 n, m, u, v;
void solve() {
	std::cin >> n >> m;
	vector<i64>d(n + 5, 0);
	std::vector<std::set<i64>>st(n + 5);
	vector<vector<i64>>tr(n + 5);
	for (i64 i = 1; i <= m; i++) {
		std::cin >> u >> v;
		tr[u].push_back(v);
		st[u].insert(v); d[v]++;
	}
	for (i64 i = 1; i <= n; i++) {
		if (not d[i]) {
			q.push(i);
		}
	}
	vector<i64>ans;
	while (not q.empty()) {
		i64 cur = q.front();
		q.pop();
		ans.push_back(cur);
		for (auto x : tr[cur]) {
			d[x]--;
			if (not d[x]) {
				q.push(x);
			}
		}
	}
	if (ans.size() != n) {
		puts("No"); return;
	}
	for (i64 i = 0; i < n - 1; i++) {
		if (not st[ans[i]].count(ans[i + 1])) {
			puts("No"); return;
		}
	}
	vector<i64>w(n + 5);
	for (i64 i = 0; i < n; i++) {
		w[ans[i]] = i + 1;
	}
	puts("Yes");
	for (i64 i = 1; i <= n; i++)std::cout  << w[i] << " ";
	std::cout  << "\n";
;
}
int main() {
	solve();
}