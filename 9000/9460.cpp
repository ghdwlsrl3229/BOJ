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

int n, k;
vector<pair<double, double>> v;

bool f(double mid) {
	int cnt = 1;
	double mn = v[0].sc, mx = v[0].sc;

	for (int i = 1; i < n; i++) {
		mn = min(mn, v[i].sc);
		mx = max(mx, v[i].sc);
		if ((mx - mn) / 2 > mid) {
			cnt++;
			mn = mx = v[i].sc;
		}
	}
	return cnt <= k;
}

void solve() {
	scanf("%d%d", &n, &k);
	v.resize(n);
	for (int i = 0; i < n; i++) scanf("%lf%lf", &(v[i].fr), &(v[i].sc));
	sort(all(v));

	double lo = 0, hi = 1e10;
	for (int i = 0; i < 200; i++){
		double mid = (lo + hi) / 2;
		if (f(mid)) hi = mid;
		else lo = mid;	
	}
	printf("%.1lf\n", lo);
}

int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
