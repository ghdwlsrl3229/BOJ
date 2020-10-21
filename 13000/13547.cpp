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

int N, Q;
int arr[110000];
int cnt[1100000];
int ans[110000];
int sqrtN;

struct query {
	int id, s, e;
	bool operator < (const query& a) {
		if (s / sqrtN != a.s / sqrtN) return s / sqrtN < a.s / sqrtN;
		return e < a.e;
	}
};

vector<query> v;

void solve(int tc) {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sqrtN = sqrt(N);

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		v.push_back({ i, a, b });
	}
	sort(all(v));

	int s = v[0].s, e = v[0].e, val = 0;
	for (int i = s; i <= e; i++) {
		if (cnt[arr[i]] == 0) val++;
		cnt[arr[i]]++;
	}
	ans[v[0].id] = val;

	for (int i = 1; i < Q; i++) {
		while (s < v[i].s) {
			cnt[arr[s]]--;
			if (cnt[arr[s]] == 0) val--;
			s++;
		}
		while (s > v[i].s) {
			--s;
			cnt[arr[s]]++;
			if (cnt[arr[s]] == 1) val++;
		}
		while (e < v[i].e) {
			++e;
			cnt[arr[e]]++;
			if (cnt[arr[e]] == 1) val++;
		}
		while (e > v[i].e) {
			cnt[arr[e]]--;
			if (cnt[arr[e]] == 0) val--;
			e--;
		}
		ans[v[i].id] = val;
	}

	for (int i = 0; i < Q; i++) cout << ans[i] << '\n';
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
