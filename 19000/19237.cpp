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

int N, M, K;
int arr[22][22];
bool die[440]; //i번 상어가 쫓겨났는지 여부 체크
pll pos[440]; //1-based, i번 상어의 위치를 (y, x) 형태로 저장
pll smell[22][22]; //(i, j)위치에 남아있는 냄새의 (상어번호, 기록 시각)을 저장
int priority[440][4][4]; //(i, j, k) 상어 i가 j를 바라보고 있을 때 우선순위
int dir[440]; //i번 상어의 현재 방향
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void shark_move(int t) {
	//오래된 냄새 제거
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (smell[i][j].sc <= t - K)
				smell[i][j] = { 0, 0 };

	//상어 냄새 뿌리기
	for (int i = 1; i <= M; i++) if (!die[i]) smell[pos[i].fr][pos[i].sc] = { i, t };

	//이동할 칸 정해서 이동하기
	for (int i = 1; i <= M; i++) {
		if (die[i]) continue;
		//1. 아무 냄새가 없는 칸의 방향을 찾는다.
		vector<int> tmp;
		for (int j = 0; j < 4; j++) {
			int ny = pos[i].fr + dy[j];
			int nx = pos[i].sc + dx[j];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (smell[ny][nx].fr == 0) tmp.push_back(j);
		}
		if (tmp.empty()) {
			//2. 자신의 냄새가 있는 칸의 방향을 찾는다.
			for (int j = 0; j < 4; j++) {
				int ny = pos[i].fr + dy[j];
				int nx = pos[i].sc + dx[j];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				if (smell[ny][nx].fr == i) tmp.push_back(j);
			}
		}

		//3. 갈 수 있는 칸이 존재한다면 우선순위를 따름
		if (tmp.size()) {
			bool flag = 0;
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < tmp.size(); k++) {
					if (tmp[k] == priority[i][dir[i]][j]) {
						dir[i] = tmp[k];
						pos[i] = { pos[i].fr + dy[dir[i]], pos[i].sc + dx[dir[i]] };
						flag = 1;
						break;
					}
				}
				if (flag) break;
			}
		}
	}

	//상어 내쫓기
	memset(arr, 0, sizeof(arr));
	for (int i = 1; i <= M; i++) {
		if (die[i]) continue;
		if (arr[pos[i].fr][pos[i].sc] == 0) arr[pos[i].fr][pos[i].sc] = i;
		else die[i] = 1;
	}
}

bool check() {
	for (int i = 2; i <= M; i++) if (!die[i]) return 0;
	return 1;
}

void solve(int tc) {
	cin >> N >> M >> K;
	for (int i =0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			pos[arr[i][j]] = { i, j };
		}

	for (int i = 1; i <= M; i++) {
		cin >> dir[i]; dir[i]--;
	}

	for (int i = 1; i <= M; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++) {
				cin >> priority[i][j][k];
				priority[i][j][k]--;
			}
			
	for (int i = 1;; i++) {
		shark_move(i);
		if (i > 1000) {
			cout << -1 << '\n';
			return;
		}
		if (check()) {
			cout << i << '\n';
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
