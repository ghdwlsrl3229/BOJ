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
vector<int> xs[110000]; //xs[x] : x좌표가 x인 y좌표 모음
int ys[110000]; //ys[y] : y좌표가 y인 점의 개수

void solve(int tc) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		xs[a].push_back(b);
		ys[b]++;
	}

	ll cnt = 0;
	for (int i = 1; i <= 100000; i++) { //x 고정
		for (int j : xs[i]) { //y고정
			cnt += (xs[i].size() - 1) * (ys[j] - 1);
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
