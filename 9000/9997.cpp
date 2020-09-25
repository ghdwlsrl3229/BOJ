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

int N;
int arr[26];
int ans = 0;

void dfs(int pos, int sum) {
	if (pos == N) {
		if (sum == (1 << 26) - 1) ans++;
		return;
	}

	dfs(pos + 1, sum);
	dfs(pos + 1, sum | arr[pos]);
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		int tmp = 0;
		for (int j = 0; j < s.size(); j++)
			tmp |= (1 << (s[j] - 'a'));
		arr[i] = tmp;
	}

	dfs(0, 0);
	cout << ans << '\n';
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
