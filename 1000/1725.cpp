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

int N;
int arr[110000];

int pa[110000];
int find(int n) {
	if (pa[n] < 0) return n;
	return pa[n] = find(pa[n]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	pa[b] += pa[a];
	pa[a] = b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	memset(pa, -1, sizeof(pa));

	vector<pll> v;
	for (int i = 0; i < N; i++) v.push_back({ arr[i], i });
	sort(all(v), greater<pll>());
	
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ll val = v[i].fr, idx = v[i].sc;
		if (idx != 0 && arr[idx - 1] >= val) merge(idx - 1, idx);
		if (idx != N - 1 && arr[idx + 1] >= val) merge(idx, idx + 1);

		ans = max(ans, val * -pa[find(idx)]);
	}
	cout << ans << '\n';
	return 0;
}
