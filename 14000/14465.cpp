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

int N, K, B;
bool broken[110000];
int psum[110000];

void solve(int tc) {
	cin >> N >> K >> B;
	for (int i = 0; i < B; i++) {
		int a; cin >> a;
		broken[a - 1] = 1;
	}
	for (int i = 1; i <= N; i++) psum[i] = psum[i - 1] + broken[i - 1];

	int ans = 1e9;
	for (int i = 0; i <= N - K; i++) {
		ans = min(ans, psum[i + K] - psum[i]);
	}
	cout << ans << '\n';
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
