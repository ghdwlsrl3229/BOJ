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

string s1, s2, s3;
vector<char> chv;
char mp[256];
bool used[10];

ll toint(string s) {
	ll ret = 0;
	for (int i = 0; i < s.size(); i++) {
		ret *= 10;
		ret += mp[s[i]];
	}
	return ret;
}

bool ans;
void dfs(int nd) {
	if (ans) return;
	if (nd == chv.size()) {
		if (toint(s1) + toint(s2) == toint(s3)) ans = 1;
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (!used[i]) {
			mp[chv[nd]] = i;
			used[i] = 1;
			dfs(nd + 1);
			used[i] = 0;
		}
	}
}

void solve(int tc) {
	cin >> s1 >> s2 >> s3;
	for (char ch : s1) chv.push_back(ch);
	for (char ch : s2) chv.push_back(ch);
	for (char ch : s3) chv.push_back(ch);
	sort(all(chv));
	chv.erase(unique(all(chv)), chv.end());
	dfs(0);
	cout << (ans ? "YES" : "NO") << '\n';
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
