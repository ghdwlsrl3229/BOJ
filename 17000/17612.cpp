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

int N, K;

void solve() {
	cin >> N >> K;
	priority_queue<pll> pq;
	priority_queue<tuple<ll, ll, ll>> pq2;
	for (int i = 1; i <= K; i++) pq.push({ 0, -i });
	for (int i = 0; i < N; i++) {
		int id, w; cin >> id >> w;
		pll p = pq.top();
		pq.pop();

		pq.push({ p.fr - w, p.sc });
		pq2.push({ p.fr - w, -p.sc, id });
	}
	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += i * get<2>(pq2.top());
		pq2.pop();
	}
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
