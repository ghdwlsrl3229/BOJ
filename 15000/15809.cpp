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
int pa[1100000];
ll sz[1100000];
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

void solve(int tc) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> sz[i];

	memset(pa, -1, sizeof(pa));
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		b--, c--;
		if (a == 1) {
			merge(b, c);
		}
		else {
			ll bsz = sz[find(b)], csz = sz[find(c)];
			merge(b, c);
			if (bsz > csz) {
				sz[find(b)] = bsz - csz;
			}
			else {
				sz[find(b)] = csz - bsz;
			}
		}
	}

	vector<ll> ans;
	for (int i = 0; i < N; i++) {
		if (pa[i] == -1) {
			if (sz[i]) ans.push_back(sz[i]);
		}
	}
	sort(all(ans));
	cout << ans.size() << '\n';
	for (ll i : ans) cout << i << ' ';
	cout << '\n';
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
