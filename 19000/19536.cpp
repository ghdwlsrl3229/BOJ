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

int N, Q;
string s;
vector<ll> rocks;
vector<ll> leftmost;
vector<ll> rightmost;
ll psum[1100000];
ll psum2[1100000];

void query(int pos) {
	if (rocks.empty()) {
		int leftp = psum[pos + 1], rightp = psum[N] - psum[pos + 1];
		//1. 오른쪽 P가 더 많음 : (왼쪽 P수) . (왼쪽 P수 + 1), 방향 : <-
		//이동 거리 : 2 * (오른쪽 P 좌표합 - 왼쪽 P 좌표합) - pos + 1
		if (leftp < rightp) {
			ll lpsum = psum2[pos + 1], rpsum = psum2[leftmost[2 * leftp] + 1] - psum2[pos + 1];
			cout << 2 * leftp + 1 << ' ';
			cout << 2 * (rpsum - lpsum) - pos + 1 << '\n';
		}
		//2. 왼쪽 P가 같거나 많음 : (오른쪽 P수) . (오른쪽 P수), 방향 : ->
		//이동 거리 :  2 * (오른쪽 P 좌표합 - 왼쪽 P 좌표합) + N - pos
		else {
			int diff = leftp - rightp;
			ll lpsum = 0;
			if (diff < leftmost.size()) lpsum = psum2[pos + 1] - psum2[leftmost[diff]];
			ll rpsum = psum2[N] - psum2[pos + 1];
			cout << 2 * rightp << ' ';
			cout << 2 * (rpsum - lpsum) + N - pos << '\n';
		}
	}
	else if (pos < rocks[0]) {
		int leftp = psum[pos + 1], rightp = psum[rocks[0] + 1] - psum[pos + 1];
		// 1. 오른쪽 P가 더 많음 : (왼쪽 P수) . (왼쪽 P수 + 1)
		if (leftp < rightp) {
			ll lpsum = psum2[pos + 1], rpsum = psum2[leftmost[2 * leftp] + 1] - psum2[pos + 1];
			cout << 2 * leftp + 1 << ' ';
			cout << 2 * (rpsum - lpsum) - pos + 1 << '\n';
		}
		// 2. 왼쪽 P가 같거나 많음 : (왼쪽 P수) . (오른쪽 P수 + 나머지는 R)
		else {
			ll lpsum = psum2[pos + 1], rpsum = psum2[rocks[0] + 1] - psum2[pos + 1] + rocks[0] * (leftp + 1 - rightp);
			//cout << "!"<< lpsum << ' ' << rpsum << '\n';
			cout << leftp + rightp << ' ';
			cout << 2 * (rpsum - lpsum) - pos + 1 << '\n';
		}
	}
	else if (rocks.back() < pos) {
		int leftp = psum[pos + 1] - psum[rocks.back()], rightp = psum[N] - psum[pos + 1];
		// 1. 오른쪽 P가 더 많음 : (왼쪽 P수 + 나머지는 R) . (오른쪽 P수)
		if (leftp < rightp) {
			ll lpsum = psum2[pos + 1] - psum2[rocks.back()] + (rightp - leftp) * rocks.back(), rpsum = psum2[N] - psum2[pos + 1];
			cout << leftp + rightp << ' ';
			cout << 2 * (rpsum - lpsum) + N - pos << '\n';
		}
		// 2. 왼쪽 P가 같거나 많음 : (오른쪽 P수) . (오른쪽 P수)
		else {
			int diff = leftp - rightp;
			ll lpsum = 0;
			if (diff < rightmost.size()) lpsum = psum2[pos + 1] - psum2[rightmost[diff]];
			ll rpsum = psum2[N] - psum2[pos + 1];
			cout << 2 * rightp << ' ';
			cout << 2 * (rpsum - lpsum) + N - pos << '\n';
		}
	}
	else {
		int idx = lower_bound(all(rocks), pos) - rocks.begin();
		int cnt = psum[rocks[idx] + 1] - psum[rocks[idx - 1]];
		cout << cnt << ' ' << -1 << '\n';
	}
}

void solve(int tc) {
	cin >> N >> Q >> s;
	for (int i = 0; i < N; i++) if (s[i] == 'R') rocks.push_back(i);
	for (int i = 0; i < N; i++) {
		if (s[i] == 'P') leftmost.push_back(i);
		else if (s[i] == 'R') break;
	}
	for (int i = N - 1; i >= 0; i--) {
		if (s[i] == 'P') rightmost.push_back(i);
		else if (s[i] == 'R') break;
	}
	reverse(all(rightmost));

	for (int i = 0; i < N; i++) {
		if (s[i] == 'P') {
			psum[i + 1] = psum[i] + 1;
			psum2[i + 1] = psum2[i] + i;
		}
		else {
			psum[i + 1] = psum[i];
			psum2[i + 1] = psum2[i];
		}
	}

	for (int i = 0; i < Q; i++) {
		int q; cin >> q;
		query(q - 1);
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
