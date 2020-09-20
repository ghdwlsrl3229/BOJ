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

const int MAX = 5e5 + 10;
struct Segtree {
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

Segtree st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N; cin >> N;
	vector<tuple<int, int, int>> v(N);
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		get<0>(v[a - 1]) = N - i;
	}
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		get<1>(v[a - 1]) = N - i;
	}
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		get<2>(v[a - 1]) = N - i;
	}

	sort(all(v));

	int cnt = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (st.query(get<1>(v[i]), MAX) < get<2>(v[i])) cnt++;
		st.modify(get<1>(v[i]), get<2>(v[i]));
	}

	cout << cnt << '\n';
	return 0;
}
