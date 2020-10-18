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

void solve() {
	string s; getline(cin, s);
	vector<int> v;
	while (1) {
		getline(cin, s);
		if (s == "고무오리 디버깅 끝") break;
		if (s == "문제") v.push_back(1);
		else {
			if (v.size()) v.pop_back();
			else {
				v.push_back(1);
				v.push_back(1);
			}
		}
	}
	if (v.empty()) cout << "고무오리야 사랑해";
	else cout << "힝구";
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
