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

int R, C;
char arr[55][55];
int dist[MAX][MAX];
int park_sz;
map<pll, int> park_mp;
vector<pll> cars;
int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0 ,0 };

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

bool f(int mid) {
	for (int i = 0; i < MAX; i++) adj[i].clear();
	for (int i = 0; i < cars.size(); i++)
		for (int j = 0; j < park_sz; j++)
			if (dist[i][j] <= mid && dist[i][j] != 0)
				adj[i].push_back(j);

	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	for (int i = 0; i < cars.size(); i++)
		if (A[i] == -1) {
			memset(visited, 0, sizeof(visited));
			if (!dfs(i)) return 0;
		}
	return 1;
}

void solve() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) cin >> arr[i];
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 'C') cars.push_back({ i, j });
			if (arr[i][j] == 'P') park_mp[pll(i, j)] = park_sz++;
		}

	for (int i = 0; i < cars.size(); i++) {
		bool visited[55][55];
		memset(visited, 0, sizeof(visited));
		queue<pll> q;
		q.push(cars[i]);
		visited[cars[i].fr][cars[i].sc] = 1;

		int cnt = 0;
		while (q.size()) {
			int qsz = q.size();
			while (qsz--) {
				int y = q.front().fr;
				int x = q.front().sc;
				q.pop();

				if (arr[y][x] == 'P') {
					dist[i][park_mp[pll(y, x)]] = cnt;
				}

				for (int j = 0; j < 4; j++) {
					int ny = y + dy[j];
					int nx = x + dx[j];
					if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
					if (arr[ny][nx] == 'X') continue;
					if (visited[ny][nx]) continue;
					visited[ny][nx] = 1;
					q.push(pll(ny, nx));
				}
			}
			cnt++;
		}
	}

	int lo = 0, hi = 1e9;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (f(mid)) hi = mid;
		else lo = mid + 1;
	}
	if (cars.size() == 0) cout << 0 << '\n';
	else if (hi == 1e9) cout << -1 << '\n';
	else cout << hi << '\n';
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
