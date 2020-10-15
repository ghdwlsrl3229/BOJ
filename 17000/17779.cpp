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
int A[22][22];
int B[22][22];

int coloring(int x, int y, int d1, int d2) {
	memset(B, 0, sizeof(B));

	for (int r = 1; r < x + d1; r++) for (int c = 1; c <= y; c++) B[r][c] = 1;
	for (int r = 1; r <= x + d2; r++) for (int c = y + 1; c <= N; c++) B[r][c] = 2;
	for (int r = x + d1; r <= N; r++) for (int c = 1; c < y - d1 + d2; c++) B[r][c] = 3;
	for (int r = x + d2 + 1; r <= N; r++) for (int c = y - d1 + d2; c <= N; c++) B[r][c] = 4;

	for (int c = y - d1, r = x + d1; r <= x + d1 + d2; r++, c++) B[r][c] = 5;
	for (int c = y + d2, r = x + d2; r <= x + d1 + d2; r++, c--) B[r][c] = 5;

	for (int c = y, r = x; r <= x + d2; c++, r++) {
		for (int i = r; B[i][c] != 5; i++) B[i][c] = 5;
	}

	for (int c = y, r = x; r <= x + d1; c--, r++) {
		for (int i = r; B[i][c] != 5; i++) B[i][c] = 5;
	}

	int cnt[5] = { 0 };
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cnt[B[i][j] - 1] += A[i][j];
	sort(cnt, cnt + 5);

	return cnt[4] - cnt[0];
}

void solve(int tc) {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];

	int ans = 1e9;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= N; k++)
				for (int s = 1; s <= N; s++) {
					int x = i, y = j, d1 = k, d2 = s;
					if (x + d1 + d2 > N || y - d1 < 1 || y + d2 > N) continue;
					int cnt = coloring(x, y, d1, d2);
					ans = min(ans, cnt);
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
