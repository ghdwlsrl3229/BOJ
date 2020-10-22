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

int S, T;
vector<int> adj[110000];
int pa[110000];
vector<int> ans;

int block, prvS;
void dfs(int nd, int prv = -1, int dep = 0) {
	if (block == nd || prvS == nd) return;
	if (dep % 2 == 0) ans.push_back(nd);
	for (int nxt : adj[nd]) {
		if (nxt == prv) continue;
		dfs(nxt, nd, dep + 1);
	}
	if (dep % 2 == 1) ans.push_back(nd);
}

void dfs2(int nd, int prv = -1, int dep = 0) {
	if (block == nd || prvS == nd) return;
	if (dep % 2 == 1) ans.push_back(nd);
	for (int nxt : adj[nd]) {
		if (nxt == prv) continue;
		dfs2(nxt, nd, dep + 1);
	}
	if (dep % 2 == 0) ans.push_back(nd);
}

void make_tree(int nd, int prv = -1) {
	if (nd == block || prvS == nd) return;
	pa[nd] = prv;
	for (int nxt : adj[nd]) {
		if (nxt == prv) continue;
		make_tree(nxt, nd);
	}
}

void solve() {
	int N; cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> S >> T;
	make_tree(S);

	int pos = T;
	vector<int> tmp;
	while (1) {
		if (pos == S) break;
		tmp.push_back(pos);
		pos = pa[pos];
	}

	reverse(all(tmp));
	for (int i : tmp){
		block = i;
		dfs(S);
		prvS = S;
		S = block;
	}
	block = 0;
	dfs2(S);

	for (int i : ans) cout << i << '\n';
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
