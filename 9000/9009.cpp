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

ll fibo[50];

void solve() {
	ll n; cin >> n;
	vector<ll> ans;
	while (n) {
		for (int i = 49; i >= 0; i--) {
			if (n >= fibo[i]) {
				n -= fibo[i];
				ans.push_back(fibo[i]);
				break;
			}
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	fibo[0] = 1, fibo[1] = 1;
	for (int i = 2; i < 50; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];

	int T; cin >> T;
	while (T--) solve();
	return 0;
}
