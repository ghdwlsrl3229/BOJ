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
pll arr[1100];

ll dist(pll a, pll b) {
	return (a.fr - b.fr) * (a.fr - b.fr) + (a.sc - b.sc) * (a.sc - b.sc);
}

void solve(int tc) {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].fr >> arr[i].sc;

	ll mindist = 2e18;
	pll ans;
	for (int i = 0; i < N; i++) {
		ll maxdist = 0;
		for (int j = 0; j < N; j++) {
			maxdist = max(maxdist, dist(arr[i], arr[j]));
		}
		if (maxdist <= mindist) {
			mindist = maxdist;
			ans = arr[i];
		}
	}
	cout << ans.fr << ' ' << ans.sc << '\n';
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
