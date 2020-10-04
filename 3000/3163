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

void solve() {
	ll N, L, K; cin >> N >> L >> K;
	vector<pll> neg_dir, pos_dir; //(위치, 아이디)
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		if (b > 0) pos_dir.push_back({ a, b });
		else neg_dir.push_back({ a, b });
	}

	vector<pll> times; //(떨어지는 시점, 아이디)
	for (int i = 0; i < neg_dir.size(); i++) {
		int left = lower_bound(all(pos_dir), pll(neg_dir[i].fr, -1e9)) - pos_dir.begin();
		int right = neg_dir.size() - i - 1;

		if (left <= right) { //<-
			ll right_end = neg_dir[i + left].fr;
			times.push_back({ right_end, neg_dir[i].sc });
		}
		else { //->
			ll left_end = pos_dir[left - right - 1].fr;
			times.push_back({ L - left_end, neg_dir[i].sc });
		}
	}

	for (int i = 0; i < pos_dir.size(); i++) {
		int left = i;
		int right = neg_dir.end() - upper_bound(all(neg_dir), pll(pos_dir[i].fr, -1e9));

		if (left < right) { //<-
			ll right_end = (upper_bound(all(neg_dir), pll(pos_dir[i].fr, -1e9)) + left) -> first;
			times.push_back({ right_end, pos_dir[i].sc });
		}
		else { //->
			ll left_end = pos_dir[left - right].fr;
			times.push_back({ L - left_end, pos_dir[i].sc });
		}
	}

	sort(all(times));
	cout << times[K - 1].sc << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
