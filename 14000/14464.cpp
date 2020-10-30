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

int C, N;
multiset<ll> chickens;
vector<ll> chicken;
vector<pll> cow;

void solve(int tc) {
	cin >> C >> N;
	chicken.resize(C);
	cow.resize(N);
	for (int i = 0; i < C; i++) {
		cin >> chicken[i];
		chickens.insert(chicken[i]);
	}
	for (int i = 0; i < N; i++) cin >> cow[i].fr >> cow[i].sc;

	sort(all(chicken));
	sort(all(cow), [](const pll& a, const pll& b) {
		if (a.sc == b.sc) return a.fr < b.fr;
		return a.sc < b.sc;
	});

	int cnt = 0;
	for (int i = 0; i < cow.size(); i++) {
		auto iter = chickens.lower_bound(cow[i].fr);
		if (iter != chickens.end() && *iter <= cow[i].sc) chickens.erase(iter), cnt++;
	}
	cout << cnt << '\n';
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
