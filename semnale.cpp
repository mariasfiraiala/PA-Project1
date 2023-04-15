#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int type1(uint_fast32_t x, uint_fast32_t y) {
    vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));

	for (uint_fast32_t l = 0; l <= x; ++l)
		dp[l][0] = 1;

	dp[0][1] = 1;
	for (uint_fast32_t i = 1; i <= x; ++i)
		for (uint_fast32_t j = 1; j <= y; ++j)
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;

    return dp[x][y];
}

int type2(uint_fast32_t x, uint_fast32_t y) {
    vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));

	for (uint_fast32_t l = 0; l <= x; ++l) {
		dp[l][0] = 1;
		dp[l][1] = l + 1;
	}

	dp[0][1] = dp[0][2] = 1;

	for (uint_fast32_t i = 1; i <= x; ++i)
		for (uint_fast32_t j = 2; j <= y; ++j)
			dp[i][j] = ((dp[i - 1][j] + dp[i - 1][j - 1]) % MOD +
				dp[i - 1][j - 2]) % MOD;

    return dp[x][y];
}

int main() {
    freopen("semnale.in", "r", stdin);
	freopen("semnale.out", "w", stdout);

	uint_fast32_t sig_type, x, y;

	cin >> sig_type >> x >> y;

    switch (sig_type) {
		case 1:
			cout << type1(x, y);;
			break;
		case 2:
			cout << type2(x, y);
			break;
		default:
			cout << "wrong task number" << "\n";
	}

    return 0;
}
