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

int N, M;
int arr[330];

bool f(int mid) {
	int cnt = 1, sum = 0;
	for (int i = 0; i < N; i++) {
		if (sum + arr[i] <= mid) {
			sum += arr[i];
		}
		else if (arr[i] <= mid) {
			sum = arr[i];
			cnt++;
		}
		else return 0;
	}
	return cnt <= M;
}

void solve(int tc) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int lo = 0, hi = 30000;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (f(mid)) hi = mid;
		else lo = mid + 1;
	}
	cout << hi << '\n';

	vector<int> ans;
	int cnt = 0, sum = 0;
	ans.clear();
	for (int i = 0; i < N; i++) {
		if (sum + arr[i] <= hi) {
			sum += arr[i];
			cnt++;
		}
		else {
			ans.push_back(cnt);
			sum = arr[i];
			cnt = 1;
		}
	}
	ans.push_back(cnt);

	int need = M - ans.size();
	vector<int> ans2;
	for (int i = 0; i < ans.size();) {
		if (need && ans[i] > 1) {
			need--;
			ans[i]--;
			ans2.push_back(1);
		}
		else {
			ans2.push_back(ans[i++]);
		}
	}

	for (int i : ans2) cout << i << ' ';
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
