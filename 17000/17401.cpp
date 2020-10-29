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

const int MOD = 1e9 + 7;
const int SZ = 50;
struct matrix {
	ll val[SZ][SZ];
	matrix() {
		for (int i = 0; i < SZ; i++)
			for (int j = 0; j < SZ; j++)
				val[i][j] = 0;
	}
};

matrix operator*(const matrix& a, const matrix& b) {
	matrix ret;
	for (int i = 0; i < SZ; i++)
		for (int j = 0; j < SZ; j++)
			for (int k = 0; k < SZ; k++) {
				ret.val[i][j] += a.val[i][k] * b.val[k][j];
				ret.val[i][j] %= MOD;
			}
	return ret;
}

matrix I;
matrix pow(matrix a, ll b) {
	if (b == 0) return I; //identity matrix
	if (b & 1) return a * pow(a, b - 1);
	matrix half = pow(a, b / 2);
	return half * half;
}

int T, N, D;
matrix A, arr[110];

void solve(int tc) {
	cin >> T >> N >> D;
	for (int i = 0; i < N; i++) I.val[i][i] = 1;
	for (int i = 0; i < T; i++) {
		int M; cin >> M;
		for (int j = 0; j < M; j++) {
			int a, b, c; cin >> a >> b >> c;
			arr[i].val[a - 1][b - 1] = c;
		}
	}

	A = arr[0];
	for (int i = 1; i < T; i++)
		A = A * arr[i];

	A = pow(A, D / T);
	for (int i = 0; i < D % T; i++)
		A = A * arr[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << A.val[i][j] << ' ';
		cout << '\n';
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
