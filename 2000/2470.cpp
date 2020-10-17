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

void solve(int tc) {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	int abssum = 2e9 + 1;
	int ans[2];

	int lo = 0;
	for (int hi = N - 1; hi >= 0; hi--) {
		while (lo < hi - 1 && abs(arr[hi] + arr[lo]) >= abs(arr[hi] + arr[lo + 1])) lo++;
	//	cout << arr[lo] << ' ' << arr[hi] << '\n';
		if (lo != hi && abs(arr[hi] + arr[lo]) <= abssum) {
			abssum = abs(arr[hi] + arr[lo]);
			ans[0] = arr[lo];
			ans[1] = arr[hi];
		}
	}
	cout << ans[0] << ' ' << ans[1] << '\n';
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
