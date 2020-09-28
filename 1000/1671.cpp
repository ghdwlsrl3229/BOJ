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

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
	int a1, a2, a3, b1, b2, b3;
	tie(a1, a2, a3) = a, tie(b1, b2, b3) = b;
	return a1 >= b1 && a2 >= b2 && a3 >= b3;
}

void solve() {
	int N; cin >> N;
	vector<tuple<int, int, int>> v(N);
	for (int i = 0; i < N; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[i] = { a, b, c };
	}
	
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++) {
			if (cmp(v[i], v[j])) {
				adj[i * 2].push_back(j);
				adj[i * 2 + 1].push_back(j);
			}
			else if (cmp(v[j], v[i])) {
				adj[j * 2].push_back(i);
				adj[j * 2 + 1].push_back(i);
			}
		}

	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	int cnt = 0;
	for (int i = 0; i <= 2 * N; i++) {
		if (A[i] == -1) {
			memset(visited, 0, sizeof(visited));
			if (dfs(i)) cnt++;
		}
	}
	cout << N - cnt << '\n';
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
