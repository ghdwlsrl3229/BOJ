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
deque<int> ans;

void solve(int tc) {
	cin >> N >> M >> K;
	int num = 1;
	for (int i = 1; i <= M; i++){
		ans.push_back(num++);
	}

	int rest = N - M;
	if (N - M < K - 1) {
		cout << -1 << '\n';
		return;
	}

	if (K != 1) {
		int w = (N - M) / (K - 1);
		int p = (N - M) % (K - 1);
		for (int i = 0; i < p; i++) {
			vector<int> tmp;
			for (int j = 0; j < w + 1; j++) {
				tmp.push_back(num++);
			}
			for (int j = tmp.size() - 1; j >= 0; j--) 
				ans.push_front(tmp[j]);
		}
		for (int i = 0; i < K - 1 - p; i++) {
			vector<int> tmp;
			for (int j = 0; j < w; j++) tmp.push_back(num++);
			for (int j = tmp.size() - 1; j >= 0; j--) ans.push_front(tmp[j]);
		}
	}

	if (ans.size() != N) {
		cout << -1 << '\n';
		return;
	}

	for (int i : ans) cout << i << ' ';
	cout << '\n';
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
