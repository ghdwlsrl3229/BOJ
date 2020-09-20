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
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (v[i] > v[j]) cnt++;
	cout << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) solve();
//	solve();
	return 0;
}
