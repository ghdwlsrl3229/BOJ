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

struct line {
	ll a, b, c;
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

double lpdist(line l, pos p) {
	return abs(l.a * p.x + l.b * p.y + l.c) / sqrt(dist({ 0, 0 }, { l.a, l.b }));
}

bool in_hull(vector<pos>& hull, pos p) {
	if (hull.size() < 3) return 0;
	for (int i = 0; i < (int)hull.size() - 1; i++) {
		if (ccw(hull[i], hull[i + 1], p) < 0) return 0;
	}
	if (ccw(hull.back(), hull[0], p) < 0) return 0;
	return 1;
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

void solve(int tc) {
	cout << fixed;
	cout.precision(2);
	while (1) {
		tc++;
		int n; cin >> n;
		if (n == 0) break;
		vector<pos> v(n);
		for (int i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
		vector<pos> hull = convex_hull(v);

		double ans = 1e18;
		for (int i = 0; i < hull.size(); i++) {
			int j = (i + 1) % hull.size();
			line tmp = { hull[j].y - hull[i].y,
					hull[i].x - hull[j].x, hull[j].x*hull[i].y - hull[j].y*hull[i].x };
			double mx = 0;
			for (int j = 0; j < hull.size(); j++) {
				mx = max(mx, lpdist(tmp, hull[j]));
			}
			ans = min(ans, mx);
		}
		ans += 0.004999999999;

		cout << "Case " << tc << ": ";
		cout << ans << '\n';
	}
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
