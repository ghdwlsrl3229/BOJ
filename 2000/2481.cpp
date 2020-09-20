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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin >> n >> k;
	map<ll, ll> mp;
	vector<ll> v;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int a = 0;
		for (int i = 0; i < k; i++) if (s[i] == '1') a += 1 << i;
		mp[a] = i;
		v.push_back(a);
	}

	queue<pll> q;
	bool visited[110000] = { 0 };
	int prev[110000];
	memset(prev, -1, sizeof(prev));
	
	visited[0] = 1;
	q.push({ 0, -1 });

	while (q.size()) {
		int idx = q.front().first;
		int prv = q.front().second;
		q.pop();
		prev[idx] = prv;

		for (int i = 0; i < k; i++) {
			ll tmp = v[idx] ^ (1 << i);
			if (mp.find(tmp) != mp.end()) {
				if (visited[mp[tmp]]) continue;
				visited[mp[tmp]] = 1;
				q.push({ mp[tmp], idx });
			}
		}
	}

	int m; cin >> m;
	while (m--) {
		int query; cin >> query;
		query--;
		if (prev[query] == -1) cout << -1 << '\n';
		else {
			vector<int> ans;
			while (query != -1) {
				ans.push_back(query);
				query = prev[query];
			}
			for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] + 1 << ' ';
			cout << '\n';
		}
	}

	return 0;
}
