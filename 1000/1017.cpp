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

const int MAX = 55;

int A[MAX], B[MAX];
bool visited[MAX];
vector<int> adj[MAX];

bool dfs(int a) {
	if (a == 0) return 0;
	visited[a] = 1;
	for (int b : adj[a]) {
		if (B[b] == -1 || !visited[B[b]] && dfs(B[b])) {
			A[a] = b;
			B[b] = a;
			return 1;
		}
	}
	return 0;
}

bool isprime[2200];
void primechk() {
	for (int i = 2; i < 2200; i++) isprime[i] = true;
	for (long long i = 2; i < 2200; i++)
		if (isprime[i]) {
			for (long long j = i * i; j < 2200; j += i)
				isprime[j] = false;
		}
}

int N;
int arr[1100];

bool f(int b) {
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	A[0] = b;
	B[b] = 0;

	int cnt = 1;
	for (int i = 0; i < N; i++) {
		if (A[i] == -1 && arr[i] % 2 == arr[0] % 2) {
			memset(visited, 0, sizeof(visited));
			if (dfs(i)) cnt++;
		}
	}
	return cnt == N / 2;
}

void solve() {
	cin >> N;
	primechk();
	for (int i = 0; i < N; i++) cin >> arr[i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (arr[i] % 2 == arr[0] % 2 && arr[j] % 2 != arr[0] % 2
				&& isprime[arr[i] + arr[j]])
				adj[i].push_back(j);
		}

	vector<int> ans;
	for (int i : adj[0]) {
		if (arr[i] % 2 != arr[0] % 2 && f(i)) 
			ans.push_back(arr[i]);
	}
	sort(all(ans));
	if (ans.size()) for (int i : ans) cout << i << ' ';
	else cout << -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if (0) {
		int T; cin >> T;
		while (T--) solve();
	}
	else {
		solve();
	}
	return 0;
}
