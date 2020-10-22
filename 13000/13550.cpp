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

int N, Q, K;
int arr[110000];
ll psum[110000];
ll ans[110000];
int sqrtN;

int sum;
list<int> li[1100000];
int cnt[1100000];
int bucket[1100];

struct query {
	int id, s, e;
	bool operator < (const query& a) {
		if (s / sqrtN != a.s / sqrtN) return s / sqrtN < a.s / sqrtN;
		return e < a.e;
	}
};

vector<query> v;

void update(int x, int val) {
	cnt[x] += val;
	bucket[x / sqrtN] += val;
}

int sqrt_query() {
	int id = -1;
	for (int i = N / sqrtN; i >= 0; i--) if (bucket[i]) {
		id = i;
		break;
	}
	if (id == -1) return 0;
	for (int i = (id + 1) * sqrtN - 1; i >= id * sqrtN; i--)
		if (cnt[i]) return i;
	return 0;
}

void Plus(int idx) {
	list<int>& li2 = li[psum[idx]];
	if (li2.size() >= 2) update(li2.back() - li2.front(), -1);


	if (li2.size() && li2.front() > idx) li2.push_front(idx);
	else li2.push_back(idx);

	if (li2.size() >= 2) update(li2.back() - li2.front(), 1);
}

void Minus(int idx) {
	list<int>& li2 = li[psum[idx]];
	if (li2.size() >= 2) update(li2.back() - li2.front(), -1);

	if (li2.front() == idx) li2.pop_front();
	else li2.pop_back();

	if (li2.size() >= 2) update(li2.back() - li2.front(), 1);
}

void solve(int tc) {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++) psum[i + 1] = (psum[i] + arr[i]) % K;
	sqrtN = sqrt(N);
	sum = 0;

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a, b; cin >> a >> b;
		a--;
		v.push_back({ i, a, b });
	}
	sort(all(v));

	int s = v[0].s, e = v[0].e;
	for (int i = s; i <= e; i++) Plus(i);
	ans[v[0].id] = sqrt_query();

	for (int i = 1; i < Q; i++) { //범위가 증가하는 경우를 먼저 처리한다.
		while (s > v[i].s) Plus(--s);
		while (e < v[i].e) Plus(++e);
		while (s < v[i].s) Minus(s++);
		while (e > v[i].e) Minus(e--);
		ans[v[i].id] = sqrt_query();
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
