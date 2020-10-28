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

int N, M;
int dist[220][220];
int maxdist[220][220];

int f(int s) {
	int ret = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (maxdist[i][j]) {
				int a = dist[s][i];
				int b = dist[s][j];
				if (a < b) swap(a, b);
				if (a - b >= maxdist[i][j]) ret = max(ret, 2*a);
				else {
					ret = max(ret, 2 * b + maxdist[i][j] + a - b);
				}
			}

	return ret;
}

void solve(int tc) {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (i != j) dist[i][j] = 1e9;
		}
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = min(dist[b][a], c);
		maxdist[a][b] = max(maxdist[a][b], c);
		maxdist[b][a] = max(maxdist[b][a], c);
	}

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];

	int ans = 1e9; //답의 2배
	for (int i = 0; i < N; i++) {
		ans = min(ans, f(i));
	}

	if (ans % 2 == 0) {
		cout << ans / 2 << ".0\n";
	}
	else {
		cout << ans / 2 << ".5\n";
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
