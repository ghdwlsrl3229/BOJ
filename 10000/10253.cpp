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

void solve() {
	ll a, b; cin >> a >> b;
	while (a != 1) {
		ll c = (b + a - 1) / a;
		ll aa = a * c - b, bb = b * c;
		a = aa / gcd(aa, bb);
		b = bb / gcd(aa, bb);
	}
	cout << b << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
