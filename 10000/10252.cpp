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

void print_pair(int i, int j) {
	cout << '(' << i << ',' << j << ")\n";
}

void solve() {
	int m, n; cin >> m >> n;
	if (m == 1) {
		cout << 1 << "\n";
		for (int i = 0; i < n; i++) print_pair(0, i);
	}
	else {
		cout << 1 << "\n";
		print_pair(0, 0);
		for (int i = 1; i < n; i++) {
			if (i % 2 == 0)
				for (int j = m - 2; j >= 0; j--) print_pair(j, i);
			else
				for (int j = 0; j < m - 1; j++) print_pair(j, i);
		}
		for (int i = n - 1; i >= 1; i--) print_pair(m - 1, i);
		for (int i = m - 1; i > 0; i--) print_pair(i, 0);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
