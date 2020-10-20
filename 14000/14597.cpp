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

int H, W;
int arr1[110][110], arr2[110][110];

ll cache[110][110];
ll dp(int y, int x) {
	if (y == H) return 0;

	ll& ret = cache[y][x];
	if (ret != -1) return ret;

	ret = dp(y + 1, x) + (arr1[y][x] - arr2[y][x]) * (arr1[y][x] - arr2[y][x]);
	if (x + 1 < W) ret = min(ret, dp(y + 1, x + 1) + (arr1[y][x] - arr2[y][x]) * (arr1[y][x] - arr2[y][x]));
	if (x - 1 >= 0) ret = min(ret, dp(y + 1, x - 1) + (arr1[y][x] - arr2[y][x]) * (arr1[y][x] - arr2[y][x]));
	return ret;
}

void solve(int tc) {
	cin >> H >> W;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> arr1[i][j];
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> arr2[i][j];

	ll ans = 2e18;
	for (int i = 0; i < W; i++) {
		memset(cache, -1, sizeof(cache));
		ans = min(ans, dp(0, i));
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
