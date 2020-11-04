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
vector<pll> v;
//int dp[3300][3300];
int grundy(int y, int x) {
	return (x + y) % 3 + 3 * ((x / 3) ^ (y / 3));
}

void solve(int tc) {
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) cin >> v[i].fr >> v[i].sc;

	//for (int i = 0; i < 20; i++)
	//	for (int j = 0; j < 20; j++) {
	//		if (i == 0 && j == 0) continue;
	//		unordered_set<int> st;
	//		for (int k = 0; k < i; k++) {
	//			st.insert(dp[k][j]);
	//		}
	//		for (int k = 0; k < j; k++) {
	//			st.insert(dp[i][k]);
	//		}
	//		if (i - 1 >= 0 && j - 1 >= 0) {
	//			st.insert(dp[i - 1][j - 1]);
	//		}

	//		for (int k = 0;; k++) {
	//			if (st.count(k) == 0) {
	//				dp[i][j] = k;
	//				break;
	//			}
	//		}
	//	}

	//for (int i = 0; i < 20; i++) {
	//	for (int j = 0; j < 20; j++)
	//		cout << dp[i][j] << ' ';
	//	cout << '\n';
	//}

	int g = 0;
	for (pll i : v) g ^= grundy(i.fr, i.sc);
	if (g) cout << "koosaga\n";
	else cout << "cubelover\n";
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
