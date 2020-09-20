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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll M, N, L; cin >> M >> N >> L;
	vector<int> hunter(M);
	vector<pll> animal(N);
	for (int i = 0; i < M; i++) cin >> hunter[i];
	for (int i = 0; i < N; i++) cin >> animal[i].fr >> animal[i].sc;

	sort(all(hunter));

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int idx = lower_bound(all(hunter), animal[i].fr) - hunter.begin();
		bool poss = 0;
		for (int j = idx - 1; j <= idx + 1; j++) {
			if (j < 0 || j >= M) continue;
			ll dist = abs(animal[i].fr - hunter[j]) + animal[i].sc;
			if (dist <= L) poss = 1;
		}
		if (poss) cnt++;
	}
	cout << cnt << '\n';

	return 0;
}
