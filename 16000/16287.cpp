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

int N, W;
int arr[220000];
bool Sum[1000000];

void solve() {
	cin >> W >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int s = arr[i] + arr[j];
			if (W > s && Sum[W - s]) {
				cout << "YES\n";
				return;
			}
		}

		for (int j = 0; j < i; j++) Sum[arr[i] + arr[j]] = 1;
	}
	cout << "NO\n";
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
