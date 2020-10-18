#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
#define ll long long
#define fr first
#define sc second
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()

int cache[40];

int dp(int n, int A) {
	if (n >= 31) return 0;
	int& ret = cache[n];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 1; i <= A; i++) {
		if (dp(n + i, A) == 0) ret = 1;
	}
	return ret;
}

void solve() {
	int A;  cin >> A;

	vector<int> ans;
	for (int i = 1; i <= A; i++) {
		memset(cache, -1, sizeof(cache));
		if (!dp(1, i)) ans.push_back(i);
	}

	for (int i : ans) cout << i << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if (0) {
		int T; cin >> T;
		while (T--) solve();
	}
	else {
		solve();
	}
	return 0;
}
