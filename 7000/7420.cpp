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

double dist(const Point& a, const Point& b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double angle(const Point& a, const Point& b, const Point& c) {
	Point vec1 = Point(a.x - b.x, a.y - b.y), vec2 = Point(c.x - b.x, c.y - b.y);
	ll dot = vec1.x * vec2.x + vec1.y * vec2.y;
	return acos(dot / (dist(a, b) * dist(b, c)));
}

void solve() {
	int N, L; scanf("%d%d", &N, &L);
	vector<Point> v(N);
	for (int i = 0; i < N; i++) {
		int x, y; scanf("%d%d", &x, &y);
		v[i] = Point(x, y);
	}
	sort(all(v));
	for (int i = 1; i < N; i++) {
		v[i].p = v[i].x - v[0].x;
		v[i].q = v[i].y - v[0].y;
	}
	sort(v.begin() + 1, v.end());

	vector<int> stk;
	stk.push_back(0);
	stk.push_back(1);
	int next = 2;
	while (next < N) {
		while (stk.size() >= 2) {
			int first, second;
			first = stk.back();
			stk.pop_back();
			second = stk.back();

			if (ccw(v[second], v[first], v[next]) > 0) {
				stk.push_back(first);
				break;
			}
		}
		stk.push_back(next++);
	}

	double ans = 0;
	for (int i = 0; i < stk.size(); i++) {
		if (i == stk.size() - 1)  {
			ans += dist(v[stk[i]], v[stk[0]]);
		}
		else {
			ans += dist(v[stk[i]], v[stk[i + 1]]);
		}
	}

	for (int i = 0; i < (int)stk.size() - 2; i++) {
		ans += L * (acos(-1) - angle(v[stk[i]], v[stk[i + 1]], v[stk[i + 2]]));
	}
	ans += L * (acos(-1) - angle(v[stk[stk.size() - 2]], v[stk[stk.size() - 1]], v[stk[0]]));
	ans += L * (acos(-1) - angle(v[stk[stk.size() - 1]], v[stk[0]], v[stk[1]]));

	printf("%.f", ans);
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
