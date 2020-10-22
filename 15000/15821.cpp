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

int N, K;
ll arr[110000];

bool f(ll mid) {
	int cnt = 0;
	for (int i = 0; i < N; i++) 
		if (arr[i] <= mid) cnt++;
	return cnt >= K;
}

void solve(int tc) {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a; scanf("%d", &a);
		while (a--) {
			ll b, c; scanf("%lld%lld", &b, &c);
			arr[i] = max(arr[i], b*b+c*c);
		}
	}

	ll lo = 0, hi = 1e18;
	while(lo < hi) {
		ll mid = (lo + hi) / 2;
		if (f(mid)) hi = mid;
		else lo = mid + 1;
	}
	printf("%lld.00\n", hi);
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	if (0) {
		int T; cin >> T;
		for (int i = 1; i <= T; i++) solve(i);
	}
	else {
		solve(0);
	}
	return 0;
}
