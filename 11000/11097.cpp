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
	int N; cin >> N;
	char cango[330][330];
	for (int i = 0; i < N; i++) cin >> cango[i];

	SCC scc(N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (cango[i][j] == '1' && i != j) {
				scc.add(i + 1, j + 1);
			}

	scc.SCC_run();
	scc.SCC_componentDAG();

	vector<pll> ans;
	bool graph[330][330];
	memset(graph, 0, sizeof(graph));
	for (int i = 0; i < scc.sn; i++) {
		for (int j : scc.adj_DAG[i]) graph[i][j] = 1;
	}
	for (int k = 0; k < scc.sn; k++)
		for (int i = 0; i < scc.sn; i++)
			for (int j = 0; j < scc.sn; j++)
				graph[i][j] |= graph[i][k] && graph[k][j];

	for (int i = 0; i < scc.sn; i++) {
		for (int j : scc.adj_DAG[i]) {
			bool flag = 1;
			for (int k = 0; k < scc.sn; k++)
				if (graph[i][k] && graph[k][j]) {
					flag = 0;
					break;
				}
			if (flag) ans.push_back({ scc.sccGroup[i][0], scc.sccGroup[j][0] });
		}
	}

	for (auto v : scc.sccGroup) {
		if (v.size() == 1) continue;
		for (int i = 0; i < v.size() - 1; i++)
			ans.push_back({ v[i], v[i + 1] });
		ans.push_back({ v.back(), v[0] });
	}

	cout << ans.size() << '\n';
	for (auto i : ans) cout << i.fr << ' ' << i.sc << '\n';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if (1) {
		int T; cin >> T;
		while (T--) solve();
	}
	else {
		solve();
	}
	return 0;
}
