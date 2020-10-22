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

//level : 1-based, kth : 0-based
int nodenum(int level, int kth) {
	int base = (1 << level) - 2;
	return base + kth;
}

int k;
int arr[4400000];
int max_len;
int dp[4400000];

void dfs(int level, int kth, int sum) {
	if (level == k + 1) return;
	
	int now = nodenum(level, kth);
	int child1 = nodenum(level + 1, 2 * kth);
	int child2 = nodenum(level + 1, 2 * kth + 1);

	dfs(level + 1, 2 * kth, sum + arr[child1]);
	dfs(level + 1, 2 * kth + 1, sum + arr[child2]);

	if (level == k + 1) dp[now] = arr[now];
	else {
		dp[now] = arr[now] + max(dp[child1], dp[child2]);
	}
}

void dfs2(int level, int kth, int sum) {
	if (level == k + 1) return;

	int now = nodenum(level, kth);
	arr[now] += sum - dp[now];
	dfs2(level + 1, 2 * kth, sum - arr[now]);
	dfs2(level + 1, 2 * kth + 1, sum - arr[now]);
}

void solve() {
	cin >> k;
	int n = (1 << (k + 1)) - 2;
	for (int i = 0; i < n; i++) cin >> arr[i];

	dfs(0, 0, 0);
	max_len = *max_element(dp, dp + n + 1);
	dfs2(1, 0, max_len);
	dfs2(1, 1, max_len);

	cout << accumulate(arr, arr + n + 1, 0LL) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
