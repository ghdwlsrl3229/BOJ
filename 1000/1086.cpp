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

ll N, K;
vector<string> v;
vector<ll> v2;
ll tens[55];

ll cache[1 << 15][110];
ll dp(int bit, int mod) {
	if (bit == (1 << N) - 1) {
		if (mod == 0) return 1;
		return 0;
	}

	ll& ret = cache[bit][mod];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i < N; i++) {
		if (!(bit & (1 << i))) {
			ret += dp(bit | (1 << i), (mod * tens[v[i].size()] + v2[i]) % K);
		}
	}
	return ret;
}

void solve(int tc) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		v.push_back(s);
	}
	cin >> K;
	for (int i = 0; i < N; i++) {
		ll res = 0;
		for (int j = 0; j < v[i].size(); j++) {
			res *= 10;
			res += v[i][j] - '0';
			res %= K;
		}
		v2.push_back(res);
	}
	tens[0] = 1 % K;
	for (int i = 0; i <= 53; i++) tens[i + 1] = tens[i] * 10 % K;

	memset(cache, -1, sizeof(cache));
	ll num = dp(0, 0);
	ll den = 1;
	for (int i = 1; i <= N; i++) den *= i;
	
	if (num == 0) {
		cout << "0/1\n";
	}
	else {
		ll g = gcd(num, den);
		num /= g;
		den /= g;
		cout << num << "/" << den << '\n';
	}
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
