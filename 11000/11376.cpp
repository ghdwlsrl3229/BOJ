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
int N, M, A[MAX_V], B[MAX_V];
vector<int> adj[MAX_V];
bool visited[MAX_V];

bool dfs(int a) {
	visited[a] = 1;
	for (int b : adj[a]) {
		if (B[b] == -1 || !visited[B[b]] && dfs(B[b])) {
			B[b] = a;
			A[a] = b;
			return 1;
		}
	}
	return 0;
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		for (int j = 0; j < a; j++) {
			int b; cin >> b;
			adj[2 * i].push_back(b);
			adj[2 * i + 1].push_back(b);
		}
	}

	int ans = 0;
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	for (int i = 0; i < 2 * N; i++) {
		if (A[i] == -1) {
			memset(visited, 0, sizeof(visited));
			if (dfs(i)) ans++;
		}
	}
	cout << ans << '\n';
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
