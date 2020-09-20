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

void f(string& s, string& ladder) {
	for (int i = 0; i < ladder.size(); i++)
		if (ladder[i] == '-') swap(s[i], s[i + 1]);
}

void solve() {
	int k, n; cin >> k >> n;
	string s; cin >> s;
	string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string ladder[1100];
	for (int i = 0; i < n; i++) cin >> ladder[i];

	for (int i = 0; i < n; i++) {
		if (ladder[i][0] == '?') break;
		f(s2, ladder[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		if (ladder[i][0] == '?') break;
		f(s, ladder[i]);
	}

	string ans = "";
	for (int i = 0; i < k - 1; i++) {
		if (s[i] == s2[i]) ans += '*';
		else if (i + 1 < k && s[i] == s2[i + 1] && s[i + 1] == s2[i]) {
			swap(s[i], s[i + 1]);
			ans += '-';
		}
	}
	for (int i = 0; i < k - 2; i++) if (ans[i] == '-' && ans[i + 1] == '-') {
		for (int i = 0; i < k - 1; i++) cout << 'x';
		return;
	}
	if (s != s2.substr(0, k)) for (int i = 0; i < k - 1; i++) cout << 'x';
	else cout << ans << '\n';
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
