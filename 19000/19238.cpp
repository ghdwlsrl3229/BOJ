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

struct passenger {
	int sy, sx, ey, ex;
};

int N, M, energy;
int arr[22][22];
pll pos;
passenger pv[440];
int arrived_cnt;
bool arrived[440];

int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0, 0 };

bool drive() {
	bool visited[22][22];
	memset(visited, 0, sizeof(visited));
	queue<pll> q;
	q.push(pos);
	visited[pos.fr][pos.sc] = 1;

	int tmp[22][22];
	memset(tmp, -1, sizeof(tmp));
	for (int i = 0; i < M; i++)
		if (!arrived[i])
			tmp[pv[i].sy][pv[i].sx] = i;

	// 태울 승객 고르기
	int pnum = -1, pr = 1e9, pc = 1e9, cnt = 0;
	while (q.size()) {
		int qsz = q.size();
		bool find = 0;
		vector<pll> tmp2;
		while (qsz--) {
			pll cur = q.front();
			q.pop();
			if (tmp[cur.fr][cur.sc] != -1) {
				find = 1;
				tmp2.push_back(cur);
			}

			for (int i = 0; i < 4; i++) {
				int ny = cur.fr + dy[i];
				int nx = cur.sc + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				if (arr[ny][nx] == 1 || visited[ny][nx]) continue;
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}
		if (find) {
			sort(all(tmp2));
			pnum = tmp[tmp2[0].fr][tmp2[0].sc];
			break;
		}
		cnt++;
	}

	if (pnum == -1) return 0;
	energy -= cnt;
	pos = { pv[pnum].sy, pv[pnum].sx };

	// 승객 이동 시키기
	cnt = 0;
	memset(visited, 0, sizeof(visited));
	while (q.size()) q.pop();
	q.push({ pos.fr, pos.sc });
	visited[pos.fr][pos.sc] = 1;
	while (q.size()) {
		int qsz = q.size();
		while (qsz--) {
			pll cur = q.front();
			q.pop();
			if (cur.fr == pv[pnum].ey && cur.sc == pv[pnum].ex) {
				pos = cur;
				if (energy - cnt < 0) return 0;
				energy += cnt;
				arrived[pnum] = 1;
				arrived_cnt++;
				return 1;
			}

			for (int i = 0; i < 4; i++) {
				int ny = cur.fr + dy[i];
				int nx = cur.sc + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				if (arr[ny][nx] == 1 || visited[ny][nx]) continue;
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}
		cnt++;
	}

	return 0;
}

void solve(int tc) {
	cin >> N >> M >> energy;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	cin >> pos.fr >> pos.sc;
	pos.fr--, pos.sc--;
	for (int i = 0; i < M; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		a--, b--, c--, d--;
		pv[i] = { a, b, c, d };
	}

	while (1) {
		bool flag = drive();
		if (!flag) { //에너지가 부족하거나 벽으로 막혀서 도달못하는 경우
			cout << -1 << '\n';
			return;
		}
		if (arrived_cnt == M){
			cout << energy << '\n';
			return;
		}
	}
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
