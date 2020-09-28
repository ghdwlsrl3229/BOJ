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

const int MAX = 110;
const int INF = 1e9;

int A[MAX], B[MAX];
bool visited[MAX];
vector<int> adj[MAX];

bool dfs(int a) {
	visited[a] = 1;
	for (int b : adj[a]) {
		if (B[b] == -1 || !visited[B[b]] && dfs(B[b])) {
			A[a] = b;
			B[b] = a;
			return 1;
		}
	}
	return 0;
}

int N, M;
vector<int> seg[MAX];
vector<pll> times;

bool f(int mid) {
	for (int i = 0; i < MAX; i++) adj[i].clear();
	for (int i = 0; i < times.size(); i++)
		for (int j = times[i].fr; j <= min(times[i].sc, 1LL*mid - 1); j++)
			for (int k : seg[i])
				adj[j].push_back(k);

	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	int cnt = 0;
	for (int i = 0; i <= 100; i++) {
		if (A[i] == -1) {
			memset(visited, 0, sizeof(visited));
			if (dfs(i)) cnt++;
		}
	}
	return cnt == N;
}

void solve() {
	cin >> N >> M;
	times.clear();
	for (int i = 0; i < MAX; i++) seg[i].clear();
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		times.push_back({ a, b - 1 });
		while (c--) {
			int d; cin >> d;
			seg[i].push_back(d);
		}
	}

	int lo = 0, hi = 110;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (f(mid)) hi = mid;
		else lo = mid + 1;
	}
	if (hi > 100) cout << -1 << '\n';
	else cout << hi << '\n';
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
