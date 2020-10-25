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

struct pos {
	long long x, y;
	pos(long long a, long long b) : x(a), y(b) {}
	pos() {}
	bool operator < (pos &rhs) {
		if (x != rhs.x) return x < rhs.x;
		return y < rhs.y;
	}
	bool operator > (pos& rhs) {
		if (x != rhs.x) return x > rhs.x;
		return y > rhs.y;
	}
};

struct asdf {
	ll x, y, dx, dy;
};

int ccw(pos a, pos b, pos c) {
	long long ret = a.x * b.y + b.x * c.y + c.x * a.y;
	ret -= b.x * a.y + c.x * b.y + a.x * c.y;
	if (ret > 0) return 1;
	if (ret) return -1;
	return 0;
}

bool chk(pos a, pos b, pos c, pos d) {
	pos t = { b.x - a.x, b.y - a.y };
	pos tt = { d.x - c.x, d.y - c.y };
	return ccw({ 0, 0 }, t, tt) >= 0;
}

long long dist(pos a, pos b) {
	long long dx = b.x - a.x;
	long long dy = b.y - a.y;
	return dx * dx + dy * dy;
}

vector<pos> convex_hull(vector<pos>& point) {
	vector<pos> hull;
	swap(point[0], *min_element(point.begin(), point.end()));
	sort(point.begin() + 1, point.end(), [&](pos a, pos b) {
		int cw = ccw(point[0], a, b);
		if (cw) return cw > 0;
		return dist(point[0], a) < dist(point[0], b);
	});
	for (auto i : point) {
		while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), i) <= 0) {
			hull.pop_back();
		}
		hull.push_back(i);
	}
	return hull;
}

ll rotatingCalipers(vector<pos>& hull) {
	int pt = 0;
	long long ret = 0;
	for (int i = 0; i < hull.size(); i++) {
		while (pt + 1 < hull.size() && chk(hull[i], hull[i + 1], hull[pt], hull[pt + 1])) {
			ret = max(ret, dist(hull[i], hull[pt]));
			++pt;
		}
		ret = max(ret, dist(hull[i], hull[pt]));
	}
	return ret;
}

int N, T;
vector<asdf> v;

ll f(ll t) {
	vector<pos> p(N);
	for (int i = 0; i < N; i++) 
		p[i] = { v[i].x + t * v[i].dx, v[i].y + t * v[i].dy };
	vector<pos> hull = convex_hull(p);
	return rotatingCalipers(hull);
}

void solve(int tc) {
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		v.push_back({ a, b, c, d });
	}

	int lo = 0, hi = T;
	while (hi - lo >= 3) {
		int p = (lo * 2 + hi) / 3, q = (lo + hi * 2) / 3;
		if (f(p) <= f(q)) hi = q;
		else lo = p;
	}

	ll res = 1e18, mint = 1e18;
	for (int i = lo; i <= hi; ++i) {
		ll tmp = f(i);
		if (tmp <= res) {
			if (tmp == res) mint = min(mint, 1LL*i);
			else {
				res = tmp;
				mint = i;
			}
		}
	}
	cout << mint << '\n';
	cout << res << '\n';

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
