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

ll f(string s);
ll f2(string s);

map<string, ll> mp, mp2;

ll f(string s) { //s를 0000..로 만드는 비용
	if (s.size() == 1) return s[0] == '1';

	if (mp.find(s) != mp.end()) return mp[s];

	if (s[0] == '0') return mp[s] = f(s.substr(1, 31));
	else {
		string tmp = "1";
		for (int i = 0; i < s.size() - 2; i++) tmp += '0';
		return mp[s] = f2(s.substr(1, 31)) + 1 + f(tmp);
	}
}

ll f2(string s) { //s를 1000..로 만드는 비용 
	if (s.size() == 1) return s[0] == '0';

	if (mp2.find(s) != mp2.end()) return mp2[s];

	if (s[0] == '1') return mp2[s] = f(s.substr(1, 31));
	else {
		string tmp = "1";
		for (int i = 0; i < s.size() - 2; i++) tmp += '0';
		return mp2[s] = f2(s.substr(1, 31)) + 1 + f(tmp);
	}
}

void solve() {
	string s; cin >> s;
	mp.clear();
	mp2.clear();
	cout << f(s) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
