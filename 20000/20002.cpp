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

int N;
int arr[330][330];
int psum[330][330];

int cost(int y, int x, int sz) {
	int ny = min(y + sz, N);
	int nx = min(x + sz, N);
	return psum[ny][nx] - psum[y][nx] - psum[ny][x] + psum[y][x];
}

void solve() {
	 cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			psum[i + 1][j + 1] = psum[i][j + 1] + psum[i + 1][j] - psum[i][j] + arr[i][j];

	int ans = -1e9;
	for (int k = 1; k <= N; k++) {
		for (int i = 0; i < N - k + 1; i++)
			for (int j = 0; j < N - k + 1; j++)
				ans = max(ans, cost(i, j, k));
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
