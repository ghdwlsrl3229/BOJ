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

int N;
int sy, ex;
vector<pair<ll, pll>> v;
set<pll> st; //(y좌표, y방향 이동 거리)

void solve(int tc) {
	cin >> N;
	cin >> sy >> ex;
	for (int i = 0; i < N; i++) {
		int x, yh, yl;
		cin >> x >> yl >> yh;
		v.push_back({ x, {yl ,yh} });
	}
	sort(all(v));

	st.insert({ sy, 0 });
	for (int i = 0; i < N; i++) {
		int x = v[i].fr, yl = v[i].sc.fr, yh = v[i].sc.sc;
		auto il = st.lower_bound(pll(yl, 0));
		auto ih = st.upper_bound(pll(yh, 1e18));
		vector<pll> tmp;

		ll distl = 1e18, disth = 1e18;
		for (auto iter = il; iter != ih; iter++) {
			tmp.push_back(*iter);
			distl = min(distl, iter->second + abs(yl - iter->first));
			disth = min(disth, iter->second + abs(yh - iter->first));
		}
		for (int i = 0; i < tmp.size(); i++) {
			st.erase(tmp[i]);
		}
		if (distl != 1e18) st.insert({ yl, distl });
		if (disth != 1e18) st.insert({ yh, disth });
	}

	ll sp = 1e18;
	for (auto iter = st.begin(); iter != st.end(); iter++) {
		sp = min(sp, iter->second);
	}

	vector<ll> ans;
	for (auto iter = st.begin(); iter != st.end(); iter++) {
		if (iter->second == sp) ans.push_back(iter->first);
	}

	cout << sp + ex << '\n';
	cout << ans.size() << ' ';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
	cout << '\n';
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
