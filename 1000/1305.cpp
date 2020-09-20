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

int fail[1100000] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N; cin >> N;
	string s; cin >> s;

	for (int i = 1, j = 0; i < N; i++) {
		while (j > 0 && s[i] != s[j]) j = fail[j - 1];
		if (s[i] == s[j]) fail[i] = ++j;
	}

	cout << N - fail[N - 1] << '\n';
	return 0;
}
