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

ll N, M;
vector<ll> v;

bool f(unsigned ll mid) {
	unsigned ll cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt += mid / v[i];
		if (cnt >= M) return 1;
	}
	return 0;
}

void solve(int tc) {
	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	ll lo = 0, hi = 1e18;
	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		if (f(mid)) hi = mid;
		else lo = mid + 1;
	}
	cout << hi << '\n';
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
