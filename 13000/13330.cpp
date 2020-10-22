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

int n, k, l; 
char arr[11000];
int cache1[11000][11000];
int cache2[11000];
int dp1(int le, int ri) { //구간 [le, ri]의 문자열에서 u의 최댓값을 리턴한다.
	if (le >= ri || arr[le] != arr[ri]) return 0;
	int& ret = cache1[le][ri];
	if (ret != -1) return ret;

	return ret = dp1(le + 1, ri - 1) + 1;
}

int dp2(int pos) { //구간 [0, pos]에서 만들 수 있는 세타 펠린드롬의 최소 개수
	if (pos == 0) return 1e9;

	int& ret = cache2[pos];
	if (ret != -1) return ret;
	
	ret = 1e9;
	if (k * (pos + 1) <= 2 * l * dp1(0, pos)) return ret = 1;

	for (int i = 1; i <= pos; i++) {
		if (k * (pos - i + 1) <= 2 * l * dp1(i, pos)) {
			if (dp2(i - 1) != 1e9)
				ret = min(ret, dp2(i - 1) + 1);
		}
	}
	return ret;
}

void solve() {
	cin >> n >> k >> l;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	memset(cache1, -1, sizeof(cache1));
	memset(cache2, -1, sizeof(cache2));
	int ans = dp2(n - 1);
	if (ans >= 1e9) cout << 0 << '\n';
	else cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
//	int T; cin >> T;
//	while (T--) solve();
	solve();
	return 0;
}
