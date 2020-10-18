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

int M, N, P;
char arr[1100][1100];
bool visited[1100][1100];
int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0, 0 };
int dps[26];
pll pos[26];
int dist[26];
int hp;
pll Bpos;

void bfs(int s) {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			visited[i][j] = 0;

	queue<pll> q;
	q.push(pos[s]);
	visited[pos[s].fr][pos[s].sc] = 1;

	int cnt = 0;
	while (q.size()) {
		int qsz = q.size();
		while (qsz--) {
			int y, x;
			tie(y, x) = q.front();
			q.pop();

			if (y == Bpos.fr && x == Bpos.sc) {
				dist[s] = cnt;
				return;
			}

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
				if (visited[ny][nx]) continue;
				if (arr[ny][nx] == 'X') continue;
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}
		cnt++;
	}
}

void solve() {
	cin >> M >> N >> P;
	for (int i = 0; i < M; i++) cin >> arr[i];
	for (int i = 0; i < P; i++) {
		char ch; int a;
		cin >> ch >> a;
		dps[ch - 'a'] = a;
	}
	cin >> hp;

	vector<int> id;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			if ('a' <= arr[i][j] && arr[i][j] <= 'z') 
				pos[arr[i][j] - 'a'] = { i, j }, id.push_back(arr[i][j] - 'a');
			if (arr[i][j] == 'B') Bpos = { i, j };
		}

	for (int i = 0; i < P; i++) bfs(id[i]);

	vector<pll> player;
	for (int i = 0; i < P; i++) 
		player.push_back({ dist[id[i]], dps[id[i]] });

	sort(all(player));

	int ans = 1;
	ll damage_sum = player[0].sc;
	for (int i = 1; i < P; i++) {
		ll gap = player[i].fr - player[i - 1].fr;
		hp -= gap * damage_sum;
		damage_sum += player[i].sc;
		if (hp <= 0) break;
		ans++;
	}
	cout << ans << "\n";
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
