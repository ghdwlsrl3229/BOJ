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

ll N, T;
ll arr[22000];

ll sum; //k가 1일때 실행 시간
ll diff[550000]; //버퍼의 크기에 따른 시간 변화
bool chk[550000]; //카운팅 소트

void solve(int tc) {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> T;

	for (int i = 0; i < N; i++) sum += arr[i];
	
	for (int i = 0; i < N; i++) {
		int F = arr[i];
		int sqrtF = sqrt(F) + 1;

		vector<ll> v2;
		for (int j = 1; j <= sqrtF; j++) v2.push_back(j);	
		for (int j = sqrtF - 1; j >= 1; j--) v2.push_back((F + j - 1) / j);

		ll last = arr[i];
		for (int j : v2) {
			chk[j] = 1;
			ll newsum = (arr[i] + j - 1) / j;
			diff[j] += newsum - last;
			last = newsum;
		}
	}

	vector<ll> v;
	for (int i = 0; i <= 500000; i++) 
		if (chk[i]) v.push_back(i);

	ll ans = 1e18, minf = 1e18;
	for (ll i : v) {
		sum += diff[i];

		ll res = sum * (i + T);
		if (ans >= res) {
			if (ans > res) {
				ans = res;
				minf = i;
			}
			else {
				minf = min(minf, i);
			}
		}
	}
	cout << ans << ' ' << minf << '\n';
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
