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

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

void solve() {
	int N; cin >> N;
	ll A[51], B[51];
	for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

	ll L = 1;
	for (int i = 0; i < N; i++) L = lcm(L, B[i]);
	ll G = A[0] * L / B[0];
	for (int i = 1; i < N; i++) G = gcd(G, A[i] * L / B[i]);

	ll G2 = gcd(G, L);
	G /= G2;
	L /= G2;
	cout << G << ' ' << L << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if (0) {
		int T; cin >> T;
		while (T--) solve();
	}
	else {
		solve();
	}
	return 0;
}
