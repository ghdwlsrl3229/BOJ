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

struct SCC {
	int n, curID, sn;
	vector<vector<int> > adj, adj_DAG;
	vector<vector<int> > sccGroup;
	vector<int> id, sccID, inDegree, outDegree;
	stack<int> stk;

	SCC(int _n) :n(_n) { adj.resize(n + 1); }

	int SCC_traverse(int now) {
		int ret = id[now] = ++curID;
		stk.push(now);
		for (auto nxt : adj[now]) {
			// tree edge
			if (id[nxt] == 0)
				ret = min(ret, SCC_traverse(nxt));
			// back edge
			else if (sccID[nxt] == -1)
				ret = min(ret, id[nxt]);
		}
		if (ret == id[now]) {
			sccGroup.push_back(vector<int>());
			while (true) {
				int elem = stk.top(); stk.pop();
				sccID[elem] = sn;
				sccGroup[sn].push_back(elem);
				if (elem == now)break;
			}
			++sn;
		}
		return ret;
	}

	void SCC_run() {
		sn = curID = 0;
		id = vector<int>(n + 1, 0);
		sccID = vector<int>(n + 1, -1);
		// 0-based or 1-based
		for (int u = 1; u <= n; ++u)
			if (!id[u])SCC_traverse(u);
	}

	void SCC_componentDAG() {
		adj_DAG.resize(sn);
		inDegree.assign(n + 1, 0), outDegree.assign(n + 1, 0);
		// 0-based or 1-based
		for (int u = 1; u <= n; ++u)
			for (auto nxt : adj[u])
				if (sccID[u] != sccID[nxt])
					adj_DAG[sccID[u]].push_back(sccID[nxt]);
		// 0-based default
		for (int i = 0; i < sn; ++i) {
			sort(all(adj_DAG[i]));
			adj_DAG[i].erase(unique(all(adj_DAG[i])),
				adj_DAG[i].end());
		}
		// 0-based default
		for (int i = 0; i < sn; ++i) {
			for (auto nxt : adj_DAG[i]) {
				inDegree[nxt]++;
				outDegree[i]++;
			}
		}
	}

	void add(int a, int b) {
		adj[a].push_back(b);
	}
};

void solve() {
	int N, M, S, T; cin >> N >> M >> S >> T;

	SCC scc = SCC(N);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		scc.add(a, b);
	}

	scc.SCC_run();
	scc.SCC_componentDAG();

	//위상정렬 dp
	int dp[11000] = { 0 };
	bool visited[11000] = { 0 };
	dp[scc.sccID[S]] = scc.sccGroup[scc.sccID[S]].size();
	visited[scc.sccID[S]] = 1;
	for (int i = scc.sccID[S]; i >= 0; i--) {
		for (int j : scc.adj_DAG[i]) {
			if (visited[i]) {
				dp[j] = max(dp[j], dp[i] + (int)scc.sccGroup[j].size());
				visited[j] = 1;
			}
		}
	}
	cout << dp[scc.sccID[T]] << '\n';
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
