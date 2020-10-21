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

const int MAX = 1e5 + 1;
struct Segtree {
	ll t[2 * MAX];
	void build() {
		for (int i = MAX - 1; i > 0; i--)
			t[i] = max(t[i << 1], t[i << 1 | 1]);
	}
	void modify(int p, ll value) {
		for (t[p += MAX] += value; p > 1; p >>= 1)
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

int N, Q;
int arr[110000];
int ans[110000];
int sqrtN;

struct query {
	int id, s, e;
	bool operator < (const query& a) {
		if (s / sqrtN != a.s / sqrtN) return s / sqrtN < a.s / sqrtN;
		return e < a.e;
	}
};

vector<query> v;
Segtree st;

void solve(int tc) {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sqrtN = sqrt(N);

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		v.push_back({ i, a, b });
	}
	sort(all(v));

	int s = v[0].s, e = v[0].e;
	for (int i = s; i <= e; i++) {
		st.modify(arr[i], 1);
	}
	ans[v[0].id] = st.query(0, MAX);

	for (int i = 1; i < Q; i++) {
		while (s < v[i].s) {
			st.modify(arr[s++], -1);
		}
		while (s > v[i].s) {
			st.modify(arr[--s], 1);
		}
		while (e < v[i].e) {
			st.modify(arr[++e], 1);
		}
		while (e > v[i].e) {
			st.modify(arr[e--], -1);
		}
		ans[v[i].id] = st.query(0, MAX);
	}

	for (int i = 0; i < Q; i++) cout << ans[i] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if (0) {
		int T; cin >> T;
		for (int i = 1; i <= T; i++) solve(i);
	}
	else {
		solve(0);
	}
	return 0;
}
