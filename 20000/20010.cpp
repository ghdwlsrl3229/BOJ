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

int pa[1100];
int find(int n) {
	if (pa[n] < 0) return n;
	return pa[n] = find(pa[n]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	pa[b] += pa[a];
	pa[a] = b;
}

vector<tuple<int, int ,int>> edges;
vector<pll> adj[1100];

ll mx = 0;
bool visited[1100];
void dfs(int nd, ll sum) {
	visited[nd] = 1;
	mx = max(mx, sum);
	for (auto nxt : adj[nd]) {
		if (visited[nxt.fr]) continue;
		dfs(nxt.fr, sum + nxt.sc);
	}
}

void solve() {
	int n, k; cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b, c; cin >> a >> b >> c;
		edges.push_back({ c, a, b });
	}
	sort(all(edges));

	ll sum = 0;
	memset(pa, -1, sizeof(pa));
	for (int i = 0; i < k; i++) {
		int u, v, w;
		tie(w, u, v) = edges[i];
		if (find(u) == find(v)) continue;
		merge(u, v);
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
		sum += w;
	}
	for (int i = 0; i < n; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i, 0);
	}
	cout << sum << '\n';
	cout << mx << '\n';
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
