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

struct asdf {
	int y, x, k;
};

int N, M, K;
char arr[1100][1100];
bool visited[1100][1100][15];
int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1 ,0 ,0 };

void solve(int tc) {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	
	queue<asdf> q;
	visited[0][0][0] = 1;
	q.push({ 0, 0, 0 });

	int cnt = 0;
	while (q.size()) {
		int qsz = q.size();
		while (qsz--) {
			asdf cur = q.front();
			q.pop();

			if (cur.y == N - 1 && cur.x == M - 1) {
				cout << cnt + 1 << '\n';
				return;
			}

			for (int i = 0; i < 4; i++) {
				int ny = cur.y + dy[i];
				int nx = cur.x + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				if (arr[ny][nx] == '0') {
					if (visited[ny][nx][cur.k]) continue;
					q.push({ ny, nx, cur.k });
					visited[ny][nx][cur.k] = 1;
				}
				else {
					if (cur.k + 1 > K) continue;
					if (visited[ny][nx][cur.k + 1]) continue;
					q.push({ ny, nx, cur.k + 1 });
					visited[ny][nx][cur.k + 1] = 1;
				}
			}
		}
		cnt++;
	}
	cout << -1 << '\n';
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
