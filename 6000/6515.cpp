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
ll ans[110000];
int sqrtN;

int sum;
int cnt[110000]; 
int meta_cnt[110000];

struct query {
	int id, s, e;
	bool operator < (const query& a) {
		if (s / sqrtN != a.s / sqrtN) return s / sqrtN < a.s / sqrtN;
		return e < a.e;
	}
};

vector<query> v;

void Plus(ll x) {
	if (meta_cnt[cnt[x]]) meta_cnt[cnt[x]]--;
	cnt[x]++;
	meta_cnt[cnt[x]]++;
	sum = max(sum, cnt[x]);
}

void Minus(ll x) {
	meta_cnt[cnt[x]]--;
	if (cnt[x] == sum && meta_cnt[cnt[x]] == 0) sum--;
	cnt[x]--;
	meta_cnt[cnt[x]]++;
}

void solve(int tc) {
	while (1) {
		cin >> N;
		if (N == 0) break;
		cin >> Q;
		vector<int> tmp;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			tmp.push_back(arr[i]);
		}
		sqrtN = sqrt(N);
		sum = 0;

		sort(all(tmp));
		tmp.erase(unique(all(tmp)), tmp.end());

		for (int i = 0; i < N; i++) {
			arr[i] = lower_bound(all(tmp), arr[i]) - tmp.begin();
			cnt[i] = meta_cnt[i] = 0;
		}

		v.clear();
		for (int i = 0; i < Q; i++) {
			int a, b; cin >> a >> b;
			a--, b--;
			v.push_back({ i, a, b });
		}
		sort(all(v));

		int s = v[0].s, e = v[0].e;
		for (int i = s; i <= e; i++) Plus(arr[i]);
		ans[v[0].id] = sum;

		for (int i = 1; i < Q; i++) {
			while (s < v[i].s) Minus(arr[s++]);
			while (s > v[i].s) Plus(arr[--s]);
			while (e < v[i].e) Plus(arr[++e]);
			while (e > v[i].e) Minus(arr[e--]);
			ans[v[i].id] = sum;
		}

		for (int i = 0; i < Q; i++) cout << ans[i] << '\n';
	}
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
