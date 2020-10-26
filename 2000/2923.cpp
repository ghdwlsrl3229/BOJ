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

int acnt[110], bcnt[110];

int f() {
	int atmp[110], btmp[110];
	for (int i = 1; i <= 100; i++) atmp[i] = acnt[i], btmp[i] = bcnt[i];

	int ret = 0;
	for (int i = 1, j = 100; i <= 100; i++) {
		if (acnt[i] == 0) continue;

		while (acnt[i] != 0) {
			if (bcnt[j] == 0) {
				j--;
				continue;
			}
			ret = max(ret, i + j);

			if (acnt[i] <= bcnt[j]) {
				bcnt[j] -= acnt[i];
				acnt[i] = 0;
				break;
			}
			else acnt[i] -= bcnt[j--];
		}
	}

	for (int i = 1; i <= 100; i++) acnt[i] = atmp[i], bcnt[i] = btmp[i];
	return ret;
}

void solve(int tc) {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		acnt[a]++;
		bcnt[b]++;
		cout << f() << '\n';
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
