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
	int N; cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	
	ll cnt = 0;
	deque<int> dq;
	dq.push_back(v[0]);
	for (int i = 1; i < N; i++) {
		int idx = upper_bound(all(dq), v[i]) - dq.begin();
		cnt += idx;
		if (idx != dq.size()) cnt++;
		while (dq.size() && dq.front() < v[i]) dq.pop_front();
		dq.push_front(v[i]);
	}
	cout << cnt << '\n';

	return 0;
}
