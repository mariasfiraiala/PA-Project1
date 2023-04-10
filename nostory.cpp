#include <bits/stdc++.h>

using namespace std;

uint_fast64_t SolveTask1(vector<uint_fast32_t>& a,
                         vector<uint_fast32_t>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<uint_fast32_t>());

    uint_fast64_t ans = 0;
    for (uint_fast32_t i = 0; i < a.size(); ++i)
        ans += max(a[i], b[i]);

    return ans;
}

uint_fast64_t SolveTask2(const vector<uint_fast32_t>& a,
                         const vector<uint_fast32_t>& b,
                         uint_fast32_t moves) {
    vector<uint_fast32_t> maxx(a.size());
    vector<uint_fast32_t> minn(a.size());

    for (uint_fast32_t i = 0; i < a.size(); ++i) {
        maxx[i] = max(a[i], b[i]);
        minn[i] = min(a[i], b[i]);
    }

    sort(maxx.begin(), maxx.end());
    sort(minn.begin(), minn.end(), greater<uint_fast32_t>());

    uint_fast64_t ans = 0;
    for (uint_fast32_t i = 0; i < a.size(); ++i) {
        if (moves && minn[i] > maxx[i]) {
            ans += minn[i];
            --moves;
        } else {
            ans += maxx[i];
        }
    }

    return ans;
}

vector<uint_fast32_t> ReadVector(istream& is, uint_fast32_t size) {
    vector<uint_fast32_t> vec(size);
    for (auto& num : vec) {
        is >> num;
    }
    return vec;
}

int main() {
    freopen("nostory.in", "r", stdin);
    freopen("nostory.out", "w", stdout);

    uint_fast32_t task;
    cin >> task;

    uint_fast32_t n, moves;
    if (task == 1) {
        cin >> n;
    } else {
        cin >> n >> moves;
    }

    auto a = ReadVector(cin, n);
    auto b = ReadVector(cin, n);

    auto res = task == 1 ? SolveTask1(a, b) : SolveTask2(a, b, moves);
    cout << res << "\n";

    return 0;
}
