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

const int MAX_V = 110 * 110 * 2;
const int INF = 1e9;

// 간선 구조체
struct Edge {
	int to, c, f;
	Edge *dual; // 자신의 역방향 간선을 가리키는 포인터
	Edge() : Edge(-1, 0) {}
	Edge(int to1, int c1) : to(to1), c(c1), f(0), dual(nullptr) {}
	int spare() {
		return c - f;
	}
	void addFlow(int f1) { // 자신과 역방향 간선에 f1만큼의 플로우 값을 갱신
		f += f1;
		dual->f -= f1;
	}
};

vector<Edge*> adj[MAX_V];

void addEdge(int u, int v, int w) {
	Edge* e1 = new Edge(v, w), *e2 = new Edge(u, 0);
	e1->dual = e2;
	e2->dual = e1;
	adj[u].push_back(e1);
	adj[v].push_back(e2);
}

int N, M;
char arr[110][110];
int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0, 0 };

void solve() {
	cin >> N >> M;
	int S, E;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'K') S = (i * M + j) * 2 + 1;
			if (arr[i][j] == 'H') E = (i * M + j) * 2;
		}
	}
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			int u = i * M + j;
			addEdge(u * 2, u * 2 + 1, 1);
			for (int t = 0; t < 4; t++) {
				int k = i + dy[t];
				int s = j + dx[t];
				if (k < 0 || s < 0 || k >= N || s >= M) continue;
				if (arr[i][j] == 'K' && arr[k][s] == 'H') {
					cout << -1 << '\n';
					return;
				}
				if (arr[i][j] != '#' && arr[k][s] != '#') {
					int v = k * M + s;
					addEdge(u * 2 + 1, v * 2, 1);
				}
			}
		}

	int total = 0;
	while (1) {
		int prev[MAX_V];
		Edge *path[MAX_V] = { 0 }; // 경로상의 간선들을 저장해두어 나중에 참조
		fill(prev, prev + MAX_V, -1);
		queue<int> Q;
		Q.push(S);
		while (!Q.empty() && prev[E] == -1) {
			int curr = Q.front();
			Q.pop();
			for (Edge *e : adj[curr]) {
				int next = e->to;
				if (e->spare() > 0 && prev[next] == -1) {
					Q.push(next);
					prev[next] = curr;
					path[next] = e;
					if (next == E) break;
				}
			}
		}
		if (prev[E] == -1) break;

		int flow = INF;
		for (int i = E; i != S; i = prev[i])
			flow = min(flow, path[i]->spare());
		for (int i = E; i != S; i = prev[i])
			path[i]->addFlow(flow);
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
