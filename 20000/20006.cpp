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

map<string, int> levels;
int cnt;
bool full[330];
vector<vector<string>> v;

void solve() {
	int p, m; cin >> p >> m;
	for (int i = 0; i < p; i++) {
		int level; string id;
		cin >> level >> id;
		levels[id] = level;

		bool flag = 1;
		for (int i = 0; i < cnt; i++) {
			if (levels[v[i][0]] - 10 <= level && level <= levels[v[i][0]] + 10 && !full[i]) {
				v[i].push_back(id);
				flag = 0;
				if (v[i].size() == m) full[i] = 1;
				break;
			}
		}

		if (flag) {
			vector<string> tmp;
			tmp.push_back(id);
			v.push_back(tmp);
			if (m == 1) full[cnt] = 1;
			cnt++;
		}
	}

	for (int i = 0; i < cnt; i++) {
		sort(all(v[i]));
		if (v[i].size() == m) cout << "Started!\n";
		else cout << "Waiting!\n";

		for (int j = 0; j < v[i].size(); j++)
			cout << levels[v[i][j]] << ' ' << v[i][j] << '\n';
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
