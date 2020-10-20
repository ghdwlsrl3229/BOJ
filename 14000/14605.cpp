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
pair<pll, ll> arr[110];
int ccw(pll a, pll b, pll c) {
	if (a.fr * (b.sc - c.sc) - a.sc * (b.fr - c.fr) + b.fr * c.sc - c.fr * b.sc < 0)
		return 0;
	return 1;
}

void solve(int tc) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b; string s;
		cin >> a >> b >> s;
		if (s == "LOVELYZ") arr[i] = { {a, b}, 1 };
		else arr[i] = { {a,b},0 };
	}

	int pos = -1, neg = 1e9;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++) {
			int cnt[2][2]; // cnt[i][j] : i그룹에 속한 j의 개수
			cnt[0][0] = cnt[0][1] = cnt[1][0] = cnt[1][1] = 0;
			for (int k = 0; k < N; k++) {
				if (k == i || k == j) continue;
				int group = ccw(arr[i].fr, arr[j].fr, arr[k].fr);
				cnt[group][arr[k].sc] += 1;
			}
			int p1 = arr[i].sc, p2 = arr[j].sc;

			//그룹0을 pos로 설정
			//p1이 그룹0에 속함
			if (cnt[0][0] + (p1 == 0) == 0) {
				if (neg > cnt[1][1] + (p2 == 1)) {
					neg = cnt[1][1] + (p2 == 1);
					pos = cnt[0][1] + (p1 == 1);
				}
			}
			//p2가 그룹0에 속함
			if (cnt[0][0] + (p2 == 0) == 0) {
				if (neg > cnt[1][1] + (p1 == 1)) {
					neg = cnt[1][1] + (p1 == 1);
					pos = cnt[0][1] + (p2 == 1);
				}
			}
			//p1, p2가 그룹0에 속함
			if (cnt[0][0] + (p1 == 0) + (p2 == 0) == 0) {
				if (neg > cnt[1][1]) {
					neg = cnt[1][1];
					pos = cnt[0][1] + (p1 == 1) + (p2 == 1);
				}
			}
			//그룹0에 아무 점도 속하지 않음
			if (cnt[0][0] == 0) {
				if (neg > cnt[1][1] + (p1 == 1) + (p2 == 1)) {
					neg = cnt[1][1] + (p1 == 1) + (p2 == 1);
					pos = cnt[0][1];
				}
			}

			//그룹1을 pos로 설정
			//p1이 그룹1에 속함
			if (cnt[1][0] + (p1 == 0) == 0) {
				if (neg > cnt[0][1] + (p2 == 1)) {
					neg = cnt[0][1] + (p2 == 1);
					pos = cnt[1][1] + (p1 == 1);
				}
			}

			//p2가 그룹1에 속함
			if (cnt[1][0] + (p2 == 0) == 0) {
				if (neg > cnt[0][1] + (p1 == 1)) {
					neg = cnt[0][1] + (p1 == 1);
					pos = cnt[1][1] + (p2 == 1);
				}
			}
			//p1, p2가 그룹1에 속함
			if (cnt[1][0] + (p1 == 0) + (p2 == 0) == 0) {
				if (neg > cnt[0][1]) {
					neg = cnt[0][1];
					pos = cnt[1][1] + (p1 == 1) + (p2 == 1);
				}
			}
			//그룹1에 아무 점도 속하지 않음
			if (cnt[1][0] == 0) {
				if (neg > cnt[0][1] + (p1 == 1) + (p2 == 1)) {
					neg = cnt[0][1] + (p1 == 1) + (p2 == 1);
					pos = cnt[1][1];
				}
			}
		}
	cout << pos << '\n';
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
