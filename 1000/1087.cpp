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

struct asdf {
	double px, py, vx, vy;
};

int N;
vector<asdf> v;

double f(double t) {
	double maxx, maxy, minx, miny;
	maxx = minx = v[0].px + v[0].vx * t;
	maxy = miny = v[0].py + v[0].vy * t;
	for (int i = 0; i < N; i++) {
		double px = v[i].px, py = v[i].py, vx = v[i].vx, vy = v[i].vy;
		maxx = max(maxx, px + vx * t);
		minx = min(minx, px + vx * t);
		maxy = max(maxy, py + vy * t);
		miny = min(miny, py + vy * t);
	}
	return max(maxx - minx, maxy - miny);
}

void solve(int tc) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		double a, b, c, d; cin >> a >> b >> c >> d;
		v.push_back({ a, b, c, d });
	}
	double lo = 0, hi = 1e9;
	for (int i = 0; i < 2000; i++) {
		double p = (lo * 2 + hi) / 3, q = (lo + hi * 2) / 3;
		if (f(p) <= f(q)) hi = q;
		else lo = p;
	}

	double ans = f(hi);
	printf("%.11f", ans);
}

int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	if (0) {
		int T; cin >> T;
		for (int i = 1; i <= T; i++) solve(i);
	}
	else {
		solve(0);
	}
	return 0;
}
