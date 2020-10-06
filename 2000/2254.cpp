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

const int MAX = 100000;

struct Point {
	int x, y; // 실제 위치
	int p, q; // 기준점으로부터의 상대 위치
	Point() : Point(0, 0, 1, 0) {}
	Point(int x1, int y1) : Point(x1, y1, 1, 0) {}
	Point(int x1, int y1, int p1, int q1) : x(x1), y(y1), p(p1), q(q1) {}
	// p, q 값을 기준으로 정렬하기 위한 관계연산자
	bool operator <(const Point& O) {
		if (1LL * q*O.p != 1LL * p*O.q) return 1LL * q*O.p < 1LL * p*O.q;
		if (y != O.y) return y < O.y;
		return x < O.x;
	}
};

// 벡터 AB와 벡터 AC의 CW/CCW
long long ccw(const Point& A, const Point& B, const Point& C) {
	return 1LL * (B.x - A.x)*(C.y - A.y) - 1LL * (B.y - A.y)*(C.x - A.x);
}

int ans;
vector<Point> v;
bool used[1100];
Point P;

bool in_convex_hull(vector<Point>& p, vector<int>& s) {
	for (int i = 0; i < (int)s.size() - 1; i++) {
		Point cur = p[s[i]], next = p[s[i + 1]];
		if (ccw(cur, next, P) <= 0) return false;
	}
	return true;
}

void convex_hull(vector<Point>& p) {
	if (p.size() < 3) return;
	sort(all(p));
	for (int i = 1; i < p.size(); i++) {
		p[i].p = p[i].x - p[0].x;
		p[i].q = p[i].y - p[0].y;
	}
	sort(p.begin() + 1, p.end());

	vector<int> stk;
	stk.push_back(0);
	stk.push_back(1);
	int next = 2;

	while (next < p.size()) {
		while (stk.size() >= 2) {
			int first, second;
			first = stk.back();
			stk.pop_back();
			second = stk.back();
			if (ccw(p[second], p[first], p[next]) > 0) {
				stk.push_back(first);
				break;
			}
		}
		stk.push_back(next++);
	}

	if (stk.size() < 3) return;
	for (int i = 0; i < stk.size(); i++) used[stk[i]] = 1;
	if (in_convex_hull(p, stk)) ans++;
}

void solve() {
	int N, Px, Py;
	cin >> N >> Px >> Py;
	P = Point(Px, Py);
	v.resize(N);
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		v[i] = Point(x, y);
	}

	while (1) {
		memset(used, 0, sizeof(used));
		convex_hull(v);
		vector<Point> nv;
		for (int i = 0; i < v.size(); i++) if (!used[i]) nv.push_back(v[i]);
		if (v.size() == nv.size()) break;
		v = nv;
	}
	cout << ans << '\n';
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
