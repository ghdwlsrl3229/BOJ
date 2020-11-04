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

void solve(int tc) {
	int N; cin >> N;

	ll g = 0;
	for (int i = 0; i < N; i++) {
		ll a; cin >> a;
		g ^= a;
	}
	if (g) cout << "cubelover\n";
	else cout << "koosaga\n";
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
