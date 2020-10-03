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

const int MAX = 550 * 550;
const int INF = 1e9;

int A[MAX], B[MAX];
vector<int> adj[MAX];
bool visited[MAX];

bool dfs(int a) {
	visited[a] = 1;
	for (int b : adj[a]) {
		if (B[b] == -1 || !visited[B[b]] && dfs(B[b])) {
			A[a] = b;
			B[b] = a;
			return 1;
		}
	}
	return 0;
}

vector<tuple<int, int, string>> garo;
vector<tuple<int, int, string>> sero;

void solve() {
	garo.clear(), sero.clear();
	for (int i = 0; i < MAX; i++) adj[i].clear();

	int H, V; cin >> H >> V; //가로, 세로
	for (int i = 0; i < H; i++) {
		int x, y; string s;
		cin >> x >> y >> s;
		garo.push_back({ x, y, s });
	}
	for (int i = 0; i < V; i++) {
		int x, y; string s;
		cin >> x >> y >> s;
		sero.push_back({ x, y, s });
	}

	for (int i = 0; i < H; i++)
		for (int j = 0; j < V; j++) {
			string s1 = get<2>(sero[j]), s2 = get<2>(garo[i]);
			int x1 = get<0>(sero[j]), x2 = get<0>(garo[i]);
			int y1 = get<1>(sero[j]), y2 = get<1>(garo[i]);

			int idx2 = x1 - x2, idx1 = y2 - y1;
			if (idx2 < 0 || idx1 < 0 || idx2 >= (int)s2.size() || idx1 >= (int)s1.size()) continue;
			if (s1[idx1] != s2[idx2]) {
				adj[i].push_back(j);
			}
		}

	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		if (A[i] == -1) {
			memset(visited, 0, sizeof(visited));
			if (dfs(i)) cnt++;
		}
	}
	cout << H + V - cnt << '\n';
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
