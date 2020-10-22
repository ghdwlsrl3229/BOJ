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
vector<int> v1, v2;
ll cache[2200][2200];

ll error(ll a, ll b) {
	return (a - b)*(a - b);
}

ll dp(int pos1, int pos2) {
	if (pos1 == N && pos2 == N) return 0;
	ll& ret = cache[pos1][pos2];
	if (ret != -1) return ret;

	ret = 1e18;
	if (pos1 < N && pos2 < N) {
		ret = min(ret, dp(pos1 + 1, pos2 + 1) + error(v1[pos1], v2[pos2]));
		ret = min(ret, dp(pos1 + 1, pos2) + error(v1[pos1], v2[pos2]));
		ret = min(ret, dp(pos1, pos2 + 1) + error(v1[pos1], v2[pos2]));
	}
	return ret;
}

void solve(int tc) {
	cin >> N;
	v1.resize(N), v2.resize(N);
	for (int i = 0; i < N; i++) cin >> v1[i];
	for (int i = 0; i < N; i++) cin >> v2[i];
	memset(cache, -1, sizeof(cache));
	cout << dp(0, 0) << '\n';
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
