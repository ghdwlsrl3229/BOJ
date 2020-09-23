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
int cards[1100];
int cache[1100][1100][2];
//근우 - 명우 를 최대로 한다.
int dp(int le, int ri, int turn) { 
	if (le == ri) {
		if (turn == 0) return cards[le];
		else return -cards[le];
	}
	int& ret = cache[le][ri][turn];
	if (ret != -1) return ret;

	if (turn == 0)
		ret = max(dp(le + 1, ri, 1) + cards[le], dp(le, ri - 1, 1) + cards[ri]);
	else
		ret = min(dp(le + 1, ri, 0) - cards[le], dp(le, ri - 1, 0) - cards[ri]);
	return ret;
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> cards[i];

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cache[i][j][0] = cache[i][j][1] = -1;
	int diff = dp(0, N - 1, 0);
	int sum = 0;
	for (int i = 0; i < N; i++) sum += cards[i];

	cout << (diff + sum) / 2 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
