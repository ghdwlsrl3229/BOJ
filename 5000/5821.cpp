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

ll R, L, B;
ll arr[110000];
ll psum[110000];

bool f(ll mid) {
	for (int i = 0; i <= R - mid; i++) {
		//[i, i + mid - 1] 범위를 모두 모은다.
		//항상 i + mid / 2로 모을 때가 최적이다.
		//[i, i + mid / 2], [i + mid/2 + 1, i + mid - 1] 범위로 쪼개서 생각한다.
		ll goal = arr[i + mid / 2]; 
		ll tmp = 0;
		tmp += goal * (mid / 2 + 1) - (psum[i + mid / 2 + 1] - psum[i]);
		tmp += (psum[i + mid] - psum[i + mid / 2 + 1]) - goal * (mid - mid / 2 - 1);
		if (tmp <= B) return 1;
	}
	return 0;
}

void solve() {
	cin >> R >> L >> B;
	for (int i = 0; i < R; i++) cin >> arr[i];
	for (int i = 0; i < R; i++) psum[i + 1] = psum[i] + arr[i];
	ll lo = 1, hi = R;
	while (lo < hi) {
		ll mid = (lo + hi + 1) / 2;
		if (f(mid)) lo = mid;
		else hi = mid - 1;
	}
	cout << lo << '\n';
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
