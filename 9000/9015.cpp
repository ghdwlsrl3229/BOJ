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

inline ll pll2num(pll a) {
	return (a.fr + 10000) * 20001 + (a.sc + 10000);
}

void solve() {
	int N; cin >> N;
	vector<pll> v(N);
	unordered_set<ll> st;
	for (int i = 0; i < N; i++) {
		cin >> v[i].fr >> v[i].sc;
		st.insert(pll2num(v[i]));
	}

	ll ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++) {
			pll vec = { v[i].fr - v[j].fr, v[i].sc - v[j].sc };
			//경우1
			pll p1 = { v[i].fr + vec.sc, v[i].sc - vec.fr };
			pll p2 = { p1.fr - vec.fr, p1.sc - vec.sc };
			if (st.count(pll2num(p1)) && st.count(pll2num(p2)))
				ans = max(ans, vec.fr * vec.fr + vec.sc * vec.sc);

			//경우2
			pll p3 = { v[i].fr - vec.sc, v[i].sc + vec.fr };
			pll p4 = { p3.fr - vec.fr, p3.sc - vec.sc };
			if (st.count(pll2num(p3)) && st.count(pll2num(p4)))
				ans = max(ans, vec.fr * vec.fr + vec.sc * vec.sc);
		}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) solve();
	return 0;
}
