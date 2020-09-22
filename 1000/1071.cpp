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

const int MAX_V = 440;
const int INF = 1e9;

int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V];
vector<int> adj[MAX_V];

void solve() {
	int N; cin >> N;
	map<int, int> mp;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		mp[a]++;
	}

	vector<int> v;
	for (int i = 0; i < N; i++) {
		int tmp = -1;
		for (auto j : mp) {
			if (v.empty() || j.fr != v.back() + 1) {
				tmp = j.fr;
				break;
			}
		}
		if (tmp != -1) {
			if (--mp[tmp] == 0) mp.erase(tmp);
			v.push_back(tmp);
		}
	}

	if (mp.size()) {
		vector<int> tmp;
		while (v.size() && mp.begin()->first == v.back() + 1) {
			tmp.push_back(v.back());
			v.pop_back();
		}
		for (auto i : mp) {
			for (int j = 0; j < i.second; j++)
				v.push_back(i.first);
		}
		for (int i : tmp) v.push_back(i);
	}

	for (int i : v) cout << i << ' ';
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
