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

int ccw(pll a, pll b, pll c) {
	int op = a.first*b.second + b.first*c.second + c.first*a.second;
	op -= (a.second*b.first + b.second*c.first + c.second*a.first);
	if (op > 0)return 1;
	else if (op == 0)return 0;
	else return -1;
}

int isIntersect(pair<pll, pll> x, pair<pll, pll> y) {
	pll a = x.first, b = x.second, c = y.first, d = y.second;
	int ab = ccw(a, b, c)*ccw(a, b, d);
	int cd = ccw(c, d, a)*ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b)swap(a, b);
		if (c > d)swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

void solve() {
	int xmin, ymin, xmax, ymax;
	cin >> xmin >> ymin >> xmax >> ymax;
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	
	//사각형 점 4개
	pair<pll, pll> l[4] = { 
		{{xmin, ymax}, {xmax, ymax}}, 
		{{xmax, ymax}, {xmax, ymin}}, 
		{{xmin, ymin}, {xmax, ymin}}, 
		{{xmin, ymax}, {xmin, ymin}}, 
	};
	pair<pll, pll> l2 = { {x1, y1}, {x2, y2} };

	//만나지 않는 경우 
	bool intersect = 0;
	for (int i = 0; i < 4; i++)
		if (isIntersect(l[i], l2)) intersect = 1;
	if (!intersect) {
		cout << 0 << '\n';
		return;
	}

	//교점이 무한히 많은 경우
	if (x1 == x2) {
		if (x1 == xmin || x1 == xmax) {
			if (!(min(y1, y2) >= ymax || max(y1, y2) <= ymin)) {
				cout << 4 << '\n';
				return;
			}
		}
	}
	if (y1 == y2) {
		if (y1 == ymin || y1 == ymax) {
			if (!(min(x1, x2) >= xmax || max(x1, x2) <= xmin)) {
				cout << 4 << '\n';
				return;
			}
		}
	}

	//꼭짓점을 지나는 경우 & 변을 지나는 경우
	int point_cnt = 0,line_cnt = 0;
	for (int i = 0; i < 4; i++) {
		pll a = l2.fr, b = l2.sc, c = l[i].fr, d = l[i].sc;
		if (ccw(a, b, c) * ccw(a, b, d) == 0 && ccw(c, d, a) * ccw(c, d, b) <= 0) point_cnt++;
		else if (isIntersect(l2, l[i])) line_cnt++;
	}
	cout << point_cnt / 2 + line_cnt << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
