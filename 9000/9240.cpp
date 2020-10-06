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

double rotatingCalipers(vector<pos>& hull) {
	int pt = 0;
	long long ret = 0;
	for (int i = 0; i < hull.size(); i++) {
		while (pt + 1 < hull.size() && chk(hull[i], hull[i + 1], hull[pt], hull[pt + 1])) {
			ret = max(ret, dist(hull[i], hull[pt]));
			++pt;
		}
		ret = max(ret, dist(hull[i], hull[pt]));
	}
	return sqrt(ret);
}

void solve() {
	int N; cin >> N;
	vector<pos> v(N);
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		v[i] = pos(x, y);
	}

	vector<pos> ch = convex_hull(v);
	double ans = rotatingCalipers(ch);
	printf("%.6f", ans);
}

int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	if (0) {
		int T; cin >> T;
		while (T--) solve();
	}
	else {
		solve();
	}
	return 0;
}
