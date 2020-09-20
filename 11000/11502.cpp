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

vector<int> prime;

void solve() {
	int K; cin >> K;
	for (int i = 0; i < prime.size(); i++)
		for (int j = i; j < prime.size(); j++)
			for (int k = j; k < prime.size(); k++)
				if (prime[i] + prime[j] + prime[k] == K) {
					cout << prime[i] << ' ' << prime[j] << ' ' << prime[k] << '\n';
					return;
				}
	cout << 0 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i = 2; i <= 1000; i++) {
		int fact = 0;
		for (int j = 2; j < i; j++)
			if (i % j == 0) fact++;
		if (fact == 0) prime.push_back(i);
	}

	int t; cin >> t;
	while (t--) solve(); 
	return 0;
}
