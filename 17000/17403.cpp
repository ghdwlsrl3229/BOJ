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

int h[1100];

void solve() {
	int N; cin >> N;
	vector<pos> v(N);
	map<pll, int> num;
	for (int i = 0; i < N; i++) {
		cin >> v[i].x >> v[i].y;
		num[{v[i].x, v[i].y}] = i;
	}
	for (int t = 1;; t++) {
		if (v.size() <= 2) break;
		vector<pos> hull = convex_hull(v);
		if (hull.size() < 3) break;
		for (pos i : hull) h[num[{i.x, i.y}]] = t;
		
		vector<pos> nv;
		for (pos i : v) if (h[num[{i.x, i.y}]] == 0) nv.push_back(i);

		if (nv.size() == v.size()) break;
		v = nv;
	}

	for (int i = 0; i < N; i++) cout << h[i] << ' ';
	cout << '\n';
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
