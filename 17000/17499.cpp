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

int N, Q;
ll arr[220000];

void solve() {
	cin >> N >> Q;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int pos0 = 0;
	while (Q--) {
		int q; cin >> q;
		if (q == 1) {
			int i, x; cin >> i >> x;
			i--;
			arr[(pos0 + i) % N] += x;
		}
		else if (q == 2) {
			int s; cin >> s;
			pos0 = (pos0 - s + N) % N;
		}
		else {
			int s; cin >> s;
			pos0 = (pos0 + s) % N;
		}
	}
	for (int i = pos0; i < N; i++) cout << arr[i] << ' ';
	for (int i = 0; i < pos0; i++) cout << arr[i] << ' ';
	cout << '\n';
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
