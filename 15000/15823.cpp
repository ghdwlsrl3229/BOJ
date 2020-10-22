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
int arr[110000];

int f2(int mid, int s) {
	unordered_set<int> st;
	for (int i = s, j = s; i < N; i++) {
		if (st.count(arr[i]) == 0) st.insert(arr[i]);
		else {
			while (st.size() && st.count(arr[i]) != 0) st.erase(arr[j++]);
			st.insert(arr[i]);
		}
		if (st.size() == mid) return i + 1;
	}
	return -1;
}

bool f(int mid) {
	int cnt = 0, pos = 0;
	while (pos < N) {
		pos = f2(mid, pos);
		if (pos != -1) cnt++;
		else break;

		if (cnt == M) return 1;
	}
	return 0;
}

void solve(int tc) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int lo = 1, hi = 1e5;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (f(mid)) lo = mid;
		else hi = mid - 1;
	}
	cout << lo << '\n';
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
