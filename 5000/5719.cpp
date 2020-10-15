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

int N, M;
int S, D;
int adj[550][550];
vector<int> prv[550];
vector<ll> dist;

const ll INF = 1e18;
vector<ll> Dijkstra() {
	vector<ll> dist(N, INF);
	dist[S] = 0;
	queue<pll> q;
	q.push({ 0, S });
	while (q.size()) {
		auto p = q.front(); q.pop();
		int cur = p.second;
		ll d = p.first;
		if (d > dist[cur]) continue;
		for (int j = 0; j < N; j++) {
			if (adj[cur][j] == -1) continue;
			ll d2 = d + adj[cur][j];
			if (d2 < dist[j]) {
				dist[j] = d2;
				q.push({ d2, j });
			}
		}
	}
	return dist;
}

void bfs(int nd) {
	queue<int> q;
	q.push(nd);

	while (q.size()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < N; i++) {
			if (adj[i][cur] != -1 && dist[cur] - dist[i] == adj[i][cur]) {
				q.push(i);
				adj[i][cur] = -1;
			}
		}
	}
}

void solve(int tc) {
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) return;
		cin >> S >> D;

		memset(adj, -1, sizeof(adj));
		for (int i = 0; i < M; i++) {
			int a, b, c; cin >> a >> b >> c;
			adj[a][b] = c;
		}
		dist = Dijkstra();
		bfs(D);
		dist = Dijkstra();

		if (dist[D] == INF) cout << -1 << '\n';
		else cout << dist[D] << '\n';

		dist.clear();
		for (int i = 0; i < N; i++) prv[i].clear();
	}
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
