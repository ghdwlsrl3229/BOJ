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

int N, K, R;
set<pair<pll, pll>> st;
vector<pll> cow;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

bool visited[110][110];
void bfs(pll s) {
	memset(visited, 0, sizeof(visited));
	queue<pll> q;
	q.push(s);
	visited[s.fr][s.sc] = 1;
	while (q.size()) {
		pll cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.fr + dy[i];
			int nx = cur.sc + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (visited[ny][nx]) continue;
			if (st.find({ cur, {ny, nx} }) != st.end()) continue;
			q.push({ ny,nx });
			visited[ny][nx] = 1;
		}
	}
}

void solve(int tc) {
	cin >> N >> K >> R;
	for (int i = 0; i < R; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		a--, b--, c--, d--;
		st.insert({ {a, b}, {c, d} });
		st.insert({ {c, d}, {a, b} });
	}
	for (int i = 0; i < K; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		cow.push_back({ a, b });
	}
	ll cnt = 0;
	for (int i = 0; i < K; i++) {
		bfs(cow[i]);
		for (int j = i + 1; j < K; j++) {
			if (!visited[cow[j].fr][cow[j].sc]) cnt++;
		}
	}
	cout << cnt << '\n';
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
