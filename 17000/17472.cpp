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
int arr[15][15];

int pa[7];
int find(int n) {
	if (pa[n] < 0) return n;
	return pa[n] = find(pa[n]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	pa[b] = a;
}

int island[15][15]; 
int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0 ,0 };
int island_num;
void dfs(int y, int x) {
	island[y][x] = island_num;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (arr[ny][nx] == 0 || island[ny][nx] != 0) continue;
		dfs(ny, nx);
	}
}

vector<tuple<int, int, int>> edges;

void solve(int tc) {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (arr[i][j] == 1 && island[i][j] == 0) {
				island_num++;
				dfs(i, j);
			}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (island[i][j] == 0) continue;
			for (int k = 0; k < 4; k++) {
				int y = i, x = j;
				while (1) {
					y += dy[k];
					x += dx[k];
					if (y < 0 || x < 0 || y >= N || x >= M) break;
					if (island[y][x]) {
						if (island[y][x] != island[i][j]) {
							int w = abs(i - y) + abs(x - j) - 1;
							int u = island[i][j];
							int v = island[y][x];
							if (w >= 2) edges.push_back({ w, u, v });
						}
						break;
					}
				}
			}
		}
	sort(all(edges));

	int ans = 0;
	memset(pa, -1, sizeof(pa));
	for (int i = 0; i < edges.size(); i++) {
		int w, u, v;
		tie(w, u, v) = edges[i];
		if (find(u) != find(v)) {
			merge(u, v);
			ans += w;
		}
	}

	for (int i = 1; i <= island_num; i++ )
		if (find(1) != find(i)) {
			cout << -1 << '\n';
			return;
		}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if (0) {
		int T; cin >> T;
		for (int i = 1; i <= T; i++) solve(i);
	}
	else {
		solve(0);
	}
	return 0;
}
