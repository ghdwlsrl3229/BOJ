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

ll n, m;
vector<ll> le, ri, rpsum, lpsum;

double d(ll h) {
	double ret = 0;
	ll idx = lower_bound(all(le), h) - le.begin();
	ll h_le = idx * h - lpsum[idx];
	ll h_ri = lpsum[n] - lpsum[idx] - (n - idx) * h;
	ret += (double)m * (h_le + h_ri);

	idx = lower_bound(all(ri), h) - ri.begin();
	h_le = idx * h - rpsum[idx];
	h_ri = rpsum[m] - rpsum[idx] - (m - idx) * h;
	ret += (double)n * (h_le + h_ri);
	return ret;
}

void solve() {
	cin >> n >> m;
	le.resize(n); ri.resize(m);
	for (int i = 0; i < n; i++) cin >> le[i];
	for (int i = 0; i < m; i++) cin >> ri[i];

	sort(all(le)); sort(all(ri));

	rpsum.resize(m + 1); lpsum.resize(n + 1);
	rpsum[0] = lpsum[0] = 0;
	for (int i = 0; i < n; i++) lpsum[i + 1] = lpsum[i] + le[i];
	for (int i = 0; i < m; i++) rpsum[i + 1] = rpsum[i] + ri[i];

	double dist = 2e20;
	ll h = 0;
	for (int i = 0; i < n; i++) {
		double dist_cand = d(le[i]);
		if (abs(dist - dist_cand) < 1e-9) h = min(h, le[i]);
		else if (dist > dist_cand) dist = dist_cand, h = le[i];
	}
	for (int i = 0; i < m; i++) {
		double dist_cand = d(ri[i]);
		if (abs(dist - dist_cand) < 1e-9) h = min(h, ri[i]);
		else if (dist > dist_cand) dist = dist_cand, h = ri[i];
	}

	cout << h << ".0\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) solve();
	return 0;
}
