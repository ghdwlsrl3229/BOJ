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
int mp, mf, ms, mv;
int arr[15][5];
int ans;
vector<int> ansv;

void dfs(int pos, int p, int f, int s, int v, int c, vector<int> vv) {
	if (pos == N) {
		if (p >= mp && f >= mf && s >= ms && v >= mv) {
			if (ans >= c) {
				if (ans == c) ansv = min(ansv, vv);
				else {
					ansv = vv;
					ans = c;
				}
			}
		}
		return;
	}

	dfs(pos + 1, p, f, s, v, c , vv);
	int np = arr[pos][0], nf = arr[pos][1], ns = arr[pos][2];
	int nv = arr[pos][3], nc = arr[pos][4];
	vv.push_back(pos + 1);
	dfs(pos + 1, p + np, f + nf, s + ns, v + nv, c + nc, vv);
}

void solve() {
	cin >> N >> mp >> mf >> ms >> mv;
	for (int i = 0; i < N; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4];
	}
	ans = 1e9;
	dfs(0, 0, 0, 0, 0, 0, {});
	if (ans == 1e9) cout << -1 << '\n';
	else {
		cout << ans << '\n';
		for (int i : ansv) cout << i << ' ';
	}
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
