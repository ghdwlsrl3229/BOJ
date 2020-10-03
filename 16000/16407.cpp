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

const int MAX_V = 2200;
const int INF = 1000000000;

ll c[MAX_V][MAX_V]; 
ll f[MAX_V][MAX_V]; 
vector<int> adj[MAX_V]; 

void addEdge(int from, int to, int c1, int c2) {
	c[from][to] = c1;
	c[to][from] = c2;
	adj[from].push_back(to);
	adj[to].push_back(from);
}

ll max_flow(int S, int E) {
	ll total = 0;
	while (1) {
		int prev[MAX_V];
		fill(prev, prev + MAX_V, -1);
		queue<int> Q;
		Q.push(S);
		while (!Q.empty() && prev[E] == -1) {
			int curr = Q.front();
			Q.pop();
			for (int next : adj[curr]) {
				if (c[curr][next] - f[curr][next] > 0 && prev[next] == -1) {
					Q.push(next);
					prev[next] = curr;
					if (next == E) break;
				}
			}
		}
		if (prev[E] == -1) break;

		ll flow = INF;
		for (int i = E; i != S; i = prev[i])
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		for (int i = E; i != S; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		total += flow;
	}
	return total;
}

int N, M, C;
char arr[33][33];
int cost[30];
int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1 ,0 ,0 };

int toInt(int y, int x) {
	return y * M + x;
}

void solve() {
	cin >> M >> N >> C;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < C; i++) cin >> cost[i];

	int S = -1, E = 2000;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			int cur = toInt(i, j);
			if ('a' <= arr[i][j] && arr[i][j] <= 'z') addEdge(2 * cur, 2 * cur + 1, cost[arr[i][j] - 'a'], 0);
			else addEdge(2 * cur, 2 * cur + 1, INF, 0);

			if (arr[i][j] == 'B') S = 2 * cur + 1;
		}
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			int cur = toInt(i, j);
			bool out = 0;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
					out = 1;
					continue;
				}
				if (arr[ny][nx] == 'B') continue;

				int nxt = toInt(ny, nx);
				addEdge(2 * cur + 1, 2 * nxt, INF, 0);
			}
			if (out) addEdge(2 * cur + 1, E, INF, 0);
		}

	ll ans = max_flow(S, E);
	if (ans >= 1e9) cout << -1 << '\n';
	else cout << ans << '\n';
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
