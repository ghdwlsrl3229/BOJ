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

string N;
int M;
int cache[10000][110];

int toint(string s) {
	int ret = 0;
	for (int i = 0; i < s.size(); i++) {
		ret *= 10;
		ret += s[i] - '0';
	}
	return ret;
}

int dp(string n, int m) {
	if (m == M) {
		if (toint(n) > toint(N)) return 0; //승리
		else return 1;
	}
	
	int& ret = cache[toint(n)][m];
	if (ret != -1) return ret;

	if (m % 2 == 0) { //구사가 턴
		ret = 1;
		for (int i = 0; i < 4; i++) {
			string tmp = n;
			if (n[i] == '9') tmp[i] = '0';
			else tmp[i]++;
			if (dp(tmp, m + 1) == 0) ret = 0;
		}
	}
	else { //큐브러버 턴
		ret = 0;
		for (int i = 0; i < 4; i++) {
			string tmp = n;
			if (n[i] == '9') tmp[i] = '0';
			else tmp[i]++;
			if (dp(tmp, m + 1) == 1) ret = 1;
		}
	}
	
	return ret;
}

void solve(int tc) {
	cin >> N >> M;
	memset(cache, -1, sizeof(cache));

	int res = dp(N, 0);
	if (res) cout << "cubelover";
	else cout << "koosaga";
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
