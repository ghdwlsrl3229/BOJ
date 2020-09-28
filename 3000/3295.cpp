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

const int MAX = 2200;
int A[MAX], B[MAX];
vector<int> adj[MAX];
bool visited[MAX];

bool dfs(int a) {
	visited[a] = true;
	for (int b : adj[a]) {
		if (B[b] == -1 || !visited[B[b]] && dfs(B[b])) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i <= 2 * n; i++) adj[i].clear();
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[2 * a + 1].push_back(2 * b);
	}

	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	int cnt = 0;
	for (int i = 0; i <= 2 * n; i++) {
		if (A[i] == -1) {
			memset(visited, 0, sizeof(visited));
			if (dfs(i)) cnt++;
		}
	}
	cout << cnt << '\n';
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
