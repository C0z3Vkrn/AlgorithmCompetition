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

class Solution {
public:
    int pre[100005];
    vector<i64>add, sum1, sum2;
    void init(int n) {
        add.resize(n * 4 + 5);
        sum1.resize(n * 4 + 5);
        sum2.resize(n * 4 + 5);
    }
    void pushup(int p) {
        sum1[p] = (sum1[p << 1] % mod + sum1[p << 1 | 1]) % mod;
        sum2[p] = (sum2[p << 1] % mod + sum2[p << 1 | 1]) % mod;
    }

    void build(int p, int l, int r) {
        sum1[p] = 0; sum2[p] = 0; add[p] = 0;
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid); build(p << 1 | 1, mid + 1, r);
        pushup(p);
    }
    void pushdown(int p, int l, int r) {
        int mid = (l + r) >> 1;
        int len1 = mid - l + 1;
        int len2 = r - mid;
        int v = add[p]; add[p] = 0;
        add[p << 1] += v; add[p << 1] %= mod;
        add[p << 1 | 1] += v; add[p << 1 | 1] %= mod;
        sum2[p << 1] = (sum2[p << 1] % mod + sum1[p << 1] % mod * 2 % mod * v % mod + v % mod * v % mod * len1 % mod) % mod;
        sum1[p << 1] = (sum1[p << 1] % mod + v % mod * len1 % mod) % mod;
        sum2[p << 1 | 1] = (sum2[p << 1 | 1] % mod + sum1[p << 1 | 1] % mod * 2 % mod * v % mod + v % mod * v % mod * len2 % mod) % mod;
        sum1[p << 1 | 1] = (sum1[p << 1 | 1] % mod + v % mod * len2 % mod) % mod;
    }
    void modify(int p, int L, int R, int l, int r, int v) {
        if (L >= l and R <= r) {
            add[p] = (add[p] % mod + v) % mod;
            sum2[p] = (sum2[p] % mod + sum1[p] % mod * 2 % mod * v % mod + v % mod * v % mod * (R - L + 1) % mod) % mod;
            sum1[p] = (sum1[p] % mod + v % mod * (R - L + 1) % mod) % mod;
            return;
        }
        pushdown(p, L , R);
        int mid = (L + R) >> 1;
        if (l <= mid)modify(p << 1, L, mid, l, r, v);
        if (r > mid)modify(p << 1 | 1, mid + 1, R, l, r, v);
        pushup(p);
    }
    i64 query(int p, int L, int R, int l, int r) {
        if (L >= l and R <= r) {
            return sum2[p] % mod;
        }
        pushdown(p, L, R);
        i64 ret = 0;
        int mid = (L + R) >> 1;
        if (l <= mid)ret = (ret % mod + query(p << 1, L, mid, l, r)) % mod;
        if (r > mid)ret = (ret % mod + query(p << 1 | 1, mid + 1, R, l, r)) % mod;
        return ret % mod;
    }
    int sumCounts(vector<int>& nums) {
        int n = nums.size(); init(n);
        std::fill(pre + 1, pre + 1 + 100000, 0);
        build(1, 1, n); i64 res = 0;
        for (int i = 1; i <= n; i++) {
            int cur = nums[i - 1];
            int p = pre[cur];
            modify(1, 1, n, p + 1, i, 1);
            pre[cur] = i;
            res = (res % mod + sum2[1]) % mod;
        }
        return res % mod;
    }
};