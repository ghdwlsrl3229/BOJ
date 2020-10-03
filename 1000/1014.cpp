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

int N, M;
char arr[11][11];
int A[110], B[110];
vector<int> adj[110];
bool visited[110];

int dy[] = { 0, -1, -1, 0, 1, 1 };
int dx[] = { -1, -1, 1, 1, -1, 1 };

int toInt(int y, int x) {
	return y * M + x;
}

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
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) adj[toInt(i, j)].clear();

	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'x') continue;
			else ans++;
			int cur = toInt(i, j);
			for (int k = 0; k < 6; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				if (arr[ny][nx] == 'x') continue;
				int nxt = toInt(ny, nx);

				if (j % 2 == 1) {
					adj[cur].push_back(nxt);
				}
			}
		}

	int min_cover = 0;
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			int cur = toInt(i, j);
			if (A[cur] == -1) {
				memset(visited, 0, sizeof(visited));
				if (dfs(cur)) min_cover++;
			}
		}

	ans -= min_cover;
	cout << ans << '\n';
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
