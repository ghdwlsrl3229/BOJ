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
char arr[770][770];
int dist[770][770];
int row[770][770], col[770][770];
bool visited[770][770];
int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1 ,0 ,0 };

pll pirate, you, treasure;

void row_dfs(int y, int x) {
	int xpos = x, st;
	while (xpos > 0 && arr[y][xpos] != 'I') xpos--;
	if (arr[y][xpos] == 'I') xpos++;
	st = xpos;

	int row_min = 1e9;
	while (xpos < M && arr[y][xpos] != 'I') {
		if (dist[y][xpos]) row_min = min(row_min, dist[y][xpos]);
		xpos++;
	}
	for (int i = st; i < xpos; i++) row[y][i] = row_min;
}
void col_dfs(int y, int x) {
	int ypos = y, st;
	while (ypos > 0 && arr[ypos][x] != 'I') ypos--;
	if (arr[ypos][x] == 'I') ypos++;
	st = ypos;

	int col_min = 1e9;
	while (ypos < N && arr[ypos][x] != 'I') {
		if (dist[ypos][x]) col_min = min(col_min, dist[ypos][x]);
		ypos++;
	}
	for (int i = st; i < ypos; i++) col[i][x] = col_min;
}

void solve(int tc) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'Y') you = { i, j };
			else if (arr[i][j] == 'V') pirate = { i, j };
			else if (arr[i][j] == 'T') treasure = { i, j };
		}

	//해적의 모든 정점으로의 최단 거리(dist)를 전처리
	queue<pll> q;
	visited[pirate.fr][pirate.sc] = 1;
	q.push(pirate);
	int cnt = 0;
	while (q.size()) {
		int qsz = q.size();
		while (qsz--) {
			pll cur = q.front();
			q.pop();
			dist[cur.fr][cur.sc] = cnt;
			for (int i = 0; i < 4; i++) {
				int ny = cur.fr + dy[i];
				int nx = cur.sc + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				if (visited[ny][nx]) continue;
				if (arr[ny][nx] == 'I') continue;
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}
		cnt++;
	}

	//각 행열의 가장 작은 dist 전처리
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (row[i][j] == 0) row_dfs(i, j);
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (col[i][j] == 0) col_dfs(i, j);
		}

	queue<pll> q2;
	memset(visited, 0, sizeof(visited));
	visited[you.fr][you.sc] = 1;
	q2.push(you);

	cnt = 0;
	while (q2.size()) {
		int qsz = q2.size();
		while (qsz--) {
			pll cur = q2.front();
			q2.pop();

			if (cur == treasure) {
				cout << "YES\n";
				return;
			}

			for (int i = 0; i < 4; i++) {
				int ny = cur.fr + dy[i];
				int nx = cur.sc + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				if (visited[ny][nx]) continue;
				if (arr[ny][nx] == 'I') continue;
				if (cnt + 1 >= row[ny][nx] || cnt + 1 >= col[ny][nx]) continue;
				visited[ny][nx] = 1;
				q2.push({ ny, nx });
			}
		}
		cnt++;
	}
	cout << "NO\n";
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
