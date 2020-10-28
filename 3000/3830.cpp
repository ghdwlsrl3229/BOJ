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
	else return pa[n] = find(pa[n]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	pa[a] = b;
}

vector<pll> adj[110000];
ll diff[110000];

void dfs(int nd, int prv = -1, int sum = 0) {
	diff[nd] = sum;
	for (auto nxt : adj[nd]) {
		if (nxt.fr == prv) continue;
		dfs(nxt.fr, nd, sum + nxt.sc);
	}
}

void solve(int tc) {
	while (1) {
		int N, M; cin >> N >> M;
		if (N == 0 && M == 0) break;

		for (int i = 1; i <= N; i++) {
			pa[i] = -1;
			adj[i].clear();
			diff[i] = 1e9;
		}
		vector<pll> query;
		vector<int> ans;

		for (int i = 0; i < M; i++) {
			char ch; cin >> ch;
			if (ch == '!') {
				int a, b, c; cin >> a >> b >> c;
				if (find(a) != find(b)) {
					adj[a].push_back({ b, c });
					adj[b].push_back({ a, -c });
					merge(a, b);
				}
			}
			else {
				int a, b; cin >> a >> b;
				query.push_back({ a, b });
				if (find(a) != find(b)) ans.push_back(1e9);
				else ans.push_back(0);
			}
		}

		for (int i = 1; i <= N; i++) {
			if (diff[i] == 1e9) {
				diff[i] = 0;
				dfs(i);
			}
		}

		for (int i = 0; i < query.size(); i++) {
			if (ans[i] != 1e9) {
				ans[i] = diff[query[i].sc] - diff[query[i].fr];
				cout << ans[i] << '\n';
			}
			else cout << "UNKNOWN\n";
		}
	}
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
