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

const int INF = 1e9;
int N, M, T;
deque<int> dq[55];

void rotate(int x, int d, int k) {
	for (int i = x; i <= N; i += x) {
		if (d == 0) {
			for (int j = 0; j < k; j++) {
				dq[i].push_front(dq[i].back());
				dq[i].pop_back();
			}
		}
		else {
			for (int j = 0; j < k; j++) {
				dq[i].push_back(dq[i].front());
				dq[i].pop_front();
			}
		}
	}
}

vector<pll> adj(int i, int j) { //인접한 좌표 리스트를 반환
	vector<pll> ret;

	if (j == 0) {
		ret.push_back({ i, 1 });
		ret.push_back({ i, M - 1 });
	}
	if (j == M - 1) {
		ret.push_back({ i, M - 2 });
		ret.push_back({ i, 0 });
	}
	if (1 <= j && j <= M - 2) {
		ret.push_back({ i, j - 1 });
		ret.push_back({ i, j + 1 });
	}
	if (i == 1) ret.push_back({ 2, j });
	if (i == N) ret.push_back({ N - 1, j });
	if (2 <= i && i <= N - 1) {
		ret.push_back({ i - 1, j });
		ret.push_back({ i + 1, j });
	}

	return ret;
}

void op() {
	set<pll> st;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < M; j++) {
			vector<pll> adjs = adj(i, j);
			for (pll k : adjs) {
				if (dq[i][j] != INF && dq[i][j] == dq[k.fr][k.sc])
					st.insert({ i, j }), st.insert(k);
			}
		}
	if (st.size()) {
		for (pll i : st) dq[i.fr][i.sc] = INF;
	}
	else {
		int sum = 0, cnt = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 0; j < M; j++)
				if (dq[i][j] != INF) sum += dq[i][j], cnt++;
		for (int i = 1; i <= N; i++)
			for (int j = 0; j < M; j++) {
				if (dq[i][j] == INF) continue;
				if (sum < cnt * dq[i][j]) dq[i][j]--;
				else if (sum > cnt * dq[i][j]) dq[i][j]++;
			}
	}
}

void solve(int tc) {
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		dq[i].resize(M);
		for (int j = 0; j < M; j++) cin >> dq[i][j];
	}
	for (int i = 0; i < T; i++) {
		int x, d, k; cin >> x >> d >> k;
		rotate(x, d, k);
		op();
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < M; j++)
			if (dq[i][j] != INF) ans += dq[i][j];
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
