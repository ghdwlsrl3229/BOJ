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
int sz[110000];
int find(int n) {
	if (pa[n] < 0) return n;
	else return pa[n] = find(pa[n]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	sz[b] += sz[a];
	pa[a] = b;
}

int cost[110000];
bool visited[110000];
vector<pll> v;

void solve() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
		sz[i] = 1;
		v.push_back({ cost[i], i });
	}
	sort(all(v), greater<pll>());

	ll ans = 0;
	memset(pa, -1, sizeof(pa));
	for (int i = 0; i < N; i++) {
		int w = v[i].fr;
		int idx = v[i].sc;
		visited[idx] = 1;

		int prv = max(idx - 1, 0);
		int nxt = min(idx + 1, N - 1);
		if (visited[prv]) merge(idx, prv);
		if (visited[nxt]) merge(idx, nxt);

		ans = max(ans, 1LL * sz[find(idx)] * w);
	}
	cout << ans << "\n";
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
