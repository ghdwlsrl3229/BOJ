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

const int MAX = 1 << 17;
struct Segtree {
	ll t[4 * MAX];
	void modify(int p, ll value) {
		for (t[p += MAX] += value; p > 1; p >>= 1)
			t[p >> 1] = t[p] + t[p ^ 1];
	}
	ll median(int sz) {
		int k = sz / 2 + 1;
		int pos = 1;
		while (pos < MAX) {
			if (k <= t[2 * pos]) pos *= 2;
			else k -= t[2 * pos], pos = 2 * pos + 1;
		}
		return pos - MAX;
	}
};

int N, M, K, W;
int arr[330][330];
int ans[330][330];
Segtree st;

void solve(int tc) {
	cin >> N >> M >> K >> W;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	int N2 = N - W + 1, M2 = M - W + 1;
	for (int i = 0; i < W; i++)
		for (int j = 0; j < W; j++)
			st.modify(arr[i][j], 1);

	int y = 0;
	while (y < N2) {
		if (y % 2 == 0) {
			if (y != 0) {
				for (int i = 0; i < W; i++) st.modify(arr[y - 1][i], -1);
				for (int i = 0; i < W; i++) st.modify(arr[y + W - 1][i], 1);
			}
			ans[y][0] = st.median(W*W);

			for (int i = 1; i < M2; i++) {
				for (int j = 0; j < W; j++) {
					st.modify(arr[y + j][i - 1], -1);
					st.modify(arr[y + j][i + W - 1], 1);
				}
				ans[y][i] = st.median(W*W);
			}
		}
		else {
			if (y != 0) {
				for (int i = M - W; i < M; i++) st.modify(arr[y - 1][i], -1);
				for (int i = M - W; i < M; i++) st.modify(arr[y + W - 1][i], 1);
			}
			ans[y][M2 - 1] = st.median(W*W);
			for (int i = M2 - 2; i >= 0; i--) {
				for (int j = 0; j < W; j++) {
					st.modify(arr[y + j][i], 1);
					st.modify(arr[y + j][i + W], -1);
				}
				ans[y][i] = st.median(W*W);
			}
		}

		y++;
	}

	for (int i = 0; i < N2; i++) {
		for (int j = 0; j < M2; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
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
