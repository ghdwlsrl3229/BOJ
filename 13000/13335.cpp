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
	int n, w, L; cin >> n >> w >> L;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	deque<pll> dq;
	int weight = 0;
	for (int t = 1, i = 0;; t++) {
		if (dq.size() && dq.front().sc + w == t) {
			weight -= dq.front().fr;
			dq.pop_front();
		}
		if (i < n && weight + v[i] <= L && dq.size() < w) 
			weight += v[i], dq.push_back({ v[i++], t });
		if (i == n && dq.empty()) {
			cout << t << '\n';
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
