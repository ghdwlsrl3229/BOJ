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

const int MOD = 1e6 + 3;
const int SZ = 55;
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

matrix I, A;

matrix pow(matrix a, ll b) {
	if (b == 0) return I; //identity matrix
	if (b & 1) return a * pow(a, b - 1);
	matrix half = pow(a, b / 2);
	return half * half;
}

int N, S, E, T;

int arr[15][15];

void solve(int tc) {
	cin >> N >> S >> E >> T;
	S--, E--;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &arr[i][j]);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0) continue;
			for (int k = 0; k < arr[i][j] - 1; k++) 
				A.val[5 * i + k][5 * i + k + 1] = 1;
			A.val[5 * i + arr[i][j] - 1][5 * j] = 1;
		}

	for (int i = 0; i < 5*N; i++) I.val[i][i] = 1;
	matrix res = pow(A, T);
	cout << res.val[5*S][5*E] << '\n';
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	if (0) {
		int T; cin >> T;
		for (int i = 1; i <= T; i++) solve(i);
	}
	else {
		solve(0);
	}
	return 0;
}
