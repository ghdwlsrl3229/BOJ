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

//0은 시작, 1은 도착, 총 33개 노드
int go[40]; 
int cost[40]; 
map<int, int> blue;
int dice[10];
int ans;

void init() {
	go[0] = 2;
	for (int i = 2; i <= 9; i++) if (i != 6) go[i] = i + 1;
	go[6] = 11;
	for (int i = 11; i <= 16; i++) if (i != 15) go[i] = i + 1;
	go[17] = 10; go[15] = 21;
	for (int i = 21; i <= 27; i++) if (i != 25) go[i] = i + 1;
	go[28] = 10; go[25] = 29;
	for (int i = 29; i <= 31; i++) go[i] = i + 1;
	go[10] = 18; go[18] = 19; go[19] = 20;
	go[32] = 20; go[20] = 1; go[1] = 1;
	int tmp[] = { 0, 0, 2, 4, 6, 8, 10, 13, 16, 19,
		25, 12, 14, 16, 18, 20, 22, 24, 30, 35,
		40, 22, 24, 26, 28, 30, 28, 27, 26, 32,
		34, 36, 38};
	for (int i = 0; i <= 32; i++) cost[i] = tmp[i];
	blue[6] = 7;
	blue[15] = 16;
	blue[25] = 26;
}

void dfs(int n, vector<int> p, int score) {
//	cout << n << ' ' << score << '\n';
	if (n == 10) {
		ans = max(ans, score);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int pos = p[i];
		if (pos == 1) continue;

		if (pos == 6 || pos == 15 || pos == 25) {
			pos = blue[pos];
			for (int i = 0; i < dice[n] - 1; i++) pos = go[pos];
		}
		else for (int i = 0; i < dice[n]; i++) pos = go[pos];	

		vector<int> tmp = p;
		bool flag = 1;
		for (int j = 0; j < 4; j++) if (pos != 1 && i != j && p[j] == pos) flag = 0;
		if (flag) {
			tmp[i] = pos;
			dfs(n + 1, tmp, score + cost[pos]);
		}
	}
}

void solve(int tc) {
	for (int i = 0; i < 10; i++) cin >> dice[i];
	init();
	dfs(0, { 0, 0, 0, 0 }, 0);
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
