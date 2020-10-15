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

ll ans;
string s;

void dnc(int le, int ri) {
	if ((ri - le + 1) % 2 == 0 || le == ri) return;

	int mid = (le + ri) / 2;
	//[le, mid - 1], [mid, ri]
	string ls, rs;
	for (int i = le; i <= mid - 1; i++) ls += s[i];
	for (int i = mid; i <= ri; i++) rs += s[i];

	//[le, mid], [mid + 1, ri]
	string ls2, rs2;
	for (int i = le; i <= mid; i++) ls2 += s[i];
	for (int i = mid + 1; i <= ri; i++) rs2 += s[i];

//	cout << ls << ' ' << rs << '\n';

	if (ls == rs.substr(0, rs.size() - 1)) { 
		ans++;
		dnc(mid, ri);
	}
	if (ls == rs.substr(1, rs.size())) {
		ans++;
		dnc(mid, ri);
	}
	if (rs2 == ls2.substr(0, ls2.size() - 1)) {
		ans++;
		dnc(le, mid);
	}
	if (rs2 == ls2.substr(1, ls2.size())) {
		ans++;
		dnc(le, mid);
	}
}

void solve(int tc) {
	cin >> s;
	dnc(0, s.size() - 1);
	cout << ans << '\n';
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
