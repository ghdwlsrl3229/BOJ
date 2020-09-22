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

int R, C;
int arr[1100][1100];

void solve() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> arr[i][j];

	if (R % 2 == 1) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C - 1; j++) {
				if (i % 2 == 0) cout << 'R';
				else cout << 'L';
			}
			if (i != R - 1) cout << 'D';
		}
	}
	else if (C % 2 == 1) {
		for (int i = 0; i < C; i++) {
			for (int j = 0; j < R - 1; j++) {
				if (i % 2 == 0) cout << 'D';
				else cout << 'U';
			}
			if (i != C - 1) cout << 'R';
		}
	}
	else {
		int mny, mnx, mn = 1e9;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if ((i + j) % 2 == 1 && arr[i][j] < mn) {
					mny = i, mnx = j, mn = arr[i][j];
				}

		vector<char> sv, ev;

		if (mny == 0) {
			for (int i = R - 1; i != mny + 1; i--) {
				if (i % 2 == 1) {
					for (int j = 0; j < C - 1; j++) ev.push_back('L');
					ev.push_back('U');
				}
				else {
					for (int j = 0; j < C - 1; j++) ev.push_back('R');
					ev.push_back('U');
				}
			}

			int y = 1;
			for (int i = C - 1; i >= 0; i--) {
				if (y == 1) {
					if (i != mnx) ev.push_back('U'), y = 0;
				}
				else {
					ev.push_back('D'), y = 1;
				}

				if (i == 0) break;
				ev.push_back('L');
			}
		}
		else {
			for (int i = R - 1; i != mny; i--) {
				if (i % 2 == 1) {
					for (int j = 0; j < C - 1; j++) ev.push_back('L');
					ev.push_back('U');
				}
				else {
					for (int j = 0; j < C - 1; j++) ev.push_back('R');
					ev.push_back('U');
				}
			}
			for (int i = 0; i < mny - 1; i++) {
				if (i % 2 == 0) {
					for (int j = 0; j < C - 1; j++) sv.push_back('R');
					sv.push_back('D');
				}
				else{
					for (int j = 0; j < C - 1; j++) sv.push_back('L');
					sv.push_back('D');
				}
			}

			if (mny % 2 == 0) {
				int y = mny;
				for (int i = 0; i < C; i++) {
					if (y == mny) {
						ev.push_back('U'), y--;
					}
					else {
						if (mnx != i) ev.push_back('D'), y++;
					}
					if (i == C - 1) break;
					ev.push_back('R');
				}
			}
			else {
				int y = mny - 1;
				for (int i = 0; i < C; i++) {
					if (y == mny) {
						sv.push_back('U'), y--;
					}
					else {
						if (mnx != i) sv.push_back('D'), y++;
					}
					if (i == C - 1) break;
					sv.push_back('R');
				}
			}
		}

		for (char i : sv) cout << i;
		reverse(all(ev));
		for (char i : ev) {
			if (i == 'U') cout << 'D';
			if (i == 'D') cout << 'U';
			if (i == 'R') cout << 'L';
			if (i == 'L') cout << 'R';
		}
	}
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
