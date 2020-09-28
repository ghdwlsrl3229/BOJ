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
const int INF = 1e9;

int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V];
vector<int> adj[MAX_V];

void addEdge(int u, int v, int w) {
	adj[u].push_back(v);
	adj[v].push_back(u);
	c[u][v] = w;
}

void solve() {
	int N, M, K; cin >> N >> M >> K;
	int S = N + M + 1, E = N + M + 2, B = N + M;
	
	addEdge(S, B, K);
	for (int i = 0; i < N; i++) {
		addEdge(S, i, 1); //직원과 소스 연결
		addEdge(B, i, 1); //브릿지와 직원 연결
	}

	//직원과 일 연결
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		while (a--) {
			int b; cin >> b;
			b = b + N - 1;
			addEdge(i, b, INF);
		}
	}

	//일과 싱크 연결
	for (int i = N; i < N + M; i++) addEdge(i, E, 1);

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
	cout << total << '\n';
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
