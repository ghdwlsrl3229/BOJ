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


const int MAX = 1e5 + 5;
struct MaxSegtree {
	ll t[2 * MAX];
	void build() {
		for (int i = MAX - 1; i > 0; i--)
			t[i] = max(t[i << 1], t[i << 1 | 1]);
	}
	void modify(int p, ll value) {
		for (t[p += MAX] = value; p > 1; p >>= 1)
			t[p >> 1] = max(t[p], t[p ^ 1]);
	}
	ll query(int l, int r) {
		ll ret = 0;
		for (l += MAX, r += MAX; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ret = max(ret, t[l++]);
			if (r & 1) ret = max(ret, t[--r]);
		}
		return ret;
	}
};

struct MinSegtree {
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
		ll ret = 2e18;
		for (l += MAX, r += MAX; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ret = min(ret, t[l++]);
			if (r & 1) ret = min(ret, t[--r]);
		}
		return ret;
	}
};

MaxSegtree mxst;
MinSegtree mnst;

void solve() {
	ll n, l; cin >> n >> l;
	vector<ll> leftend(n), rightend(n), order(n);
	for (int i = 0; i < n; i++) {
		cin >> leftend[i];
		rightend[i] = leftend[i] + l;
	}
	for (int i = 0; i < n; i++) cin >> order[i];

	vector<pll> v(n);
	for (int i = 0; i < n; i++) {
		int le = lower_bound(all(rightend), leftend[i]) - rightend.begin();
		int ri = upper_bound(all(leftend), rightend[i]) - leftend.begin() - 1;
		v[i] = { le + 1, ri + 1 };
//		cout << le + 1 << ' ' << ri + 1 << '\n';
	}

	for (int i = 0; i < n; i++) {
		mxst.t[order[i] + MAX] = i;
		mnst.t[order[i] + MAX] = i;
	}
	mxst.build();
	mnst.build();

	int ans = 1;
	for (int i = 0; i < n; i++) {
		if (mxst.query(v[i].fr, v[i].sc + 1) - mnst.query(v[i].fr, v[i].sc + 1) != v[i].sc - v[i].fr) ans = -1;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) solve();
//	solve();
	return 0;
}
