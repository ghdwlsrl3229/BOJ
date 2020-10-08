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
	vector<vector<int> > adj, adj_DAG, radj_DAG;
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
		radj_DAG.resize(sn);
		inDegree.assign(n + 1, 0), outDegree.assign(n + 1, 0);
		// 0-based or 1-based
		for (int u = 1; u <= n; ++u)
			for (auto nxt : adj[u])
				if (sccID[u] != sccID[nxt]) {
					adj_DAG[sccID[u]].push_back(sccID[nxt]);
					radj_DAG[sccID[nxt]].push_back(sccID[u]);
				}
		// 0-based default
		for (int i = 0; i < sn; ++i) {
			sort(all(adj_DAG[i]));
			adj_DAG[i].erase(unique(all(adj_DAG[i])), adj_DAG[i].end());
			sort(all(radj_DAG[i]));
			radj_DAG[i].erase(unique(all(radj_DAG[i])), radj_DAG[i].end());
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

int ncnt = 1;
map<string, int> mp;
map<int, string> mp2;
set<pll> st;

int wordNum(string s) {
	if (mp.find(s) == mp.end()) {
		mp2[ncnt] = s;
		mp[s] = ncnt++;
		return ncnt - 1;
	}
	return mp[s];
}

void solve() {
	while (1) {
		int N; cin >> N;
		if (N == 0) return;

		ncnt = 1;
		mp.clear();
		mp2.clear();
		st.clear();

		SCC scc(N);

		for (int i = 0; i < N; i++) {
			char s[30]; scanf("%s", s);
			int c = wordNum(string(s));
			while (1) {
				char a[30]; char b;
				scanf("%s%c", a, &b);

				int d = wordNum(string(a));
				if (st.find({ d, c }) == st.end()) {
					st.insert({ d, c });
					scc.add(d, c);
				}
				if (b != ' ') break;
			}
		}

		scc.SCC_run();
		scc.SCC_componentDAG();

		vector<string> v;
		bool need[110] = { 0 };
		for (int i = 0; i < scc.sn; i++) {
			if (scc.sccGroup[i].size() > 1) need[i] = 1;
		}

		for (int k = 0; k < scc.sn; k++)
			for (int i = 0; i < scc.sn; i++)
				if (need[i])
					for (int j : scc.radj_DAG[i]) need[j] = 1;

		for (int i = 0; i < scc.sn; i++) if (need[i]) {
			for (int j : scc.sccGroup[i])
				v.push_back(mp2[j]);
		}

		sort(all(v));
		cout << v.size() << '\n';
		for (string i : v) cout << i << ' ';
		cout << '\n';
	}
}

int main() {
	//	ios::sync_with_stdio(false);
	//	cin.tie(0);
	if (0) {
		int T; cin >> T;
		while (T--) solve();
	}
	else {
		solve();
	}
	return 0;
}
