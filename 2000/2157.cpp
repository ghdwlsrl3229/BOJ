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

int N, M, K;
map<pll, ll> mp;
vector<pll> adj[330];

ll cache[330][330];
ll dp(int pos, int cnt) {
	if (pos == N) return 0;

	ll& ret = cache[pos][cnt];
	if (ret != -1) return ret;

	ret = 0;
	for (pll nxt : adj[pos]) {
		if (cnt < M - 1) ret = max(ret, dp(nxt.fr, cnt + 1) + nxt.sc);
		else ret = -1e18;
	}
	return ret;
}

void solve(int tc) {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		ll a, b, c; cin >> a >> b >> c;
		if (a > b) continue;
		mp[{a, b}] = max(mp[{a, b}], c);
	}
	for (auto p : mp) {
		adj[p.fr.fr].push_back({ p.fr.sc, p.sc });
	}

	memset(cache, -1, sizeof(cache));
	cout << dp(1, 0) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if (0) {
		int T; cin >> T;
		for (int i = 1; i <= T; i++) solve(i);
	}
	else {
		solve(0);
	}
	return 0;
}
