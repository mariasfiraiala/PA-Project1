#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

void fibonacci(uint_fast64_t n, uint_fast64_t &x, uint_fast64_t &y) {
    if (n == 0) {
        x = 0;
        y = 1;
        return;
    }

    if (n & 1) {
        fibonacci(n - 1, y, x);
        y = (y + x) % MOD;
    } else {
        uint_fast64_t a, b;
        fibonacci(n >> 1, a, b);
        y = (a * a + b * b) % MOD;
        x = (a * b + a * (b - a + MOD)) % MOD;
    }
}

int main() {
    freopen("badgpt.in", "r", stdin);
    freopen("badgpt.out", "w", stdout);

    uint_fast8_t c;
    uint_fast64_t n;

    uint_fast64_t ans = 1;
    while (cin >> c >> n) {
        if (c == 'n' || c == 'u') {
            uint_fast64_t x = 0, y = 1;
            fibonacci(n + 1, x, y);
            ans = ((ans % MOD) * (x % MOD)) % MOD;
        }
    }

    cout << ans;

    return 0;
}
