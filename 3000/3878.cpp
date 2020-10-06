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

int ccw(pos a, pos b, pos c) {
	long long ret = a.x * b.y + b.x * c.y + c.x * a.y;
	ret -= b.x * a.y + c.x * b.y + a.x * c.y;
	if (ret > 0) return 1;
	if (ret) return -1;
	return 0;
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

int isIntersect(pair<pos, pos> x, pair<pos, pos> y) {
	pos a = x.first, b = x.second, c = y.first, d = y.second;
	int ab = ccw(a, b, c)*ccw(a, b, d);
	int cd = ccw(c, d, a)*ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return !(c > b || a > d);
	}
	return ab <= 0 && cd <= 0;
}

bool in_hull(vector<pos>& hull, pos p) {
	if (hull.size() < 3) return 0;
	for (int i = 0; i < (int)hull.size() - 1; i++) {
		if (ccw(hull[i], hull[i + 1], p) < 0) return 0;
	}
	if (ccw(hull.back(), hull[0], p) < 0) return 0;
	return 1;
}

void solve() {
	int N, M; cin >> N >> M;
	vector<pos> black(N), white(M);
	for (int i = 0; i < N; i++)cin >> black[i].x >> black[i].y;
	for (int i = 0; i < M; i++)cin >> white[i].x >> white[i].y;

	vector<pos> black_hull = convex_hull(black);
	vector<pos> white_hull = convex_hull(white);

	for (pos i : black_hull)
		if (in_hull(white_hull, i)) {
			cout << "NO\n";
			return;
		}

	for (pos i : white_hull)
		if (in_hull(black_hull, i)) {
			cout << "NO\n";
			return;
		}

	vector<pair<pos, pos>> black_line, white_line;
	for (int i = 0; i < (int)black_hull.size() - 1; i++) 
		black_line.push_back({ black_hull[i], black_hull[i + 1] });
	for (int i = 0; i < (int)white_hull.size() - 1; i++)
		white_line.push_back({ white_hull[i], white_hull[i + 1] });
	black_line.push_back({ black_hull[0], black_hull.back() });
	white_line.push_back({ white_hull[0], white_hull.back() });

	for (auto i : black_line)
		for (auto j : white_line) 
			if (isIntersect(i, j)) {
				cout << "NO\n";
				return;
			}

	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if (1) {
		int T; cin >> T;
		while (T--) solve();
	}
	else {
		solve();
	}
	return 0;
}
