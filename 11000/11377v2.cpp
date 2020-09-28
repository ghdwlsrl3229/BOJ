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

void solve() {
	int N, M, K; cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		while (a--) {
			int b; cin >> b;
			adj[i * 2].push_back(b);
			adj[i * 2 + 1].push_back(b);
		}
	}

	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < N; i++) {
		int v = i * 2;
		if (A[v] == -1) {
			memset(visited, 0, sizeof(visited));
			if (dfs(v)) cnt1++;
		}
	}
	for (int i = 0; i < N; i++) {
		int v = i * 2 + 1;
		if (A[v] == -1) {
			memset(visited, 0, sizeof(visited));
			if (dfs(v)) cnt2++;
			if (cnt2 == K) break;
		}
	}

	cout << cnt1 + cnt2 << '\n';
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
