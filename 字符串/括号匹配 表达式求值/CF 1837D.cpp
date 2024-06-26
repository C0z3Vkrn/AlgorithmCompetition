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
	string s; std::cin >> s; s = " " + s;
	bool f1 = 1, f2 = 1;
	i64 cnt1 = 0, cnt2 = 0;
	for (i64 i = 1; i <= n; i++) {
		if (s[i] == '(')cnt1++;
		else {
			if (cnt1) {
				cnt1--;
			} else {
				f1 = 0; break;
			}
		}
	}
	for (i64 i = 1; i <= n; i++) {
		if (s[i] == ')') {
			cnt2++;
		}
		else {
			if (cnt2) {
				cnt2--;
			} else {
				f2 = 0; break;
			}
		}
	}
	if ((cnt1 == 0 and f1) or (cnt2 == 0 and f2)) {
		std::cout  << 1 << "\n";
;
		for (i64 i = 1; i <= n; i++) {
			std::cout  << 1 << " ";
		}
		std::cout  << "\n";
; return;
	}
	vector<i64>co(n + 5, 0), stk1(n + 5, 0), stk2(n + 5, 0);
	i64 top1 = 0, top2 = 0;
	for (i64 i = 1; i <= n; i++) {
		if (s[i] == '(') {
			if (top2) {
				co[i] = co[stk2[top2]] = 2; top2--;
			} else
				stk1[++top1] = i;
		} else {
			if (top1) {
				co[i] = co[stk1[top1]] = 1; top1--;
			} else {
				stk2[++top2] = i;
			}
		}
	}
	for (i64 i = 1; i <= n; i++) {
		if (not co[i]) {
			puts("-1"); return;
		}
	}
	std::cout  << 2 << "\n";
;
	for (i64 i = 1; i <= n; i++) {
		std::cout  << co[i] << " \n"[i == n];
	}
}
int main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}