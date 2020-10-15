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

int N, K; 
int board[15][15];
vector<int> token[15][15]; //쌓인 순서
pll pos[15]; //(y, x)
int dir[15];

//오 왼 위 아래
int revdir[] = { 1, 0, 3, 2 };
int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1, -1, 0, 0 };

void move(int k) {
	vector<int> grp;
	bool flag = 0;
	for (int i : token[pos[k].fr][pos[k].sc]) {
		if (i == k) flag = 1;
		if (flag) {
			grp.push_back(i);
			token[pos[k].fr][pos[k].sc].pop_back();
		}
	}
	int ny = pos[k].fr + dy[dir[k]];
	int nx = pos[k].sc + dx[dir[k]];

	if (ny < 0 || nx < 0 || ny >= N || nx >= N || board[ny][nx] == 2) {
		dir[k] = revdir[dir[k]];
		ny = pos[k].fr + dy[dir[k]];
		nx = pos[k].sc + dx[dir[k]];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N || board[ny][nx] == 2) {
			for (int i : grp) {
				token[pos[k].fr][pos[k].sc].push_back(i);
			}
			return;
		}
	}
	
	if (board[ny][nx] == 0) {
		for (int i : grp) {
			pos[i] = { ny, nx };
			token[ny][nx].push_back(i);
		}
	}
	else if (board[ny][nx] == 1) {
		for (int i = grp.size() - 1; i >= 0; i--) {
			pos[grp[i]] = { ny, nx };
			token[ny][nx].push_back(grp[i]);
		}
	}
}

bool check() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (token[i][j].size() >= 4) 
				return 1;
	return 0;
}

void solve(int tc) {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	for (int i = 0; i < K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--, c--;
		pos[i] = { a, b };
		dir[i] = c;
		token[a][b].push_back(i);
	}
	for (int i = 1;; i++)
		for (int j = 0; j < K; j++) {
			move(j);
			if (check()) {
				cout << i << '\n';
				return;
			}
			if (i > 1000) {
				cout << -1 << '\n';
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
