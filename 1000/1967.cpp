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
vector<pll> adj[11000];

void dfs(int nd, int & _nd, int & _len, int prv = -1, int len = 0) {
	if (_len < len) {
		_len = len;
		_nd = nd;
	}

	for (auto nxt : adj[nd]) {
		if (nxt.fr == prv) continue;
		dfs(nxt.fr, _nd, _len, nd, len + nxt.sc);
	}
}

void solve(int tc) {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	int v1 = 1, len1 = 0;
	dfs(1, v1, len1);
	int v2 = v1, len2 = 0;
	dfs(v1, v2, len2);

	cout << len2 << "\n";
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
