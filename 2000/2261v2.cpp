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

struct cmp {
	bool operator()(const pll& a, const pll& b) const {
		if (a.sc == b.sc) return a.fr < b.fr;
		else return a.sc < b.sc;
	}
};

ll dist(pll a, pll b) {
	return (a.fr - b.fr) * (a.fr - b.fr) + (a.sc - b.sc) * (a.sc - b.sc);
}

void solve(int tc) {
	int N; cin >> N;
	vector<pll> v;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(all(v));

	set<pll, cmp> st;
	st.insert(v[0]);
	st.insert(v[1]);
	ll d = dist(v[0], v[1]);
	for (int i = 2, j = 0; i < N; i++) {
		for (; j < i; j++) {
			if (d <= (v[j].fr - v[i].fr) * (v[j].fr - v[i].fr)) {
				st.erase(v[j]);
			}
			else break;
		}
		
		ll d2 = (int)sqrt(d) + 1;
		auto lb = st.lower_bound(pll(-1e5, v[i].sc - d2));
		auto ub = st.upper_bound(pll(1e5, v[i].sc + d2));
		for (auto iter = lb; iter != ub; iter++) {
			d = min(d, dist(v[i], *iter));
		}
		st.insert(v[i]);
	}
	cout << d << '\n';
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
