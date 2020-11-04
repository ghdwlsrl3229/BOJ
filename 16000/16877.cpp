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

int fib[35];
int arr[110000];
int dp[3300000];

void solve(int tc) {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	fib[0] = 1, fib[1] = 1;
	for (int i = 2; i < 35; i++) fib[i] = fib[i - 1] + fib[i - 2];

	for (int i = 0; i <= 3000000; i++) {
		int cnt[40] = { 0 };
		for (int j = 0; j < 35; j++) {
			if (i >= fib[j]) cnt[dp[i - fib[j]]] = 1;
			else break;
		}
		for (int j = 0; j < 35; j++)
			if (cnt[j] == 0) {
				dp[i] = j;
				break;
			}
	}

	int res = dp[arr[0]];
	for (int i = 1; i < n; i++) res ^= dp[arr[i]];

	if (res) cout << "koosaga\n";
	else cout << "cubelover\n";
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
