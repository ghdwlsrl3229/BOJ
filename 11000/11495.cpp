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

const int MAX_V = 3000;
const int INF = 1e9;

int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V];
vector<int> adj[MAX_V];
int arr[55][55];
int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0, 0 };

int toInt(int y, int x) {
	return y + 50 * x;
}

int edmond_karp(int S, int E) {
	int total = 0;
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

		int flow = INF;
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

void solve() {
	int n, m; cin >> n >> m;

	int total = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j], total += arr[i][j];

	int S = 2500, E = 2501;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int cur = toInt(i, j);
			if ((i + j) % 2 == 0) {
				adj[S].push_back(cur);
				adj[cur].push_back(S);
				c[S][cur] = arr[i][j];
			}
			else {
				adj[E].push_back(cur);
				adj[cur].push_back(E);
				c[cur][E] = arr[i][j];
			}

			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				int nxt = toInt(ny, nx);
				adj[nxt].push_back(cur);
				adj[cur].push_back(nxt);
				if ((i + j) % 2 == 0) c[cur][nxt] = INF;
				else c[nxt][cur] = INF;
			}
		}

	int max_flow = edmond_karp(S, E);
	cout << total - max_flow << '\n';

	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	for (int i = 0; i < MAX_V; i++) adj[i].clear();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if (1) {
		int T; cin >> T;
		while (T--) solve();
	}
	else {
		solve();
	}
	return 0;
}
