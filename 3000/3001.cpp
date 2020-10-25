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

ll A, B, S;
string Astr, Bstr;

// as : 0(a보다 작음), 1(a와 같음), 2(a보다 큼)
// bs : as에서 a를 b로 바꿈
// s : 지금까지 각 자리의 합
// pos : 자리(가장 큰 자리부터 시작)
ll cache[20][3][3][140];
ll dp(int pos, int as, int bs, int s) {
	if (pos == -1) {
		if (s == S) {
			if (as == 0 || bs == 2) return 0;
			return 1;
		}
		else return 0;
	}

	ll& ret = cache[pos][as][bs][s];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i < 10; i++) {
		int next_as, next_bs;
		if (as == 1) {
			if (i == Astr[pos] - '0') next_as = 1;
			else if (i < Astr[pos] - '0') next_as = 0;
			else next_as = 2;
		}
		else next_as = as;
		if (bs == 1) {
			if (i == Bstr[pos] - '0') next_bs = 1;
			else if (i < Bstr[pos] - '0') next_bs = 0;
			else next_bs = 2;
		}
		else next_bs = bs;

		ret += dp(pos - 1, next_as, next_bs, s + i);
	}
	return ret;
}

string bt(int pos, int as, int bs, int s) {
	if (pos == -1) return "";

	for (int i = 0; i < 10; i++) {
		int next_as, next_bs;
		if (as == 1) {
			if (i == Astr[pos] - '0') next_as = 1;
			else if (i < Astr[pos] - '0') next_as = 0;
			else next_as = 2;
		}
		else next_as = as;
		if (bs == 1) {
			if (i == Bstr[pos] - '0') next_bs = 1;
			else if (i < Bstr[pos] - '0') next_bs = 0;
			else next_bs = 2;
		}
		else next_bs = bs;

		if (dp(pos - 1, next_as, next_bs, s + i)) {
			return char(i + '0') + bt(pos - 1, next_as, next_bs, s + i);
			
		};
	}
}

void solve(int tc) {
	cin >> A >> B >> S;
	Astr = to_string(A);
	Bstr = to_string(B);
	reverse(all(Astr));
	reverse(all(Bstr));
	while (Astr.size() != Bstr.size()) Astr += '0';

	memset(cache, -1, sizeof(cache));
	cout << dp(Bstr.size() - 1, 1, 1, 0) << '\n';
	
	string tmp = bt(Bstr.size() - 1, 1, 1, 0);
	string ans = "";
	int i = 0;
	while (i < tmp.size() && tmp[i] == '0') i++;
	for (; i < tmp.size(); i++) ans += tmp[i];
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
