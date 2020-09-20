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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll N, L; cin >> N >> L;
	ll total_weight = 0;
	vector<ll> pdir, ndir; //(x);
	deque<tuple<int, int, int>> cows; //(x, w, dir)
	for (int i = 0; i < N; i++) {
		int a, b, c; cin >> a >> b >> c;
		cows.push_back({ b, a, c }); 
		total_weight += a;
		if (c == 1) pdir.push_back(b);
		else ndir.push_back(b);
	}

	sort(all(pdir)); sort(all(ndir));
	sort(all(cows));

	vector<pll> times;
	for (int i = 0; i < N; i++) {
		if (get<2>(cows[i]) == 1) times.push_back({ L - get<0>(cows[i]), 1 });
		else times.push_back({ get<0>(cows[i]), -1 });
	}

	sort(all(times));

	ll holdtime = 0, weight = 0;
	for (int i = 0; i < N; i++) {
		holdtime = times[i].fr;
		if (times[i].sc == -1) {
			weight += get<1>(cows.front());
			cows.pop_front();
		}
		else {
			weight += get<1>(cows.back());
			cows.pop_back();
		}
		if (weight * 2 >= total_weight) break;
	}

	ll cnt = 0;
	for (int i = 0; i < pdir.size(); i++) {
		cnt += upper_bound(all(ndir), pdir[i] + 2 * holdtime) - lower_bound(all(ndir), pdir[i]);
	}
	cout << cnt << '\n';

	return 0;
}
