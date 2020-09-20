
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
char arr[2200][2200];
int ans[2200][2200];
int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0, 0 };

void f(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		arr[ny][nx] = arr[ny][nx] == 'W' ? 'B' : 'W';
	}
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			f(i, j), ans[i][j] = 2;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (arr[i][j] == 'B') ans[i][j] = 3;

	cout << 1 << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << ans[i][j];
		cout << '\n';
	}
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
