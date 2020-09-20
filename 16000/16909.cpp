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
struct MaxSegtree {
	pll t[2 * MAX];
	void build() {
		for (int i = MAX - 1; i > 0; i--)
			t[i] = max(t[i << 1], t[i << 1 | 1]);
	}
	pll query(int l, int r) {
		pll ret = { 0, 0 };
		for (l += MAX, r += MAX; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ret = max(ret, t[l++]);
			if (r & 1) ret = max(ret, t[--r]);
		}
		return ret;
	}
};

struct MinSegtree {
	pll t[2 * MAX];
	void build() {
		for (int i = MAX - 1; i > 0; i--)
			t[i] = min(t[i << 1], t[i << 1 | 1]);
	}
	pll query(int l, int r) {
		pll ret = { 2e18, 0 };
		for (l += MAX, r += MAX; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ret = min(ret, t[l++]);
			if (r & 1) ret = min(ret, t[--r]);
		}
		return ret;
	}
};

MaxSegtree mxst;
MinSegtree mnst;
int N;
int cards[1100000];

ll ans = 0;
void f(int le, int ri) {
	pll mx = mxst.query(le, ri + 1);
	ans += mx.fr * (mx.sc - le + 1) * (ri - mx.sc + 1);

	if (le == ri) return;

	if (le != mx.sc) f(le, mx.sc - 1);
	if (ri != mx.sc) f(mx.sc + 1, ri);
}

void f2(int le, int ri) {
	pll mn = mnst.query(le, ri + 1);
	ans -= mn.fr * (mn.sc - le + 1) * (ri - mn.sc + 1);

	if (le == ri) return;

	if (le != mn.sc) f2(le, mn.sc - 1);
	if (ri != mn.sc) f2(mn.sc + 1, ri);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> cards[i];
	for (int i = 0; i < N; i++) mxst.t[MAX + i] = mnst.t[MAX + i] = pll(cards[i], i);
	mxst.build(); mnst.build();

	f(0, N - 1);
	f2(0, N - 1);

	cout << ans << '\n';
	return 0;
}
