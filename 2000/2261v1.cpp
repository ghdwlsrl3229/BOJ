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
vector<pll> v;

ll dist(pll a, pll b) {
	return (a.fr - b.fr) * (a.fr - b.fr) + (a.sc - b.sc) * (a.sc - b.sc);
}

ll f(int le, int ri) {
	if (le == ri) return 1e18;
	if (le + 1 == ri) return dist(v[le], v[ri]);
	int mid = (le + ri) / 2;
	ll d1 = f(le, mid);
	ll d2 = f(mid + 1, ri);
	ll d = min(d1, d2);

	vector<pll> p;
	for (int i = le; i <= ri; i++) 
		if (v[mid].fr - d <= v[i].fr && v[i].fr <= v[mid].fr + d) 
			p.push_back(v[i]);
	
	sort(all(p), [](const pll& a, const pll& b) {
		if (a.sc == b.sc) return a.fr < b.fr;
		return a.sc < b.sc;
	});

	for (int i = 0; i < p.size(); i++)
		for (int j = i + 1; j < p.size(); j++) {
			if ((p[j].sc - p[i].sc) * (p[j].sc - p[i].sc) >= d) break;
			d = min(d, dist(p[i], p[j]));
		}

	return d;
}

void solve(int tc) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(all(v));

	cout << f(0, N - 1) << '\n';
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
