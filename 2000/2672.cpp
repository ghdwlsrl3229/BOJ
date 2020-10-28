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

vector<pll> v; //(x좌표, 상태)
vector<pll> segs;
set<int> st;

ll length() {
	if (st.empty()) return 0;

	vector<pll> v2;
	for (int i : st) v2.push_back(segs[i-1]);
	sort(all(v2));

	vector<pll> stk;
	stk.push_back(v2[0]);
	for (int i = 1; i < v2.size(); i++) {
		if (stk.back().sc >= v2[i].fr) stk.back().sc = max(stk.back().sc, v2[i].sc);
		else stk.push_back(v2[i]);
	}

	ll ret = 0;
	for (int i = 0; i < stk.size(); i++) ret += stk[i].sc - stk[i].fr;
	return ret;
}

void solve(int tc) {
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, c[4];
		for (int j = 0; j < 4; j++) {
			double b; cin >> b;
			c[j] = b * 10;
		}
		v.push_back({ c[0], i });
		v.push_back({ c[0] + c[2], -i });
		segs.push_back({ c[1], c[1] + c[3] });
	}
	sort(all(v));

	ll ans = 0, last = get<0>(v[0]);
	for (auto seg : v) {
		int x, s;
		tie(x, s) = seg;

		ll height = length();
		ans += height * (x - last);
		last = x;

		if (s > 0) {
			st.insert(s);
		}
		else {
			st.erase(-s);
		}
	}

	ll rest = ans % 100;
	ans /= 100;
	if (rest == 0) cout << ans << '\n';
	else if (rest < 10) cout << ans << ".0" << rest << '\n';
	else cout << ans << "." << rest << '\n';
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
