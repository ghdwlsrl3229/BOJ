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

void solve() {
	int N, M; cin >> N >> M;
	vector<pll> v(M);
	vector<ll> ys, xs;
	ll xsum = 0, ysum = 0;
	for (int i = 0; i < M; i++) {
		cin >> v[i].fr >> v[i].sc;
		xsum += v[i].fr, ysum += v[i].sc;
		xs.push_back(v[i].fr);
		ys.push_back(v[i].sc);
	}

	ll xans = 1e18, yans = 1e18;
	sort(all(ys));
	sort(all(xs));

	ll sum = 0;
	for (int i = 0; i < M; i++) {
		xans = min(xans, (xs[i] * i - sum) + (xsum - sum - xs[i] * (M - i)));
		sum += xs[i];
	}
	sum = 0;
	for (int i = 0; i < M; i++) {
		yans = min(yans, (ys[i] * i - sum) + (ysum - sum - ys[i] * (M - i)));
		sum += ys[i];
	}
	cout << xans + yans << '\n';
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
