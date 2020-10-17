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

int N;
char town[55][55];
int height[55][55];
int dy[] = {0, 0, -1, 1, 1, 1, -1, -1 };
int dx[] = {-1, 1, 0, 0, 1, -1, 1, -1 };
vector<pll> house;
int py, px;

bool f(int mx, int mn){
	bool visited[55][55];
	queue<pll> q;
	memset(visited, 0, sizeof(visited));
	if (mn <= height[py][px] && height[py][px] <= mx) {
		q.push({ py, px });
		visited[py][px] = 1;
	}

	while (q.size()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = cur.fr + dy[i];
			int nx = cur.sc + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (mn > height[ny][nx] || height[ny][nx] > mx) continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}

	for (pll i : house) if (!visited[i.fr][i.sc]) return 0;
	return 1;
}

void solve(int tc) {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> town[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (town[i][j] == 'P') py = i, px = j;
			if (town[i][j] == 'K') house.push_back({ i, j });
		}

	vector<int> hv;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> height[i][j];
			hv.push_back(height[i][j]);
		}

	sort(all(hv));
	hv.erase(unique(all(hv)), hv.end());

	int ans = 1e9;
	int lo = 0;
	for (int hi = 0; hi < hv.size(); hi++) {
		while (lo < hi && f(hv[hi], hv[lo + 1])) lo++;
		if (f(hv[hi], hv[lo])) ans = min(ans, hv[hi] - hv[lo]);
	}

	cout << ans << '\n';
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
