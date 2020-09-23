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
int arr[110];
vector<int> v[110];

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];

	for (int i = 0; i < N; i++) {
		bool flag = 0;
		for (int j = 0; j < K; j++) {
			if (v[j].empty() || v[j].back() < arr[i]) {
				v[j].push_back(arr[i]);
				flag = 1;
				break;
			}
		}
		if (!flag) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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
