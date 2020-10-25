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

int V, E;
vector<int> adj[3300];
bool visited[3300];
int deg[3300];

void dfs(int nd) {
	visited[nd] = 1;
	for (int nxt : adj[nd]) {
		if (visited[nxt]) continue;
		dfs(nxt);
	}
}

void solve(int tc) {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b; cin >> a >> b;
		deg[a]++;
		deg[b]++;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);
	for (int i = 1; i <= V; i++) if (!visited[i]) {
		cout << "NO\n";
		return;
	}

	int odd = 0, even = 0;
	for (int i = 1; i <= V; i++) {
		if (deg[i] % 2 == 0) even++;
		else odd++;
	}

	if (odd == 0 || odd == 2) cout << "YES\n";
	else cout << "NO\n";
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
