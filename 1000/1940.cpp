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

int cnt[110000];

void solve() {
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		cnt[a]++;
	}
	int ans = 0;
	for (int i = 1; i <= 100000; i++) {
		int j = M - i;
		if (j <= 0 || j > 100000) continue;
		if (i != j) ans += min(cnt[i], cnt[j]);
		else ans += cnt[i] / 2;

		cnt[i] = cnt[j] = 0;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if ( 0) {
		int T; cin >> T;
		while (T--) solve();
	}
	else {
		solve();
	}
	return 0;
}
