#include <bits/stdc++.h>

using namespace std;

int task1(uint_fast32_t n, uint_fast32_t m, int x,
		  vector <int>& p, vector <vector <int> >& g) {
	vector<uint_fast32_t> sum_g(m);

	for (uint_fast32_t c = 0; c < m; ++c) {
		uint_fast32_t sum = 0;

		for (uint_fast32_t l = 0; l < n; ++l)
			sum += g[l][c];

		sum_g[c] = sum;
	}

	uint_fast32_t price_limit = x * n;
	vector< vector<int> > dp(m + 1, vector<int>(price_limit + 1, 0));

	for (int i = 1; i <= m; ++i) {
		for (int cap = 0; cap <= price_limit; ++cap) {
			dp[i][cap] = dp[i - 1][cap];

			if (cap - p[i - 1] >= 0) {
				int sol_aux = dp[i - 1][cap - p[i - 1]] + sum_g[i - 1];
				dp[i][cap] = max(dp[i][cap], sol_aux);
			}
		}
	}

	return dp[m][price_limit];
}

int task2(uint_fast32_t n, uint_fast32_t m, int x,
		  vector <int> &p, vector <vector <int> > &g) {
	vector<uint_fast32_t> sum_g(m);

	for (uint_fast32_t c = 0; c < m; ++c) {
		uint_fast32_t sum = 0;

		for (uint_fast32_t l = 0; l < n; ++l)
			sum += g[l][c];

		sum_g[c] = sum;
	}

	sum_g.insert(sum_g.end(), sum_g.begin(), sum_g.end());
	p.insert(p.end(), p.begin(), p.end());

	uint_fast32_t price_limit = x * n;
	vector< vector<int> > dp(2 * m + 1, vector<int>(price_limit + 1, 0));

	for (int i = 1; i <= 2 * m; ++i) {
		for (int cap = 0; cap <= price_limit; ++cap) {
			dp[i][cap] = dp[i - 1][cap];

			if (cap - p[i - 1] >= 0) {
				int sol_aux = dp[i - 1][cap - p[i - 1]] + sum_g[i - 1];

				dp[i][cap] = max(dp[i][cap], sol_aux);
			}
		}
	}

	return dp[2 * m][price_limit];
}

int task3(uint_fast32_t n, uint_fast32_t m, int x,
		  vector <int> &p, vector <vector <int> > &g) {
	vector<uint_fast32_t> sum_g(m);

	for (uint_fast32_t c = 0; c < m; ++c) {
		uint_fast32_t sum = 0;

		for (uint_fast32_t l = 0; l < n; ++l)
			sum += g[l][c];

		sum_g[c] = sum;
	}

	sum_g.insert(sum_g.end(), sum_g.begin(), sum_g.end());
	p.insert(p.end(), p.begin(), p.end());

	uint_fast32_t price_limit = x * n;
	vector< vector< vector<int> > > dp(2 * m + 1, vector< vector <int> >
									  (price_limit + 1, vector <int>(n + 1)));

	for (int i = 1; i <= 2 * m; ++i) {
		for (int cap = 0; cap <= price_limit; ++cap) {
			for (int j = 1; j <= n; ++j) {
				dp[i][cap][j] = dp[i - 1][cap][j];

				if (cap - p[i - 1] >= 0) {
					int sol_aux = dp[i - 1][cap - p[i - 1]][j - 1] + sum_g[i - 1];

					dp[i][cap][j] = max(dp[i][cap][j], sol_aux);
				}
			}
		}
	}

	return dp[2 * m][price_limit][n];
}

int main() {
	freopen("sushi.in", "r", stdin);
	freopen("sushi.out", "w", stdout);

	int task;  // task number

	uint_fast32_t n;  // number of friends
	uint_fast32_t m;  // number of sushi types
	int x;  // how much each of you is willing to spend

	vector <int> prices;  // prices of each sushi type
	// the grades you and your friends gave to each sushi type
	vector <vector <int> > grades;

	cin >> task;
	cin >> n >> m >> x;

	prices.assign(m, 0);
	grades.assign(n, vector <int> (m, 0));

	// price of each sushi
	for(int i = 0; i < m; ++i) {
		cin >> prices[i];
	}

	// each friends rankings of sushi types
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> grades[i][j];
		}
	}

	int ans = -1;

	switch(task) {
		case 1:
			ans = task1(n, m, x, prices, grades);
			break;
		case 2:
			ans = task2(n, m, x, prices, grades);
			break;
		case 3:
			ans = task3(n, m, x, prices, grades);
			break;
		default:
			cout << "wrong task number" << endl;
	}

	cout << ans << endl;

	return 0;
}
