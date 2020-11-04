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
int dp[1100];

void solve(int tc) {
	cin >> N;
	for (int i = 2; i <= N; i++) {
		unordered_set<int> st;
		for (int j = 0; j <= i - 2; j++) {
			st.insert(dp[i - j - 2] ^ dp[j]);
		}
		for (int j = 0;; j++) {
			if (st.count(j) == 0) {
				dp[i] = j;
				break;
			}
		}
	}

	if (dp[N]) cout << 1 << '\n';
	else cout << 2 << '\n';
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
