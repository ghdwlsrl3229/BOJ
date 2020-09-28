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

const int MAX = 330;

int A[MAX], B[MAX];
vector<int> adj[MAX];
bool visited[MAX];

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

void solve() {
	int R, C, N; cin >> R >> C >> N;
	set<pll> st;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		st.insert({ a, b });
	}

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			if (st.find({ i, j }) == st.end())
				adj[i].push_back(j);

	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	int cnt = 0;
	for (int i = 1; i <= R; i++) {
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
	if (0) {
		int T; cin >> T;
		while (T--) solve();
	}
	else {
		solve();
	}
	return 0;
}
