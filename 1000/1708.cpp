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

void solve() {
	int N; cin >> N;
	vector<Point> v(N);
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		v[i] = Point(x, y);
	}

	sort(all(v));

	for (int i = 0; i < N; i++) {
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

	cout << stk.size() << '\n';
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
