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

const int MAX = 5500;
int A[MAX], B[MAX];
vector<int> adj[MAX];
bool visited[MAX];

int N;
char arr[110][110];
int row_num[110][110];
int col_num[110][110];

bool dfs(int a) {
	visited[a] = 1;
	for (int b : adj[a]) {
		if (B[b] == -1 || !visited[B[b]] && dfs(B[b])) {
			B[b] = a;
			A[a] = b;
			return 1;
		}
	}
	return 0;
}

void row_numbering(int y, int x, int n) {
	row_num[y][x] = n;
	if (x - 1 >= 0 && arr[y][x - 1] == '.' && row_num[y][x - 1] == 0)
		row_numbering(y, x - 1, n);
	if (x + 1 < N && arr[y][x + 1] == '.' && row_num[y][x + 1] == 0)
		row_numbering(y, x + 1, n);
}

void col_numbering(int y, int x, int n) {
	col_num[y][x] = n;
	adj[n].push_back(row_num[y][x]);
	if (y - 1 >= 0 && arr[y - 1][x] == '.' && col_num[y - 1][x] == 0)
		col_numbering(y - 1, x, n);
	if (y + 1 < N && arr[y + 1][x] == '.' && col_num[y + 1][x] == 0)
		col_numbering(y + 1, x, n);
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int cnt = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (row_num[i][j] == 0 && arr[i][j] == '.')
				row_numbering(i, j, cnt++);

	cnt = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (col_num[i][j] == 0 && arr[i][j] == '.')
				col_numbering(i, j, cnt++);

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++)
	//		cout << row_num[i][j] << ' ';
	//	cout << '\n';
	//}

	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	int ans = 0;
	for (int i = 1; i <= N * ((N + 1) / 2); i++) {
		if (A[i] == -1) {
			memset(visited, 0, sizeof(visited));
			if (dfs(i)) ans++;
		}
	}
	cout << ans << '\n';
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
