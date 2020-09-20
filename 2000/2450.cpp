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
int arr[110000];
int total[4];

int f(int a, int b, int c) {
	int cnt[3][4];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < total[a]; i++) cnt[0][arr[i]]++;
	for (int i = total[a]; i < total[a] + total[b]; i++) cnt[1][arr[i]]++;
	for (int i = total[a] + total[b]; i < N; i++) cnt[2][arr[i]]++;
	return cnt[0][b] + cnt[0][c] + max(cnt[1][c], cnt[2][b]);
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++) total[arr[i]]++;

	int ans = 1e9;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			for (int k = 1; k <= 3; k++)
				if (i != j && i != k && j != k) {
					ans = min(ans, f(i, j, k));
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
