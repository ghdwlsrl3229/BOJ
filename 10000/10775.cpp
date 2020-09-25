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

int pa[110000];
int find(int n) {
	if (pa[n] < 0) return n;
	return pa[n] = find(pa[n]);
}
void merge(int a, int b) { //루트노드는 b로 한다.
	a = find(a);
	b = find(b);
	if (a == b) return;
	pa[a] = b;
}

void solve() {
	int G, P; cin >> G >> P;
	memset(pa, -1, sizeof(pa));
	int cnt = 0;
	for (int i = 0; i < P; i++) {
		int a; cin >> a;
		int pos = find(a);
		if (pos == 0) break;
		cnt++;
		merge(pos, find(pos - 1));
	}
	cout << cnt << '\n';
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
