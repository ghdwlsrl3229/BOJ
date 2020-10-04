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

const int MAX = 1e6 + 1;
struct Segtree {
	ll t[2 * MAX];
	void build() {
		for (int i = MAX - 1; i > 0; i--)
			t[i] = min(t[i << 1], t[i << 1 | 1]);
	}
	void modify(int p, ll value) {
		for (t[p += MAX] = value; p > 1; p >>= 1)
			t[p >> 1] = min(t[p], t[p ^ 1]);
	}
	ll query(int l, int r) {
		ll ret = 1e18;
		for (l += MAX, r += MAX; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ret = min(ret, t[l++]);
			if (r & 1) ret = min(ret, t[--r]);
		}
		return ret;
	}
};

Segtree xst, yst;
vector<int> xs, ys;
vector<tuple<int, int, int, int, int>> ships;
vector<pll> query;

int yidx(int val) {
	return lower_bound(all(ys), val) - ys.begin();
}
int xidx(int val) {
	return lower_bound(all(xs), val) - xs.begin();
}

void solve() {
	int n, k, l; cin >> n >> k >> l;
	xs.clear(); ys.clear(); ships.clear(); query.clear();
	for (int i = 0; i < k; i++) {
		int x, y, x2, y2, w;
		cin >> x >> y >> x2 >> y2 >> w;
		ships.push_back({ x, y, x2 ,y2 ,w });
		xs.push_back(x); xs.push_back(x2);
		ys.push_back(y); ys.push_back(y2);
	}
	for (int i = 0; i < l; i++) {
		int a, b; cin >> a >> b;
		query.push_back({ a, b });
		if (b == 0) ys.push_back(a);
		else xs.push_back(a);
	}

	sort(all(xs)); sort(all(ys));
	xs.erase(unique(all(xs)), xs.end());
	ys.erase(unique(all(ys)), ys.end());

	for (int i = 0; i <= xs.size(); i++) xst.t[MAX + i] = 1e18;
	for (int i = 0; i <= ys.size(); i++) yst.t[MAX + i] = 1e18;
	xst.build(), yst.build();

	for (int i = 0; i < query.size(); i++) {
		if (query[i].sc == 0) {
			int idx = yidx(query[i].fr);
			if (yst.t[MAX + idx] == 1e18) yst.modify(idx, i);
		}
		else {
			int idx = xidx(query[i].fr);
			if (xst.t[MAX + idx] == 1e18) xst.modify(idx, i);
		}
	}

	vector<int> heaviest(query.size());
	for (int i = 0; i < ships.size(); i++) {
		int x, y, x2, y2, w;
		tie(x, y, x2, y2, w) = ships[i];
		if (x > x2) swap(x, x2);
		if (y > y2) swap(y, y2);
		ll q = min(xst.query(xidx(x), xidx(x2) + 1), yst.query(yidx(y), yidx(y2) + 1));

		if (q == 1e18) continue;
		heaviest[q] = max(heaviest[q], w);
	}
	for (int i = 0; i < l; i++) cout << heaviest[i] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
