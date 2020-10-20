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

int N, M;
int pa[1100000];
int find(int n) {
	if (pa[n] < 0) return n;
	return pa[n] = find(pa[n]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	pa[a] = b;
}

void solve(int tc) {
	cin >> N >> M;
	memset(pa, -1, sizeof(pa));
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		if (a < b) 
			for (int j = a - 1; j < b - 1; j++) {
				if (find(j) == find(j + 1) && find(j) != -1) j = find(j);
				if (j < b - 1) {
					merge(j, j + 1);
				}
			}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (pa[i] == -1) cnt++;
	}
	cout << cnt << '\n';
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
