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

ll pa[1100];
ll e[1100];
int find(int n) {
	if (pa[n] < 0) return n;
	return pa[n] = find(pa[n]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	pa[b] += pa[a];
	pa[a] = b;
}

void solve() {
	int n; cin >> n;
	vector<tuple<int, int, int>> edges;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int a; cin >> a;
			edges.push_back({ a, i, j });
		}
	}
	sort(all(edges));
	memset(pa, -1, sizeof(pa));
	memset(e, 0, sizeof(e));

	int ans = 0;
	for (int i = 0; i < edges.size(); ) {
		int val = get<0>(edges[i]);
		vector<int> updated;
		for (; i < edges.size(); i++) {
			if (get<0>(edges[i]) != val) break;
			int u = get<1>(edges[i]), v = get<2>(edges[i]);

			//간선 개수 갱신
			if (find(u) != find(v)) e[find(v)] += e[find(u)] + 1;
			else e[find(v)]++;
			merge(u, v);
			updated.push_back(find(u));
		}

		//완전 그래프 체크
		for (int &i : updated) i = find(i);
		sort(all(updated));
		updated.erase(unique(all(updated)), updated.end());
		for (int i : updated) {
			ll sz = -pa[i];
			if (e[i] == sz * (sz - 1) / 2 && sz != n) ans++;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) solve();
//	solve();
	return 0;
}
