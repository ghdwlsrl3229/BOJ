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

int n, a;
vector<ll> t, psum;

ll cache[110][110][2];
ll dp(int le, int ri, int pos) {
	if (le == 0 && ri == n - 1) return 0;

	ll& ret = cache[le][ri][pos];
	if (ret != -1) return ret;
	
	ret = 2e18;
	int now = pos == 0 ? le : ri;
	int remain = n - ri + le - 1;

	if (le > 0) ret = min(ret, dp(le - 1, ri, 0) + remain * (psum[now] - psum[le - 1]));
	if (ri < n - 1) ret = min(ret, dp(le, ri + 1, 1) + remain * (psum[ri + 1] - psum[now]));
	return ret;
}

void solve() {
	cin >> n >> a;
	a--;
	t.resize(n - 1), psum.resize(n);
	psum[0] = 0;
	for (int i = 0; i < n - 1; i++) {
		cin >> t[i];
		psum[i + 1] = psum[i] + t[i];
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cache[i][j][0] = cache[i][j][1] = -1;
	cout << dp(a, a, 0) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
