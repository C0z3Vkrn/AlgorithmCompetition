/*300兆字节 1- 2 秒*/

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

int main() {
	std::cin.tie(0);
	ios::sync_with_stdio(0);
	int T;
	std::cin >> T;
	while (T--) {
		i64 a, b;
		std::cin >> a >> b;
		if (a > b) swap(a, b);
		if (a == 1 && a == b) {
			std::cout  << "niumei" << "\n";
;
			continue;
		}
		if (a == b && a > 2) {
			a -= 2;
			b -= 1;
			if (a % 3 == 1 || a % 3 == 2) {
				std::cout  << "niumei" << "\n";
;

			}
			else {
				std::cout  << "niuniu" << "\n";
;
			}
			continue;
		}
		if (a % 3 == 1 || a % 3 == 2) {
			std::cout  << "niuniu" << "\n";
;

		}
		else {
			std::cout  << "niumei" << "\n";
;
		}

	}
	return 0;
}

